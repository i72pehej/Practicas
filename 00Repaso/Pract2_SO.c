//Repaso de la práctica 2 - SIstemas Operativos


/*Ejercicio 2 -> Modfificar programa para que se ejecuten 4 hilos y resolver sección crítica.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>

double counter = 0;

#define ITER 10
#define NHILOS 4

int main(int argc, char const *argv[]) {
  pthread_t hilos[NHILOS];
  int status, i, v[NHILOS];
  extern double counter;
  void *adder(void *);
  double *r_value;

// Create NHILOS threads
  for (i = 0; i < NHILOS; i++) {
    v[i] = i;
    if ((status = pthread_create(&hilos[i], NULL, adder, (void *) &v[i])))
    exit(status);
  }

// Wait threads
  printf("\n");
  for (i = 0; i < NHILOS; i++) {
    pthread_join(hilos[i], (void **) &r_value);
    printf("Valor devuelto por el hilo %lu: <%lf>.\n", hilos[i], *r_value);
  }

// Final result
  fprintf(stdout, "Resultado final: <%f>.\n", counter);

  return 0;
}

void *adder(void *p) {
  double l, *to_return;
  extern double counter;
  int *id, i;

  id = (int *) p;

  printf("\n");
  for (i = 0; i < ITER; i++) {
    l = counter;
    fprintf(stdout, "Hilo %d: <%f>.\n", *id, counter);
    l++;
    counter = l;
  }

  to_return = malloc(sizeof(double));

  *to_return = counter;

  pthread_exit((void *) to_return);
}
