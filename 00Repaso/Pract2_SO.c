//Repaso de la práctica 2 - SIstemas Operativos

/*Ejercicio 2 -> Modfificar programa para que se ejecuten 4 hilos y resolver sección crítica.
Seguimos teniendo el programa del contador.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include <semaphore.h>

int contador = 0;  //Variable global.
sem_t semaforoContador;  //Semáforo general.
pthread_mutex_t mutexContador;  //Mutex binario.

#define N_HILOS 4
#define ITER 5


void *funcionHilo(void *id_Hilo) {
  extern int contador;  //Variable global.
  int *res, i, *id;

  id = (int *) id_Hilo;
  res = malloc(sizeof(int));  //Reserva de memoria para no perder resultado.

//Sección crítica.
//-------------------------------------------------------------
/*  if(sem_wait(&semaforoContador) != 0) {exit(EXIT_FAILURE);}
  else {printf("\nSemáforo bloqueado para Hilo <%d>.\n", *id);}*/

  if(pthread_mutex_lock(&mutexContador) != 0) {exit(EXIT_FAILURE);}
  else {printf("\nMutex binario bloqueado para Hilo <%d>.\n", *id);}

  for (i = 0; i < ITER; i++) {contador ++;}

  if(pthread_mutex_unlock(&mutexContador) != 0) {exit(EXIT_FAILURE);}
  else {printf("\nMutex binario desbloqueado para Hilo <%d>.\n", *id);}

  /*if(sem_post(&semaforoContador) != 0) {exit(EXIT_FAILURE);}
  else {printf("\nSemáforo desbloqueado.\n");}*/
//-------------------------------------------------------------
  printf("\n");

  *res = contador;
  pthread_exit((void *) res);
}

int main(int argc, char const *argv[]) {
  pthread_t hilos[N_HILOS];
  extern int contador;  //Variable global.
  int v_id[N_HILOS], i, *resultado;

//Inicialización de semáforo.
  /*if(sem_init(&semaforoContador, 0, 1) != 0) {exit(EXIT_FAILURE);}
  else {printf("\nSemáforo creado correctamente.\n");}*/

//Inicialización de mutex binario.
  if(pthread_mutex_init(&mutexContador, NULL) != 0) {exit(EXIT_FAILURE);}
  else {printf("\nMutex binario creado correctamente.\n");}

//Creación de N_HILOS hilos.
  printf("\n");
  for (i = 0; i < N_HILOS; i++) {
    v_id[i] = i;
    if(pthread_create(&hilos[i], NULL, funcionHilo, (void *) &v_id[i]) != 0) {exit(EXIT_FAILURE);}
    printf("Hilo <%d>, con ID <%d>, creado satisfactoriamente.\n", hilos[i], v_id[i]);
  }

//Espera de N_HILOS hilos.
  for (i = 0; i < N_HILOS; i++) {
    if (pthread_join(hilos[i], (void **) &resultado) != 0) {exit(EXIT_FAILURE);}
    printf("Resultado del hilo <%d> (ID = %d): <%d>.\n", hilos[i], v_id[i], *resultado);
  }

//Destrucción de semáforo.
  /*if(sem_destroy(&semaforoContador) != 0) {exit(EXIT_FAILURE);}
  else {printf("\nEl semáforo ha sido destruido. Memoria liberada.\n");}*/

//Destrucción de mutex binario.
  if(pthread_mutex_destroy(&mutexContador) != 0) {exit(EXIT_FAILURE);}
  else {printf("\nMutex binario destruido.\n");}

//Resutado final.
  printf("\nEl resultado final del contador es: <%d>.\n\n", contador);

  return 0;
}
