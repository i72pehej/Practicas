//tipo abanico

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  if(argc == 2) {
    int i, estado;
    pid_t pid;

    printf("\nFormato correcto.\n\n");
    for(i = 0; i < atoi(argv[1]); i++) {
      switch(fork()) {
        case -1:
          printf("\nERROR. No se ha podido crear el proceso.\n");
          exit(EXIT_FAILURE);

        case 0:
          printf("Proceso HIJO <%lf>, con PADRE <%lf>, creado correctamente.\n", (double)getpid(), (double)getppid());
          exit(EXIT_SUCCESS);
      }
    }

    sleep(1);
    printf("\n");
    while((pid = wait(&estado)) > 0) {
      if(WIFEXITED(estado)) {printf("Proceso HIJO <%d> terminado con estado: <%d>.\n", pid, WEXITSTATUS(estado));}
    }

    printf("\nEjecucuión terminada con éxito.\n\n");
    exit(EXIT_SUCCESS);
  }

  else {printf("\n\nERROR. Formato de argumentos incorrecto.\n\n"); exit(EXIT_FAILURE);}
}
