#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <signal.h>
#include "common.h"

// Apuntador al fichero de log (se utilizará en el ejercicio resumen)
FILE *fLog = NULL;

// Cola del servidor
mqd_t mq_server = -1;

// Cola del cliente
mqd_t mq_client = -1;

// Nombre para las colas
char clientQueue[100];
char serverQueue[100];

// Función que procesará EL FINAL
void finPrograma(int value);

int main(int argc, char **argv)
{

	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE];

	// Buffer para mensajes
   char msgbuf[100];

	// Nombre para las colas. Al concatenar el login seran unicas en el sistema.
	sprintf(clientQueue, "%s-%s", CLIENT_QUEUE, getenv("USER"));
	sprintf(serverQueue, "%s-%s", SERVER_QUEUE, getenv("USER"));

	// Abrir la cola del servidor
	mq_server = mq_open(serverQueue, O_WRONLY);
	if( mq_server == (mqd_t)-1)
	{
     	perror("Error al abrir la cola del servidor");
      exit(EXIT_FAILURE);
	}

	// Abrir la cola del cliente
	mq_client = mq_open(clientQueue, O_RDONLY);
	if( mq_client == (mqd_t)-1)
	{
    	perror("Error al abrir la cola del cliente");
   	exit(EXIT_FAILURE);
	}

	// flag que indica cuando hay que parar
	int must_stop = 0;
	printf("Mandando mensajes al servidor (escribir \"%s\" para parar):\n", MSG_STOP);

	do 
	{
		printf("> ");

		// Puede servirnos por si al hacer pruebas hemos cerrado nuestro cliente y servidor
		// y se han quedado caracteres en los bufferes de entrada/salida estandar
		fflush(stdout);                  // Limpiar buffer de salida
		memset(buffer, 0, MAX_SIZE);     // Poner a 0 el buffer

		/* Leer por teclado. Según la documentación, fgets lo hace de esta manera:
		It stops when either (n-1) characters are read, the newline character is read,
		or the end-of-file is reached, whichever comes first. 
		Automáticamente fgets inserta el fin de cadena '\0'
		*/
		fgets(buffer, MAX_SIZE, stdin);

		/* //Descartar el \n del final
		if(buffer[strlen(buffer)-1] == '\n') 
			buffer[strlen(buffer)-1] = '\0';
		*/
		
		// Enviar y comprobar si el mensaje se manda
		if(mq_send(mq_server, buffer, MAX_SIZE, 0) != 0)
		{
			perror("Error al enviar el mensaje");
			exit(EXIT_FAILURE);
		}
	
		if(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
			must_stop=1;
		else
		{
			// Número de bytes leidos
			ssize_t bytes_read;
			// Recibir el mensaje
			bytes_read = mq_receive(mq_client, buffer, MAX_SIZE, NULL);
			// Comprar que la recepción es correcto (bytes leidos no son negativos)
			if(bytes_read < 0)
			{
				perror("Error al recibir el mensaje");
				exit(EXIT_FAILURE);
			}
			
			// Cerrar la cadena
			//buffer[bytes_read] = '\0'; 
			 
			printf("Recibido el mensaje: %s\n", buffer);
			//Si recibo un exit del servidor es que ha habido fallo en el marching.
			if(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
				must_stop=1;
		}
		// Iterar hasta escribir el código de salida
	}while (!must_stop);

	finPrograma(-1);
	exit(EXIT_SUCCESS);
}




void finPrograma(int value)
{
   char msgbuf[100];

	if(mq_client!=-1)
	{
		// Cerrar la cola del servidor
		if(mq_close(mq_client) == (mqd_t)-1)
		{
			perror("Error al cerrar la cola del cliente");
			exit(EXIT_FAILURE);
		}
	}
	
	if(mq_server!=-1)
	{
		// Buffer para intercambiar mensajes
		char buffer[MAX_SIZE];
		
		//Finalizar el programa (exit). Se lo enviamos al servidor
		//sprintf(buffer,"%s",MSG_STOP);
		strcpy(buffer,MSG_STOP);
		
		// Enviar y comprobar si el mensaje se manda
		if(mq_send(mq_server, buffer, MAX_SIZE, 0) != 0)
		{
			perror("Error al enviar el mensaje");
			exit(EXIT_FAILURE);
		}

		// Cerrar la cola del servidor
		if(mq_close(mq_server) == (mqd_t)-1)
		{
			perror("Error al cerrar la cola del servidor");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}
