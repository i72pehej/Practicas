#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <mqueue.h>
#include <regex.h>
#include <errno.h>
#include <getopt.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include "common.h"

#define QUEUE_NAME "/queue"


/* VARIABLES GLOBALES, LAS USA LA FUNCION finPrograma */

mqd_t queue = -1; //Inicializa la cola a -1
char queue_name[100]; //Inicializa el nombre de la cola a NULL

/* IMPORTANTE
NO DECLARARLO COMO char*, SALE VIOLACION DE SEGMENTO :*/


void finPrograma(int value); /* Cabecera de la función, esta se define al
final del código*/



/*Función manual, aparece si se invoca al programa de forma incorrecta o con
la opción -h*/
void imprimir_uso()
{
    printf("Uso del programa: ejercicio4-servidor [opciones]\n");
    printf("Opciones:\n");
    printf("-h, --help\t	Imprimir esta ayuda\n");
    printf("-r, --regex=EXPR\t	Expresión regular a utilizar\n");
}



int main(int argc, char** argv)
{
  int errnum = errno;
  /*---------------------------------------------------
                DECLARACIÓN DE VARIABLES
    ---------------------------------------------------*/


  //Estructura de las opciones del programa
  static struct option long_options[] =
	{
		/* Opciones que no van a actuar sobre un flag */
		/* "opcion", recibe o no un argumento, 0,
		   identificador de la opción */
		{"regex",  required_argument,	   0, 'r'},
		{"help",     no_argument,	   0, 'h'},
		/* Necesario para indicar el final de las opciones */
		{0, 0, 0, 0}
	};

  // flag que indica cuando hay que parar
	int must_stop = 0; // Cuando se introduce 'exit' en la cola, finaliza el programa

  /* Usados en las opciones -*/
  int c; // Usamos esta variable para movernos por las opciones
  int option_index; // Recoge el número de argc en el que estamos

  pid_t pid, pid_aux; // Usadas por los procesos
  int status;

  /* Variable de estructura usada en la cola*/
  struct mq_attr attr; //Atributos de la cola, usados en la creación

  /* La estructura struct mq_attr tiene los siguientes campos:

  struct mq_attr
  {
               long mq_flags;       //Flags: 0 or O_NONBLOCK
               long mq_maxmsg;      // Max. # of messages on queue
               long mq_msgsize;     // Max. message size (bytes)
               long mq_curmsgs;     // # of messages currently in queue
  };*/

  // Buffer para intercambiar mensajes entre procesos.
  char buffer[MAX_SIZE];

  /* Variables para la expresion regular */
  char* regexValue = NULL; //Variable que recoge el argumento de -r
  regex_t regex; /*Aquí alojaremos el valor de regexValue para cuando
  necesitemos hacer comparaciones*/
	int reti; //Usamos esta variable para control de errores, no es necesaria
  char msgbuf[100]; /* Copia de seguridad que utiliza el padre para
  guardar el mensaje que le manda el hijo, solo es por SEGURIDAD */


  /*---------------------------------------------------
              FIN DE DECLARACIÓN DE VARIABLES
    ---------------------------------------------------*/

  // Inicializar los atributos de la cola
  attr.mq_maxmsg = 10;        // Maximo número de mensajes
  attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje

  /*Se pone opterr = 0 para poder crear los mensajes personalizados de error con
  getopt_long()*/
  opterr = 0;

  /* Bucle while que cuenta con un switch case.
  Se usa para recoger el valor de la expresión regular.
  Es un copypaste del ejercicio 3*/
  while ((c = getopt_long (argc, argv, "hr:",long_options, &option_index))!=-1)
  {
    switch (c)
    {
      //CASO -h, IMPRIME EL MENU DE AYUDA
      case 'h':
        imprimir_uso();
        break;

      //CASO -r, GUARDA EN regexValue EL VALOR DEL ARGUMENTO
      case 'r':
        regexValue = optarg;
        break;

      //CASO ERROR EN LA LÍNEA DE ARGUMENTOS
      case '?':
        if (optopt == 'r')
          fprintf (stderr, "La opción -%c requiere un argumento.\n", optopt);

        else if (isprint (optopt))
          fprintf (stderr, "Opción desconocida `-%c'.\n", optopt);

        else
          fprintf (stderr, "Carácter de opción desconocido `\\x%x'.\n", optopt);

        imprimir_uso();

      //CASO EXCEPCIONAL
      default:
        exit(EXIT_SUCCESS);
    }
  }

  /*Control de error por si se invoca sin argumentos*/
  if(regexValue==NULL)
  {
     imprimir_uso();
     exit(EXIT_SUCCESS);
  }

  /* Compilar la expresión regular */
	reti = regcomp(&regex, regexValue, 0);
  if(reti!=0)
  {
		fprintf(stderr, "No pude compilar la expresión regular\n");
		exit(EXIT_FAILURE);
	}

  printf("Valor de regexvalue en servidor:%s\n",regexValue);

  /* Termina la recogida del valor de la expresión regular, en resumen,
  hemos usado el bucle y el switch case para guardar en regexValue el
  valor del argumento mandado (la expresión regular, que luego usaremos
  en la cola) y luego hemos hecho un control de error con regexValue == NULL
  para ver que se ha guardado correctamente o que realmente hemos usado el
  argumento necesario y finalmente hemos compilado la expresión regular y
  guardado en reti el valor de la compilación (el cual debia ser != para
  que todo hubiera ido bien), aquí hemos guardado la expresión en &regex
  y a partir de ahora usaremos esa variable cuando queramos referirnos a
  la expresión regular*/

  /*A partir de aquí establecemos el nombre de la cola, creamos el proceso
  hijo y hacemos lo que nos pide el ejercicio*/

  /* ESTA LINEA ES MUY IMPORTANTE QUE VAYA ANTES DEL FORK, SINO, NO TE VA A SERVIR*/
  sprintf(queue_name, "%s-%s", QUEUE_NAME, getenv("USER"));

  pid = fork();

  switch(pid)
  {
    //CASO ERROR
    case -1:
      perror("ERROR en la creación del proceso hijo...\n\n");
      exit(EXIT_FAILURE);

    //CASO HIJO
    case 0:

      queue = mq_open(queue_name, O_RDWR);

      do
      {
        /* Todo lo siguiente es en su mayoría copypaste, reutilizar en el examen*/

        printf("> ");

    		/* Puede servirnos por si al hacer pruebas hemos cerrado nuestro cliente y servidor
    		y se han quedado caracteres en los bufferes de entrada/salida estandar*/

    		fflush(stdout);                  // Limpiar buffer de salida
    		memset(buffer, 0, MAX_SIZE);     // Poner a 0 el buffer

        /* Se usa el fgets para leer por teclado, funciona asi:
        Registra en la cadena buffer, con un máximo tamaño de MAX_SIZE mediante
        stdin (lectura de teclado), la función lee hasta llegados a n-1 caracteres,
        es decir, lee hasta ññegados a 1023 (definido en common.h) y usa el último
        caracter para introducir un /0
        */
    		fgets(buffer, MAX_SIZE, stdin);

    		/* ESTO ESTABA EN EL EJERCICIO RESUELTO 3, USAR SI ES NECESARIO
        //Descartar el \n del final
    		if(buffer[strlen(buffer)-1] == '\n')
    			buffer[strlen(buffer)-1] = '\0';
    		*/

    		// Enviar y comprobar si el mensaje se manda
        if(mq_send(queue, buffer, MAX_SIZE, 0) != 0)
    		{
    			perror("[HIJO]: Error al enviar el mensaje");
          fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));

          /*El ejercicio da fallo pero el codigo está bien, lo más seguro es
          que el ejercicio no se pueda hacer o que haya que añadir algo
          que no sé que es.
          Puedes reutilizar todas las partes porque todo funciona perfectamente,
          si te da fallo en el examen usa la variable errnum*/

    			exit(EXIT_FAILURE);
    		}

        /* Se usa la función strncmp para comprobar si se ha introducido un exit*/
    		if(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
    			must_stop=1;

        else
      	{
      		// Número de bytes leidos, se declara como ssize_t para poder meter un -1
      		ssize_t bytes_read;

      	  // Recibir el mensaje
      		bytes_read = mq_receive(queue, buffer, MAX_SIZE, NULL);

      		// Comprar que la recepción es correcto (bytes leidos no son negativos)
      		if(bytes_read < 0)
      		{
      			perror("[HIJO]: Error al recibir el mensaje");
      			exit(EXIT_FAILURE);
      		}

          /* ESTO ESTABA EN EL CODIGO DEL EJERCICIO 3 RESUELTO, USAR SI ES NECESARIO
      		// Cerrar la cadena.
      		//buffer[bytes_read] = '\0';
          */

      		printf("[HIJO]: Recibido el mensaje: %s\n", buffer);

      		//Si recibo un exit del servidor es que ha habido fallo en el marching.
      		if(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
      			must_stop=1;
      	}

      // Iterar hasta escribir el código de salida
      }while (!must_stop);

      exit(EXIT_SUCCESS);

    //CASO PADRE
    default:

      /* Usamos la funciçon sprintf, esta funciona de la siguiente forma:
      En la variable (char*) queue_name, vamos a meter la concatenación de
      "%s"-"%s", cuyos valores se encuentran en QUEUE_NAME y en getenv("USER")

      La función getenv("USER") nos devuelve el usuario de la máquina, es
      importante llamar a la cola con el nombre de usuario para impedir
      que nadie más sepa el nombre de la cola y por tanto no use nuestra
      cola*/

      /* Creación de la cola y control de error.
      Apertura de la cola:
      - O_CREAT: si no existe, se crea
      - O_RDWR: lectura/escritura
      - O_RDONLY: solo lectura
      - O_WRONLY: solo escritura
      - 0644: permisos rw-r--r--
      - attr: estructura con atributos para la cola
      */

      queue = mq_open(queue_name, O_CREAT | O_RDWR, 0644, &attr);

      if(queue == (mqd_t)-1)
    	{
        perror("[PADRE]: Error al abrir la cola del servidor");
       	exit(EXIT_FAILURE);
    	}

      do
      {

        // Número de bytes leidos, usa ssize_t para almacenar números negativos
  		  ssize_t bytes_read;

  		  /* Recibir el mensaje, esta función es bloqueante, es decir, espera
        hasta que el hijo le mande un mensaje y luego empieza a ejecutarse */
  		  bytes_read = mq_receive(queue, buffer, MAX_SIZE, NULL);

  		  // Comprar que la recepción es correcto (bytes leidos no son negativos)
  		  if(bytes_read < 0)
  		  {
  			  perror("[PADRE]: Error al recibir el mensaje");
  			  exit(EXIT_FAILURE);
  		  }

        /* ESTO ESTABA EN EL CÓDIGO DEL EJERCICIO RESUELTO 3, USAR SI ES
        NECESARIO
  		  // Cerrar la cadena
  		  //buffer[bytes_read] = '\0';
        */

        /* El padre deja esta parte del código bloqueada hasta que reciba un
        mensaje del hijo*/

        // Comprobar el fin del bucle si se lee exit
  		  if (strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
  			 must_stop = 1;

        else
        {
          printf("[PADRE]: Recibido el mensaje: %s\n", buffer);

          /* Comprobar la expresión regular sobre la cadena pasada como argumento,
          se utiliza el regex ya que en realidad la función regexec utiliza
          una variable de tipo regex_t.
          Esta función comprueba si la cadena regex se encuentra en la cadena
          (la cual es más grande) buffer, los demás parámetros úsalos igualmente.
          */
          reti = regexec(&regex, buffer, 0, NULL, 0);

          //Hago una copia por si hay error de matching mostralo.
          sprintf(msgbuf,"%s", buffer);

          // Puede servirnos, UNA VEZ COMPROBADA LA EXPRESION, por si al hacer pruebas hemos cerrado nuestro
          // cliente y servidor, y se han quedado caracteres en los bufferes de entrada/salida estandar
          fflush(stdout);                  // Limpiar buffer de salida
          memset(buffer, 0, MAX_SIZE);     // Poner a 0 el buffer

          /* Usamos reti para ver si empareja o no empareja */
          if(reti==0)
            strcpy(buffer,"Empareja");

          else if(reti==REG_NOMATCH) //REG_NOMATCH indica que NO se ha encontrado.
            strcpy(buffer,"No Empareja");

          /* Control de errores por si la función regexec devuelve algo
          inesperado */
          else
          {
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            fprintf(stderr, "[PADRE]: Falló el matching de la expresión regular: %s\n", msgbuf);

            //Finalizar el programa si falla el matching (exit). Se lo enviamos al cliente
            //sprintf(buffer,"%s",MSG_STOP);
            strcpy(buffer,MSG_STOP);
          }

          // Enviar y comprobar si el mensaje se manda
  			  if(mq_send(queue, buffer, MAX_SIZE, 0) != 0)
  			  {
  				  perror("[PADRE]: Error al enviar el mensaje");
  				  exit(-1);
  			  }
  		  }
  	}while (!must_stop); // Iterar hasta que llegue el código de salida 'exit'

    //Espera a que termine

    /*Todo el código que sigue de aquí hasta el final del programa es código
    copiado del profesor, úsalo en el examen*/
    while ( (pid_aux=wait(&status)) > 0 )
    {
      if (WIFEXITED(status))
      {
        printf("Proceso Padre, Hijo con PID %ld finalizado, status = %d\n", (long int)pid_aux, WEXITSTATUS(status));
      }
      else if (WIFSIGNALED(status))
      {  //Para seniales como las de finalizar o matar
        printf("Proceso Padre, Hijo con PID %ld finalizado al recibir la señal %d\n", (long int)pid_aux, WTERMSIG(status));
      }
      else if (WIFSTOPPED(status))
      { //Para cuando se para un proceso. Al usar wait() en vez de waitpid() no nos sirve.
        printf("Proceso Padre, Hijo con PID %ld parado al recibir la señal %d\n", (long int)pid_aux,WSTOPSIG(status));
      }
      else if (WIFCONTINUED(status))
      { //Para cuando se reanuda un proceso parado. Al usar wait() en vez de waitpid() no nos sirve.
        printf("Proceso Padre, Hijo con PID %ld reanudado\n",(long int) pid_aux);
      }
    }

    if (pid_aux==(pid_t)-1 && errno==ECHILD)
    {
      printf("Proceso Padre, valor de errno = %d, definido como %s, no hay más hijos que esperar!\n", errno, strerror(errno));
    }
    else
    {
      printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
      exit(EXIT_FAILURE);
    }

    // Cerrar el programa
    finPrograma(-1);

    /* Liberar la expresión regular utilizada */
    regfree(&regex);

    exit(EXIT_SUCCESS);
  }
}


/* Esta función es un copypaste, estaba en el ejercicio resuelto 3.
Básicamente envía un exit por si no se había enviado de antes y luego
cierra y elimina las colas, úsalo al acabar el programa */

void finPrograma(int value)
{
   char msgbuf[100];

	if(queue!=-1)
	{
		// Buffer para intercambiar mensajes
		char buffer[MAX_SIZE];

		//Finalizar el programa si falla el matching (exit). Se lo enviamos al cliente
		//sprintf(buffer,"%s",MSG_STOP);
		strcpy(buffer,MSG_STOP);

		// Enviar y comprobar si el mensaje se manda
		if(mq_send(queue, buffer, MAX_SIZE, 0) != 0)
		{
			perror("Error al enviar el mensaje");
			exit(EXIT_FAILURE);
		}

		// Cerrar la cola del servidor
		if(mq_close(queue) == (mqd_t)-1)
		{
			perror("Error al cerrar la cola del cliente");
			exit(EXIT_FAILURE);
		}
		// Eliminar la cola del cliente
		if(mq_unlink(queue_name) == (mqd_t)-1)
		{
			perror("Error al eliminar la cola del cliente");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}
