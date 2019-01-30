//tipo abanico

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char**argv)
{
  if(argc==2)
  {
    int i,pid_aux,estado;
    pid_t pid;

    for(i=0;  i<atoi(argv[1]);  i++)
    {
      pid=fork();

      switch(pid)
      {
        case -1:
        printf("ERROR en el fork\n");
        exit(EXIT_FAILURE);

        case 0:
        printf("Soy el hijo %lf y mi padre es %lf\n",(double)getpid(),(double)getppid());
        exit(EXIT_SUCCESS);
      }
    }
    while(pid_aux = wait(&estado) > 0)
    {
      if(pid_aux > 0)
      {
        if(WIFEXITED(estado))
        {
          printf("El hijo %d salio y su Status %d\n",pid_aux,WEXITSTATUS(estado));
        }
      }
    }
    exit(EXIT_SUCCESS);
  }

  else
  {
    printf("ERROR de argumentos\n");
    exit(EXIT_FAILURE);
  }
}
