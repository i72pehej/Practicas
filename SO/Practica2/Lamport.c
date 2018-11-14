#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>  // Aplicar libreria para bool
#include <stdlib.h>

double counter = 0;

#define ITER	30
#define NHILOS	4

int main()
{
    pthread_t hilos[NHILOS];  //ID de cada hilo.
    int status, i, v[NHILOS];
    extern double counter;
    void *adder(void *);
    double *r_value;
/*
    for (size_t x = 0; x < NHILOS; x++) {
      Eligiendo[x] = false;
      Numero[x] = 0;
    }
*/
    // Create NHILOS threads
    for (i = 0; i < NHILOS; i++) {
      v[i] = i;
	    if ((status = pthread_create(&hilos[i], NULL, adder, (void *) &v[i])))
      exit(status);
    }

    // Wait threads
    for (i = 0; i < NHILOS; i++) {
	     pthread_join(hilos[i], (void **) &r_value); // Recibe el ID del hilo y el retorno de to_return.
	     printf("Value returned by %lu thread: %lf\n", hilos[i], *r_value);
    }

    // Final result
    fprintf(stdout, "Final result: %f\n", counter);

    return 0;
}

int maximo(int *v){
  int max = 0;
  for (size_t i = 0; i < NHILOS; i++) {
    if (max < v[i]) {
      max = v[i];
    }
  }
  return max;
}

void *adder(void *p){ // Recibe el último parámetro de phtread_create = número que le asignamos a cada hilo.
    double l, *to_return;
    extern double counter;  // Todos los hilos pueden acceder a este parámetro.
    int *id;

    id = (int *) p;

    //Corrección de Lamport.
    extern bool Eligiendo[NHILOS];
    extern int Numero[NHILOS];

    for (size_t j = 0; j < NHILOS; j++) {
      Eligiendo[*id] = true;
      Numero[*id] = 1 + maximo(Numero);
      Eligiendo[*id] = false;

      for (size_t k = 0; k < NHILOS; k++) {
        while (Eligiendo[k]) {}
        while ((Numero[k] != 0) && ((Numero[k] < Numero[*id]) || ((Numero[k] == Numero[*id]) && (k < *id)))) {}
      }

      for (size_t i = 0; i < ITER; i++) {
        //SECCION CRITICA - vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
        l = counter;  // Para ampliar la Sección Crítica (no tiene más importancia).
	      fprintf(stdout, "Hilo %d: %f\n", *id, counter);
        l++;
	      counter = l;
        //SECCION CRITICA - ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
      }
    }

    to_return = malloc(sizeof(double)); // Al terminar la función se libera la memoria y elimina los parámetros,
                                        // por lo que perderíamos sus valores al llegar a phtread_join.
    *to_return = counter;

    pthread_exit((void *) to_return);
}
