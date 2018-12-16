//Ejercicio3.1 -> Hay un único hilo productor y un único hilo consumidor.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>  //Para utilizar semáforos.

double suma_P = 0, suma_C = 0;

//Creación de semáforos.
sem_t SCritica, Ocupados, Libres;

#define N 30
#define ITER 100

//Buffer/Vector de almacenamiento compartido.
int buffer[N];

int main(){
  pthread_t hilo_P, hilo_C;
  int status, i, idProductor = 1, idConsumidor = 2;
  extern double suma_P, suma_C;
  void *productor(void *);
  void *consumidor(void *);
  double *r_value_P, *r_value_C;

  srand(time(NULL));

  //Inicialización del semáforo.
  if(sem_init(&SCritica, 0, 1) != 0){
    printf("\nERROR. No se pudo crear el semáforo SCritica correctamente.\n");
    return 1;
  }else{printf("\nEl semáforo SCritica se ha creado correctamente.\n");}

  if(sem_init(&Ocupados, 0, 0) != 0){
    printf("\nERROR. No se pudo crear el semáforo Ocupados correctamente.\n");
    return 1;
  }else{printf("\nEl semáforo Ocupados se ha creado correctamente.\n");}

  if(sem_init(&Libres, 0, N) != 0){
    printf("\nERROR. No se pudo crear el semáforo Libres correctamente.\n");
    return 1;
  }else{printf("\nEl semáforo Libres se ha creado correctamente.\n");}

  //Creación de un hilo productor.
  if ((status = pthread_create(&hilo_P, NULL, productor, (void *) &idProductor)))
  exit(status);

  //Creación de un hilo consumidor.
  if ((status = pthread_create(&hilo_C, NULL, consumidor, (void *) &idConsumidor)))
  exit(status);

  //Espera de lo hilos.
  pthread_join(hilo_P, (void **) &r_value_P);
  printf("Valor retornado por el hilo productor %lu: %lf\n", hilo_P, *r_value_P);

  pthread_join(hilo_C, (void **) &r_value_C);
  printf("Valor retornado por el hilo consumidor %lu: %lf\n", hilo_C, *r_value_C);

  //Destrucción de Semáforos.
  if (sem_destroy(&SCritica) != 0) {
    printf("\nERROR. No se pudo destruir el semáforo SCritica.\n");
    return 1;
  }
  else {printf("\nEl semáforo SCritica se ha destruido. Memoria liberada.\n");}

  if (sem_destroy(&Ocupados) != 0) {
    printf("\nERROR. No se pudo destruir el semáforo Ocupados.\n");
    return 1;
  }
  else {printf("\nEl semáforo Ocupados se ha destruido. Memoria liberada.\n");}

  if (sem_destroy(&Libres) != 0) {
    printf("\nERROR. No se pudo destruir el semáforo Libres.\n");
    return 1;
  }
  else {printf("\nEl semáforo Libres se ha destruido. Memoria liberada.\n");}

  // Final result
  fprintf(stdout, "\nResultado final productor: %f\n", suma_P);
  fprintf(stdout, "Resultado final consumidor: %f\n\n", suma_C);

  return 0;
}

//Hilo productor. -> Genera números de 0 a 1000 y los introduce en el buffer.
void *productor(void *p){
  double l, *to_return_P;
  extern double suma_P;
  extern int buffer[N];
  int *id, i;

  id = (int *) p;

  for (i = 0; i < ITER; i++) {
    sem_wait(&Libres);  //Espera a la existencia de espacios libres.
    //Genera números aleatorios entre 0 y 1000.
    l = rand() % 1001;
    sem_wait(&SCritica);  //Espera a que la SC sea accesible.
      buffer[i] = l;
      suma_P += buffer[i];
      fprintf(stdout, "Suma de Hilo Productor (id = %d): %f\n", *id, suma_P);
    sem_post(&SCritica);  //Señal de desbloqueo de SC.
    sem_post(&Ocupados);  //Señal para indicar que se ha ocupado un espacio.
  }

  to_return_P = malloc(sizeof(double));
  *to_return_P = suma_P;

  pthread_exit((void *) to_return_P);
}

//Hilo consumidor. -> Coge los números del buffer y los suma.
void *consumidor(void *c){
  double l, *to_return_C;
  extern double suma_C;
  extern int buffer[N];
  int *id, i;

  id = (int *) c;

  for (i = 0; i < ITER; i++) {
    sem_wait(&Ocupados);  //Espera a la existencia de espacios ocupados que consumir.
    sem_wait(&SCritica);  //Espera a que la SC sea accesible.
      suma_C += buffer[i];
    fprintf(stdout, "Suma de Hilo Consumidor (id = %d): %f\n", *id, suma_C);
    sem_post(&SCritica);  //Señal de desbloqueo de SC.
    sem_post(&Libres);  //Señal para indicar que se ha consumido un espacio.
  }

  to_return_C = malloc(sizeof(double));
  *to_return_C = suma_C;

  pthread_exit((void *) to_return_C);
}
