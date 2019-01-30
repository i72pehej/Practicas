//Prácticando estructuras de procesos.


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include <pthread.h>


//Lineal/Secuencial.

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    int i, estado;
    pid_t pid;

    printf("\nFormato correcto.\n");

    for (i = 0; i < atoi(argv[1]); i++) {
      printf("\n");
      switch (fork()) {
        case -1:  //ERROR.
          printf("\nERROR. No se ha podido crear el nuevo proceso.\n");
          exit(EXIT_FAILURE);

        case 0:  //Proceso HIJO.
          printf("Creación del HIJO <%d>, con PADRE <%d>, correctamente.\n", getpid(), getppid());
          exit(EXIT_SUCCESS);

        break;

        default:  //Proceso PADRE.
          pid = wait(&estado);
          if(pid == -1) {exit(EXIT_FAILURE);}
          else {printf("Proceso HIJO <%d> terminó con estado: <%d>.\n", pid, WEXITSTATUS(estado));}
      }
    }

    printf("\n\n");
    printf("FIN. Ejecucuión terminada correctamente . . .\n\n");
    exit(EXIT_SUCCESS);
  }

  else {
    printf("\n¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ERROR. Formato de comando incorrecto!!!!!!!!!!!!!!!!!!\n");
    printf("\nTerminando ejecucuión . . .\n\n");
    sleep(2);
    exit(EXIT_FAILURE);
  }
}

/*
//Abanico.

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    int i, estado;
    pid_t pid;

    printf("\nFormato correcto.\n\n");

    for (i = 0; i < atoi(argv[1]); i++) {
      switch (fork()) {
        case -1:  //ERROR.
          printf("\nERROR. No se ha podido crear el proceso.\n");
          exit(EXIT_FAILURE);

        case 0:  //HIJO.
          printf("\nSe ha creado el HIJO <%d>, con PADRE <%d>, correctamente.\n", getpid(), getppid());
          exit(EXIT_SUCCESS);

        break;
      }
    }

    for(i = 0; i < atoi(argv[1]); i++) {
      pid = wait(&estado);
      if(pid == -1) {exit(EXIT_FAILURE);}
      else {printf("\nProceso HIJO <%d>, con PADRE <%d>, terminado con estado: <%d>.\n", getpid(), getppid(), WEXITSTATUS(estado));}
    }
  }

  else {
    printf("\n¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ERROR. Formato de comando incorrecto!!!!!!!!!!!!!!!!!!\n");
    printf("\nTerminando ejecucuión . . .\n\n");
    sleep(2);
    exit(EXIT_FAILURE);
  }

  printf("\n\n");
  printf("FIN. Ejecucuión terminada correctamente . . .\n\n");
  exit(EXIT_SUCCESS);
}
*/
