#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h> //Control de errores
#include <string.h> //Para la funcion strerror(), que permite describir el valor de errno como cadena.

#define BSIZE 100

/***************************************************************************************************
Cuando la comunicación es simple y ambos extremos de la comunicación han sido generados
con un fork() o pertenecen al mismo proceso, se pueden utilizar tuberías anónimas (pipes).
**************************************************************************************************/


//Función para calcular si dos número son primos.
int primo(int numero) {
  int i;
  int contador = 0;

  if(numero == 1 || numero == 2)
    return 1;

  for(i = 1; i <= numero; i++) {
    if(numero % i == 0)
      contador++;
  }

  if(contador == 2)
    return 1;

  return 0;
}


int main() {

////////////////////////////////////////////////////////////////////////////////

	// Para realizar el fork.
	pid_t pid;
	int flag, status;

	// Para controlar los valores devueltos por las funciones (control de errores).
	int resultado1;
  int resultado2;

	// Lo que vamos a leer y escribir de la tubería.
  int numero1;
  int numero2;
  int primo1;
  int primo2;

  // Información obtenida entre PADRE e HIJO.
  char buf[BSIZE];
  char final_chance[BSIZE];
  ssize_t nbytes;
  char *comprobacion;

  // Delimitador para strtok() y string devuelto.
  const char lim[2] = ";";
  char *token;

	// Descriptores de las dos tuberías (fileDes[0] para LECTURA, fileDes[1] para ESCRITURA).
	int fileDes[2];  // Hacia el HIJO.
  int fileDes2[2]; // Hacia el PADRE.

	// Iterador.
	int i = 0;

////////////////////////////////////////////////////////////////////////////////

	// Creamos las tuberías.
	resultado1 = pipe(fileDes);
  resultado2 = pipe(fileDes2);

	if(resultado1 == -1 || resultado2 == -1) {
		printf("\nERROR al crear tubería.\n");
		exit(1);
	}

	pid = fork();
	switch (pid) {
    // ERROR.
		case -1:
			printf ("\nNo se ha podido crear el proceso hijo...\n");
			exit(EXIT_FAILURE);
    break;

    // HIJO. Lee desde la tubería.
    case 0:
      // No se va a escribir (fileDes[1]), cerramos esa puerta.
      if (close(fileDes[1]) == -1) {
        perror("\n[HIJO]: Error al cerrar el extremo de la tubería 1.\n");
        exit(EXIT_FAILURE);
      }
      else {printf("\n[HIJO]: Tubería 1 cerrada para escrituras.\n");}

      // Leer (fileDes[0]) usando READ. Es una llamada bloqueante.
      nbytes = read(fileDes[0], buf, BSIZE);
      if (nbytes < 0) {
        perror("\n[HIJO]: Error al leer de la tubería 1.\n");
        exit(EXIT_FAILURE);
      }
      // Si read() no ha leido nada -> Se llegaría a FEOF porque el padre habría cerrado la tuberia.
      else if (nbytes == 0) {
        printf("\n[HIJO]: Vaya, mi padre ha cerrado la tubería 1 ...\n");
      }
      else {printf("\n[HIJO]: Se ha leído %s de la tubería 1.\n", buf);}

      // Se termina de leer -> Cerramos fileDes[0].
      if (close(fileDes[0]) == -1) {
        perror("\n[HIJO]: Error al cerrar el extremo de la tubería 1.\n");
        exit(EXIT_FAILURE);
      }
      else {printf("\n[HIJO]: Tubería 1 cerrada.\n");}

////////////////////////////////////////////////////////////////////////////////

      // Tratamiento de valores leidos desde la tubería hacia el HIJO.
      token = strtok(buf, lim);
      numero1 = atoi(token);

      token = strtok(NULL, lim);
      numero2 = atoi(token);

      primo1 = primo(numero1);
      primo2 = primo(numero2);

      if((primo1 == 1) && (primo2 == 1)) {
        comprobacion = "primos";

        if((numero1 - numero2) == 2) {comprobacion = "gemelos";}
      }
      else {comprobacion = "no-primos";}

////////////////////////////////////////////////////////////////////////////////

      // Se escribe el resultado obtenido en la tubería hacia el PADRE.
      if(close(fileDes2[0]) == -1) {
        perror("\n[HIJO]: Error al cerrar el extremo de la tubería 2.\n");
        exit(EXIT_FAILURE);
      }

      if(write(fileDes2[1], comprobacion, BSIZE) == -1) {
        perror("\n[HIJO]: Error al escribir resultado en la tubería 2.\n");
        exit(EXIT_FAILURE);
      }
      else {printf("\n[HIJO]: Tubería 2 cerrada.\n");}

      exit(EXIT_SUCCESS);
    break;

////////////////////////////////////////////////////////////////////////////////

    // PADRE
		default:
      // Se piden los números para introducir en la tubería.
			printf ("\n[PADRE]: Introduzca un numero:\n");
      scanf("%d", &numero1);
      printf ("\n[PADRE]: Introduzca otro numero\n");
      scanf("%d", &numero2);

      // Se introducen los números separados por un ";".
      sprintf(buf, "%d;%d", numero1, numero2);

      // Se termina de escribir -> Cerramos fileDes[0].
      if (close(fileDes[0]) == -1) {
        perror("\n[PADRE]: Error al cerrar el extremo de la tubería 1.\n");
        exit(EXIT_FAILURE);
      }
      else {printf("\n[PADRE]: Tubería 1 cerrada.\n");}

			// Mandamos el mensaje.
			resultado1 = write(fileDes[1], buf, BSIZE);
			if(resultado1 != BSIZE) {
				perror("\n[PADRE]: ERROR al escribir en la tubería 1 ...\n");
				exit(EXIT_FAILURE);
			}

			// Cerrar la tubería que va hacia el HIJO.
      if (close(fileDes[1]) == -1) {
        perror("\n[PADRE]: Error al cerrar el extremo de la tubería 1.\n");
        exit(EXIT_FAILURE);
      }
      else {printf("\n[PADRE]: Tubería 1 cerrada.\n");}

      if (close(fileDes2[1]) == -1) {
        perror("\n[PADRE]: Error al cerrar el extremo de la tubería 2.\n");
        exit(EXIT_FAILURE);
      }
      else {printf("\n[PADRE]: Tubería 2 cerrada.\n");}

      // Leer usando READ. Es una llamada bloqueante.
      nbytes = read(fileDes2[0], final_chance, BSIZE);
      if (nbytes < 0){
        printf("\n[PADRE]: Error al leer desde tubería 2.\n");
      }
      else {
        printf("%s\n", final_chance );
      }

////////////////////////////////////////////////////////////////////////////////

			// Espera del PADRE a los HIJOS.
			while ((flag = wait(&status)) > 0) {
				if (WIFEXITED(status)) {
					printf("\n[PADRE]: Hijo con PID %ld finalizado, status = %d.\n", (long int)flag, WEXITSTATUS(status));
				}
        //Para señales como las de finalizar o matar.
				else if (WIFSIGNALED(status)) {
					printf("\n[PADRE]: Hijo con PID %ld finalizado al recibir la señal %d.\n", (long int)flag, WTERMSIG(status));
				}
			}

			if (flag == (pid_t)-1 && errno == ECHILD) {
				printf("[PADRE]: Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
			}
			else {
				printf("[PADRE]: Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
				exit(EXIT_FAILURE);
			}
    break;
  }

////////////////////////////////////////////////////////////////////////////////

  exit(EXIT_SUCCESS);
}
