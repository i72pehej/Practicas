#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

double counter = 0;

//Corrección con Semáforos.
pthread_mutex_t semaforo;

#define ITER	10
#define NHILOS	4

int main()
{
    pthread_t hilos[NHILOS];
    int status, i, v[NHILOS];
    extern double counter;
    void *adder(void *);
    double *r_value;

    srand(time(NULL));

    //Creación del semáforo.
    if(pthread_mutex_init(&semaforo, NULL) != 0){
      printf("\nERROR. No se pudo crear el semáforo correctamente.\n");
      return 1;
    }else{printf("\nEl semáforo se ha creado correctamente.\n");}

    // Create NHILOS threads
    for (i = 0; i < NHILOS; i++) {
	     v[i] = i;
	     if ((status = pthread_create(&hilos[i], NULL, adder, (void *) &v[i])))
	     exit(status);
    }

    // Wait threads
    for (i = 0; i < NHILOS; i++) {
	     pthread_join(hilos[i], (void **) &r_value);
	     printf("Value returned by %lu thread: %lf\n", hilos[i], *r_value);
    }

    //Destrucción del Semáforo.
    if (pthread_mutex_destroy(&semaforo) != 0) {
      printf("\nERROR. No se pudo destruir el semáforo.\n");
      return 1;
    }
    else{printf("\nEl semáforo se ha destruido. Memoria liberada.\n");}

    // Final result
    fprintf(stdout, "\nResultado final: %f\n", counter);

    return 0;
}

void *adder(void *p)
{
    double l, *to_return;
    extern double counter;
    int *id, i;

    id = (int *) p;

    rand() % 1000;

    //Bloqueo de semáforo para que  únicamnete un hilo entre en SC.
    if(pthread_mutex_lock(&semaforo) != 0){printf("\nERROR. No se pudo bloquear el semáforo.\n");}
    else{printf("\nEl semáforo se ha bloqueado.\n\n");}

    for (i = 0; i < ITER; i++) {
	     l = counter;
	     fprintf(stdout, "Hilo %d: %f\n", *id, counter);
	     l++;
	     counter = l;
    }

    //Desbloqueo del semáforo al terminar la SC.
    if (pthread_mutex_unlock(&semaforo) != 0) {printf("\nERROR. No se pudo desbloquear el semáforo.\n");}
    else{printf("\nEl semáforo se ha desbloqueado.\n\n");}

    to_return = malloc(sizeof(double));

    *to_return = counter;

    pthread_exit((void *) to_return);
}
