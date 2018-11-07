// Práctica 1 - Sistemas Operativos.
// Ejercicio propuesto 1.

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

#define ITER	5
#define CHILDREN	3

// The process finished correctly
#define Ok	88

// Pide dos valores (índice de vector y su valor), repetido 10 veces.
void procesoHijo1(int *v){
  int pos, valor;

  for (size_t x = 0; x < 10; x++) {
    printf("Introduzca la posición del vector.\n");
    fscanf(stdin, "%d", &pos);
    printf("Introduzca el valor para asignar a la posición.\n");
    fscanf(stdin, "%d", &valor);

    v[pos] = valor;
  }

exit(Ok);
}

void procesoHijo2(int *v){
  for (size_t i = 0; i < 100; i++) {
    v[rand() % 100] = rand();
  }
  sleep(1);

exit(Ok);
}

void procesoHijo3(int *v){
  int suma = 0;

  for (size_t i = 0; i < ITER; i++) {
    for (size_t j = 0; j < 100; j++) {
      suma += v[j];
    }
  }
  printf("La suma de los elementos del vector es: <%d>.\n", suma);
  sleep(30);

exit(Ok);
}

int main()
{
    int i, shmid, status;
    key_t key;
    int *v;
    struct shmid_ds buf;
    srand(time(NULL));

    // Shared memory
    key = ftok("Pract01_SO.c", 1);

    if ((shmid = shmget(key, 100 * sizeof(int), IPC_CREAT | 0777)) == -1)
	  exit(1);

    v = (int *) shmat(shmid, NULL, 0);

    // Parent process
    for (size_t i = 0; i < 100; i++) {
      v[i] = rand();
    }

    // Run children
    for (i = 0; i < CHILDREN; i++) {
	     if (!fork()) {
         if (i == 0) {
           procesoHijo1(v);
         }
         else if (i == 1) {
           procesoHijo2(v);
         }
         else{
           procesoHijo3(v);
         }
	        exit(0);
	     }
    }

    // Wait to finish
    for (i = 0; i < CHILDREN; i++) {
	     pid_t pid = wait(&status);
	     printf("\nChild %d finished with status %d\n\n", pid, WEXITSTATUS(status));
    }

    // Final result
    for (size_t i = 0; i < 100; i++) {
      fprintf(stdout, "Vector value <%d>: %d\n", (i + 1), (*v + i));
    }

    // Detach segment
    shmdt(v);

    // Mark the segment to be destroyed
    shmctl(shmid, IPC_RMID, &buf);

    return 0;
}
