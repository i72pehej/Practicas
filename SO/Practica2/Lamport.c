//Ejercicio 2 -> Corrección de Lamport.

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>  //Aplicar librería para bool.


#define ITER	10
#define NHILOS	4

//variables externas.
double counter = 0;
bool Eligiendo[NHILOS];
int Numero[NHILOS];

int main(){
  pthread_t hilos[NHILOS];  //ID de cada hilo.
  int status, i, v[NHILOS];
  void *adder(void *);
  double *r_value;
  extern double counter;
  extern bool Eligiendo[NHILOS];
  extern int Numero[NHILOS];

  //Inicializamos los vectores valores booleanos.
  for (i = 0; i < NHILOS; i++) {
    Eligiendo[i] = true;
    Numero[i] = false;
  }

  //Creación de NHILOS hilos.
  for (i = 0; i < NHILOS; i++) {
    v[i] = i;
    if ((status = pthread_create(&hilos[i], NULL, adder, (void *) &v[i])))
    exit(status);
  }

  //Espera de los hilos.
  for (i = 0; i < NHILOS; i++) {
    pthread_join(hilos[i], (void **) &r_value); //Recibe el ID del hilo y el valor devuelto de to_return.
    printf("Valor de retorno del hilo %lu: %lf\n", hilos[i], *r_value);
  }

  //Resultado final.
  fprintf(stdout, "Resultado final: %f\n", counter);

  return 0;
}

int maximo(int *v){
  int max = -1;
  for (size_t i = 0; i < NHILOS; i++) {
    if (max < v[i]) {
      max = v[i];
    }
  }
  return max;
}

void *adder(void *p){ //Recibe el último parámetro de phtread_create = número que le asignamos a cada hilo.
    double l, *to_return;
    extern double counter;  //Todos los hilos pueden acceder a este parámetro.
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
        while (Eligiendo[k]);
        while ((Numero[k] != 0) && ((Numero[k] < Numero[*id]) || ((Numero[k] == Numero[*id]) && (k < *id))));
      }

        //SECCION CRITICA - vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
        l = counter;  //Para ampliar la Sección Crítica (no tiene más importancia).
	      fprintf(stdout, "Hilo %d: %f\n", *id, counter);
        l++;
	      counter = l;

        Numero[*id] = 0;  //Reducimos la prioridad para dejar pasar al resto.
        //SECCION CRITICA - ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    }

    //Al terminar la función se libera la memoria y elimina los parámetros, por lo que perderíamos sus valores al llegar a phtread_join.
    to_return = malloc(sizeof(double));
    *to_return = counter;

    pthread_exit((void *) to_return);
}
