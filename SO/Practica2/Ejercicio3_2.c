//Ejercicio3.2 -> Hay P hilos productores y C hilos consumidores. Cada número generado por un productor es consumido por un único consumidor.

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

double suma_P = 0, suma_C = 0;

//Inicialización de Semáforos.
pthread_mutex_t semaforo_P, semaforo_C;

#define N 3
#define N_Prod 15
#define N_Cons 3
#define LIMITE -1

//Buffer/Vector de almacenamiento compartido.
int buffer[N];

int main(){
  pthread_t hilo_P[N_Prod], hilo_C[N_Cons];
  int status, i, v_idProductor[N_Prod], v_idConsumidor[N_Cons];
  extern double suma_P, suma_C;
  void *productor(void *);
  void *consumidor(void *);
  double *r_value_P, *r_value_C;

  srand(time(NULL));

  //Creación del semáforo.
  if(pthread_mutex_init(&semaforo_P, NULL) != 0){
    printf("\nERROR. No se pudo crear el semáforo productor correctamente.\n");
    return 1;
  }else{printf("\nEl semáforo productor se ha creado correctamente.\n");}

  if(pthread_mutex_init(&semaforo_C, NULL) != 0){
    printf("\nERROR. No se pudo crear el semáforo consumidor correctamente.\n");
    return 1;
  }else{printf("\nEl semáforo consumidor se ha creado correctamente.\n");}

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
  if (pthread_mutex_destroy(&semaforo_P) != 0) {
    printf("\nERROR. No se pudo destruir el semáforo productor.\n");
    return 1;
  }
  else{printf("\nEl semáforo productor se ha destruido. Memoria liberada.\n");}

  if (pthread_mutex_destroy(&semaforo_C) != 0) {
    printf("\nERROR. No se pudo destruir el semáforo consumidor.\n");
    return 1;
  }
  else{printf("\nEl semáforo consumidor se ha destruido. Memoria liberada.\n");}

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

  //Bloqueo de semáforo para que  únicamnete un hilo entre en SC.
  if(pthread_mutex_lock(&semaforo_P) != 0){printf("\nERROR. No se pudo bloquear el semáforo productor.\n");}
  else{printf("\nEl semáforo productor se ha bloqueado.\n\n");}

  for (i = 0; i < N; i++) {
    //Genera números aleatorios entre 0 y 1000.
    l = rand() % 1001;
    buffer[i] = l;
    suma_P += buffer[i];
    fprintf(stdout, "Suma de Hilo Productor (id = %d): %f\n", *id, suma_P);
  }

  //Desbloqueo del semáforo al terminar la SC.
  if (pthread_mutex_unlock(&semaforo_P) != 0) {printf("\nERROR. No se pudo desbloquear el semáforo productor.\n");}
  else{printf("\nEl semáforo productor se ha desbloqueado.\n\n");}

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

  //Bloqueo de semáforo para que  únicamnete un hilo entre en SC.
  if(pthread_mutex_lock(&semaforo_C) != 0){printf("\nERROR. No se pudo bloquear el semáforo consumidor.\n");}
  else{printf("\nEl semáforo consumidor se ha bloqueado.\n\n");}

  for (i = 0; i < N; i++) {
    if (buffer[i] == NULL) {
      fprintf(stdout, "Error al consumir. Buffer vacío.\n");
    } else {
      suma_C += buffer[i];
      buffer[i];¿?¿?¿?¿ //Consumir el elemento del buffer.
      fprintf(stdout, "Suma de Hilo Consumidor (id = %d): %f\n", *id, suma_C);
    }
  }

  //Desbloqueo del semáforo al terminar la SC.
  if (pthread_mutex_unlock(&semaforo_C) != 0) {printf("\nERROR. No se pudo desbloquear el semáforo consumidor.\n");}
  else{printf("\nEl semáforo consumidor se ha desbloqueado.\n\n");}

  to_return_C = malloc(sizeof(double));

  *to_return_C = suma_C;

  pthread_exit((void *) to_return_C);
}
