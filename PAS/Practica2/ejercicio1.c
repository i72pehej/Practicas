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
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>


int main (int argc, char **argv) {
	int opcion;

	char *lgn;
	struct passwd *pw;
	struct group *gr;

	FILE *f_grupo;
	char *info_grupo;

	/* Estructura a utilizar por getoptlong */
	static struct option long_options[] = {
		/* Opciones que no van a actuar sobre un flag */
		/* "opcion", recibe o no un argumento, 0, identificador de la opción */
		{"username",  required_argument, 0, 'u'},
		{"useruid",   required_argument, 0, 'i'},
		{"groupname", required_argument, 0, 'g'},
		{"groupuid",  required_argument, 0, 'd'},
		{"allgroups", no_argument,			 0, 's'},
		/* Necesario para indicar el final de las opciones */
		{0, 0, 0, 0}
	};

	/* Estas variables servirán para almacenar el resultado de procesar la línea de comandos */
	char *u_value = NULL;	//Nombre de usuario del sistema.
	char *i_value = NULL;	//Identificador de usuario del sistema.
	char *g_value = NULL;	//Nombre de un grupo del sistema.
	char *d_value = NULL;	//Identificador de un grupo del sistema.
	int 	s_value = 0;	//Información de todos los grupos.

	/* getopt_long guardará el índice de la opción en esta variable. */
	int option_index = 0;

	/* Deshabilitar la impresión de errores por defecto */
	opterr = 0;

	while ((opcion = getopt_long(argc, argv, "u:i:g:d:s", long_options, &option_index)) != -1) {
		/*El usuario ha terminado de introducir opciones.*/
		if (opcion == -1) {break;}

		switch (opcion) {
			// Muestra la información de "passwd" de un usuario mediante su nombre de usuario.
			case 'u':
				printf("\nOpción -u con valor '%s'\n", optarg);
				u_value = optarg;

				if ((lgn = u_value /*getenv("USER")*/) == NULL || (pw = getpwnam(lgn)) == NULL) {
          fprintf(stderr, "\nError al obtener información de usuario.\n");
          exit(1);
        }

				//Aqui ya se dispone de la estructura que contiene informacion del usuario.
				printf("\n");
				printf("\tNombre de Usuario: %s\n", 		pw->pw_gecos);
				printf("\tLogin: %s\n", 								pw->pw_name);
				printf("\tPassword: %s\n", 							pw->pw_passwd);
				printf("\tUID: %d\n", 									pw->pw_uid);
				printf("\tDirectorio HOME: %s\n", 			pw->pw_dir);
				printf("\tID de grupo principal: %d\n", pw->pw_gid);
				printf("\n");

			break;

			// Muestra la información de "passwd" de un usuario mediante su ID de usuario.
			case 'i':
				printf("\nOpción -i con valor '%s'\n", optarg);
				i_value = optarg;

				if ((lgn = i_value /*getenv("USER")*/) == NULL || (pw = getpwuid(atoi(lgn))) == NULL) {
          fprintf(stderr, "\nError al obtener información de usuario.\n");
          exit(1);
        }

				//Aqui ya se dispone de la estructura que contiene informacion del usuario.
				printf("\n");
				printf("\tNombre de Usuario: %s\n", 		pw->pw_gecos);
				printf("\tLogin: %s\n", 								pw->pw_name);
				printf("\tPassword: %s\n", 							pw->pw_passwd);
				printf("\tUID: %d\n", 									pw->pw_uid);
				printf("\tDirectorio HOME: %s\n", 			pw->pw_dir);
				printf("\tID de grupo principal: %d\n", pw->pw_gid);
				printf("\n");

			break;

			// Muestra el GID de "group" de un grupo mediante su nombre de grupo.
			case 'g':
				printf("\nOpción -g con valor '%s'\n", optarg);
				g_value = optarg;

				if ((lgn = g_value /*getenv("USER")*/) == NULL || (gr = getgrnam(lgn)) == NULL) {
          fprintf(stderr, "\nError al obtener información del grupo.\n");
          exit(1);
        }

				printf("\n");
			 	// printf("\tNombre del grupo principal: %s\n", gr->gr_name);
				printf("\tID del grupo principal: %d\n", 		 gr->gr_gid);
				printf("\n");

			break;

			// Muestra el nombre de "group" de un grupo mediante su GID de grupo.
			case 'd':
				printf("\nOpción -d con valor '%s'\n", optarg);
				d_value = optarg;

				if ((lgn = d_value /*getenv("USER")*/) == NULL || (gr = getgrgid(atoi(lgn))) == NULL) {
          fprintf(stderr, "\nError al obtener información del grupo.\n");
          exit(1);
        }

				printf("\n");
				printf("\tNombre del grupo principal: %s\n", gr->gr_name);
				// printf("\tID del grupo principal: %s\n", 		 gr->gr_gid);
				printf("\n");

			break;

			// Muestra la información de todos los grupos del sistema.
			case 's':
				s_value = 1;

				//Apertura del fichero de información de grupos: "/etc/group".
				if(f_grupo = fopen("group", "r")) {
					printf("ERROR. Imposible abrir fichero.\n");
					exit(1);
				}
				else {printf("El fichero se abrió correctamente.\n");}

				printf("\n");
				while (fgets(info_grupo, 30, f_grupo) != NULL) {
					printf("Información de grupo: %s\n", info_grupo);
				}
				printf("\n");

				fclose(f_grupo);
			break;

			case '?':
				/* getopt_long ya imprime su mensaje de error, no es necesario hacer nada.*/
				/* Si queremos imprimir nuestros propios errores, debemos poner opterr = 0.*/
				// /*
				if (optopt == 'u') {fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);}
				if (optopt == 'i') {fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);}
				if (optopt == 'g') {fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);}
				if (optopt == 'd') {fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);}
				if (optopt == 's') {fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);}

			break;
				// */

			default:
				printf("\n\nERROR FATAL.\n\n");
				printf("\n\nAbortando . . .\n\n");
				abort ();
		}
		printf("optind: %d, optarg: %s, optopt: %c\n", optind, optarg, optopt);
	}

	/* Imprimir el resto de argumentos de la línea de comandos que no son opciones con "-" */
	if (optind < argc) {
		printf("\nArgumentos ARGV que no son opciones: ");
		while (optind < argc)
			printf("%s ", argv[optind++]);
		putchar ('\n');
	}

	printf ("\nu_value = %s, i_value = %s, g_value = %s, d_value = %s, s_value = %d.\n",u_value, i_value, g_value, d_value, s_value);

	exit (0);
}
