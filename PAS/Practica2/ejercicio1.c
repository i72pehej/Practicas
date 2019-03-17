/*Ejercicio 1:
Implemente un programa que obtenga e imprima información sobre usuarios del sistema
(todos los campos de la estructura passwd) e información sobre grupos del sistema (GID y
nombre del grupo mediante la estructura group), según las opciones recibidas por la línea de
argumentos.
*/

/*Ejermplos de ejecución.
./a.out
./a.out -d hola
./a.out --delete
./a.out -k
*/


#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>


int main (int argc, char **argv) {
	int opcion;

	/* Estructura a utilizar por getoptlong */
	static struct option long_options[] = {
		/* Opciones que no van a actuar sobre un flag */
		/* "opcion", recibe o no un argumento, 0, identificador de la opción */
		{"username",  required_argument, 0, 'u'},
		{"useruid",   required_argument, 0, 'i'},
		{"groupname", required_argument, 0, 'g'},
		{"groupuid",  required_argument, 0, 'd'},
		{"allgroups", required_argument, 0, 's'},
		/* Necesario para indicar el final de las opciones */
		{0, 0, 0, 0}
	};

	/* Estas variables servirán para almacenar el resultado de procesar la línea de comandos */
	char *u_value = NULL;
	char *i_value = NULL;
	char *g_value = NULL;
	char *d_value = NULL;
	char *s_value = NULL;

	/* getopt_long guardará el índice de la opción en esta variable. */
	int option_index = 0;

	/* Deshabilitar la impresión de errores por defecto */
	/* opterr=0; */
	while ((opcion = getopt_long(argc, argv, "u:i:g:d:s:", long_options, &option_index)) != -1) {
		/*El usuario ha terminado de introducir opciones.*/
		if (opcion == -1) {break;}

		switch (opcion) {
			case 'u':
				printf("\nOpción -u con valor '%s'\n", optarg);
				u_value = optarg;
				break;

			case 'i':
				printf("\nOpción -i con valor '%s'\n", optarg);
				i_value = optarg;
				break;

			case 'g':
				printf("\nOpción -g con valor '%s'\n", optarg);
				g_value = optarg;
				break;

			case 'd':
				printf("\nOpción -d con valor '%s'\n", optarg);
				d_value = optarg;
				break;

			case 's':
				printf("\nOpción -s con valor '%s'\n", optarg);
				s_value = optarg;
				break;

			case '?':
				/* getopt_long ya imprime su mensaje de error, no es necesario hacer nada.*/
				/* Si queremos imprimir nuestros propios errores, debemos poner opterr = 0.*/
				/*
				if (optopt == 'c')
					fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);
				break;
				*/

			default:
				abort ();
		}
		printf("optind: %d, optarg: %s, optopt: %c\n", optind, optarg, optopt);
	}

	/* Imprimir el resto de argumentos de la línea de comandos que no son opciones con "-" */
	if (optind < argc)
	{
		printf("Argumentos ARGV que no son opciones: ");
		while (optind < argc)
			printf("%s ", argv[optind++]);
		putchar ('\n');
	}
	printf ("\nu_value = %s, i_value = %s, g_value = %s, d_value = %s, s_value = %s.\n",u_value, i_value, g_value, d_value, s_value);

	exit (0);
}
