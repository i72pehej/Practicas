#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

double suma_P = 0, suma_C = 0;

//Inicialización de Semáforos.
pthread_mutex_t semaforo_P, semaforo_C;

#define N 30

//Buffer/Vector de almacenamiento compartido.
int buffer[N];

int main()
{
    pthread_t hilo_P, hilo_C;
    int status, i, idProductor = 1, idConsumidor = 2;
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

    //Creación de un hilo productor.
	  if ((status = pthread_create(&hilo_P, NULL, productor, (void *) &idProductor)))
    exit(status);

    //Creación de un hilo consumidor.
    if ((status = pthread_create(&hilo_C, NULL, consumidor, (void *) &idConsumidor)))
    exit(status);

    // Wait threads
    pthread_join(hilo_P, (void **) &r_value_P);
    printf("Value returned by %lu thread: %lf\n", hilo_P, *r_value_P);
    pthread_join(hilo_C, (void **) &r_value_C);
    printf("Value returned by %lu thread: %lf\n", hilo_C, *r_value_C);

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

    // Final result
    fprintf(stdout, "\nResultado final productor: %f\n", suma_P);
    fprintf(stdout, "Resultado final consumidor: %f\n\n", suma_C);

    return 0;
}

//Hilo productor. -> Genera números de 0 a 1000 y los introduce en el buffer.
void *productor(void *p)
{
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
void *consumidor(void *c)
{
    double l, *to_return_C;
    extern double suma_C;
    extern int buffer[N];
    int *id, i;

    id = (int *) c;

    //Bloqueo de semáforo para que  únicamnete un hilo entre en SC.
    if(pthread_mutex_lock(&semaforo_C) != 0){printf("\nERROR. No se pudo bloquear el semáforo consumidor.\n");}
    else{printf("\nEl semáforo consumidor se ha bloqueado.\n\n");}

    for (i = 0; i < N; i++) {
      suma_C += buffer[i];
	    fprintf(stdout, "Suma de Hilo Consumidor (id = %d): %f\n", *id, suma_C);
    }

    //Desbloqueo del semáforo al terminar la SC.
    if (pthread_mutex_unlock(&semaforo_C) != 0) {printf("\nERROR. No se pudo desbloquear el semáforo consumidor.\n");}
    else{printf("\nEl semáforo consumidor se ha desbloqueado.\n\n");}

    to_return_C = malloc(sizeof(double));

    *to_return_C = suma_C;

    pthread_exit((void *) to_return_C);
}
