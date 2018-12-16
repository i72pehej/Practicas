//Ejercicio3.2 -> Hay P hilos productores y C hilos consumidores. Cada número generado por un productor es consumido por un único consumidor.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

double suma_P = 0, suma_C = 0;

//Inicialización de Semáforos.
pthread_mutex_t semaforo_P, semaforo_C;

#define N 10
#define N_Prod 4
#define N_Cons 2
#define ITER 5

//Buffer/Vector de almacenamiento compartido.
int buffer[N];

//Creación de semáforos.
sem_t SCritica, Ocupados, Libres;

//Iteradores compartidos.
int indice_P = -1, indice_C = -1;

int main(){
  pthread_t hilo_P[N_Prod], hilo_C[N_Cons];
  int status, i, v_idProductor[N_Prod], v_idConsumidor[N_Cons];
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
  }else{printf("\nEl semáforo Libres se ha creado correctamente.\n\n");}

  //Creación de N_Prod hilos productores.
  for (size_t p = 0; p < N_Prod; p++) {
    v_idProductor[p] = p;

    if ((status = pthread_create(&hilo_P[p], NULL, productor, (void *) &v_idProductor[p])))
    exit(status);
  }

  //Creación de N_Cons hilos consumidores.
  for (size_t c = N_Prod, i = 0; c < (N_Prod + N_Cons), i < N_Cons; c++, i++) {
    v_idConsumidor[i] = c;

    if ((status = pthread_create(&hilo_C[i], NULL, consumidor, (void *) &v_idConsumidor[i])))
    exit(status);
  }

  //Espera de los hilos.
  for (size_t p = 0; p < N_Prod; p++) {
    pthread_join(hilo_P[p], (void **) &r_value_P);
    printf("Valor devuelto por el hilo productor %lu: %lf\n", hilo_P[p], *r_value_P);
  }

  for (size_t c = 0; c < N_Cons; c++) {
    pthread_join(hilo_C[c], (void **) &r_value_C);
    printf("Valor devuelto por el hilo consumidor %lu: %lf\n", hilo_C[c], *r_value_C);
  }

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

  //Resultado final.
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
      indice_P = (indice_P + 1) % N;
      buffer[indice_P] = l;
      suma_P += buffer[indice_P];
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
  int nConsumiciones = ((N_Prod * ITER) / N_Cons);

  id = (int *) c;

  for (i = 0; i < nConsumiciones; i++) {
    sem_wait(&Ocupados);  //Espera a la existencia de espacios ocupados que consumir.
    sem_wait(&SCritica);  //Espera a que la SC sea accesible.
    indice_C = (indice_C + 1) % N;
      suma_C += buffer[indice_C];
    fprintf(stdout, "Suma de Hilo Consumidor (id = %d): %f\n", *id, suma_C);
    sem_post(&SCritica);  //Señal de desbloqueo de SC.
    sem_post(&Libres);  //Señal para indicar que se ha consumido un espacio.
  }

  to_return_C = malloc(sizeof(double));
  *to_return_C = suma_C;

  pthread_exit((void *) to_return_C);
}
