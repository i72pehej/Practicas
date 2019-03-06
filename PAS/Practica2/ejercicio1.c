//Practica 2.
//Ejercicio resumen 1.


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <getopt.h>


int main(int argc, char *argv[]) {
	 // Declaracion de las estructuras que almacenaran la informarcion de un usuario y de un grupo.
    char *lgn;
    struct passwd *pw;
    struct group *gr;

    // En el caso de que no se ha introducido ningún nombre de usuario,
    // por defecto en lgn almacenara el usuario que ha ejecutado este programa

    if (argc < 2) {
      //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
      if ((lgn = getenv("USER") == NULL || (pw = getpwnam(lgn)) == NULL) {
        fprintf(stderr, "Obtención de información de usuario fallida.\n");
        exit(1);
      }
    }
    else {
      //Se indica el nombre de usuario en el primer argumento.
      lgn = argv[1];

      if ((pw = getpwnam(lgn)) == NULL) {
        //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO.
        fprintf(stderr, "Obtención de información de usuario fallida.\n");
        exit(1);
      }
    }

	//Aqui ya se dispone de la estructura que contiene informacion del usuario
	printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
	printf("Login: %s\n", pw->pw_name);
	printf("Password: %s\n", pw->pw_passwd);
	printf("UID: %d\n", pw->pw_uid);
	printf("Home: %s\n", pw->pw_dir);
	printf("Número de grupo principal: %d\n", pw->pw_gid);

	// Obtenemos la estructura de información del grupo a través del número de grupo al que pertenece el usuario
	gr = getgrgid(pw->pw_gid);

	//Se imprime el campo de la estructura que nos interesa
	printf("Nombre del grupo principal: %s\n", gr->gr_name);

	exit(0);

}

////////////////////////////////////////////////////////////////////////////////

int main (int argc, char **argv)
{
  int opciones;

	/* Estructura a utilizar por getoptlong */
	static struct option long_options[] = {
		/* Opciones que no van a actuar sobre un flag */
		/* "opcion", recibe o no un argumento, 0, identificador de la opción */

		{"username",	 no_argument,	   0, 'u'},
		{"useruid",  no_argument,	   0, 'i'},
		{"groupname",  required_argument, 0, 'd'},
		{"groupuid",  required_argument, 0, 'c'},
		{"file",	required_argument, 0, 'f'},
		/* Necesario para indicar el final de las opciones */
		{0, 0, 0, 0}
	};

	/* Estas variables servirán para almacenar el resultado de procesar la línea de comandos */
	int aflag = 0;
	int bflag = 0;
	char *cvalue = NULL;
	char *dvalue = NULL;
	char *fvalue = NULL;

	/* getopt_long guardará el índice de la opción en esta variable. */
	int option_index = 0;

	/* Deshabilitar la impresión de errores por defecto */
	/* opterr=0; */
	while ((c = getopt_long (argc, argv, "abc:d:f:", long_options, &option_index))!=-1)
	{
		/* El usuario ha terminado de introducir opciones */
		if (c == -1)
			break;
		switch (c)
		{
			case 'a':
				//printf("Opción -a\n");
				aflag=1;
				break;

			case 'b':
				//printf("Opción -b\n");
				bflag=1;
				break;

			case 'c':
				//printf("Opción -c con valor '%s'\n", optarg);
				cvalue = optarg;
				break;

			case 'd':
				//printf("Opción -d con valor '%s'\n", optarg);
				dvalue = optarg;
				break;

			case 'f':
				//printf("Opción -f con valor '%s'\n", optarg);
				fvalue = optarg;
				break;

			case '?':
				/* getopt_long ya imprime su mensaje de error, no es necesario hacer nada */
				/* Si queremos imprimir nuestros propios errores, debemos poner opterr=0,
				 y hacer algo como lo que se expone a continuacion. Pruebe a hacer sus propios errores.
				if (optopt == 'c')
					fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);*/
				break;

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
	printf ("aflag = %d, bflag = %d, cvalue = %s, dvalue = %s, fvalue = %s\n",aflag, bflag, cvalue, dvalue, fvalue);

	exit (0);
}
