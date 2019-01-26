//Práctica 1 - Sistemas Operativos.

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define HIJOS 3
#define ITER 3
#define SUCCESS 10
#define TAM 100

//Ejercicio 1.
//Implementar un proceso PADRE que cree 3 hijos y luego espera a que finalicen antes de finalizar él mismo.

void procesoHijo(int id) {
  key_t clave, i;
  int shmid;
  int *contador;

//Memoria compartida.
  clave = ftok("Pract1_SO.c", 1);

  shmid = shmget(clave, sizeof(int), 0);
  if (shmid == -1) {exit(EXIT_FAILURE);}

  contador = (int *) shmat(shmid, NULL, 0);

//Trabajo de los procesos.
  printf("\n");

  for (i = 0; i < ITER; i++) {
    printf("Proceso HIJO <%d> : <%d>.\n", id, *contador);
    *contador = *contador + 1;
  }

//Desconexión de memoria compartida.
  shmdt(contador);

  exit(SUCCESS);
}

int main(int argc, char const *argv[]) {
  int i, shmid, estado;
  int *contador;
  key_t clave;
  struct shmid_ds buffer;  //Buffer para guardar la información posible de shmctl().

//Memoria compartida.
  clave = ftok("Pract1_SO.c", 1);  //Crea clave de acceso a memoria.

  shmid = shmget(clave, sizeof(int), IPC_CREAT | 0777);  //Crea el espacio de memoria a compartir.
  if (shmid == -1) {exit(EXIT_FAILURE);}  //Comprobación para saber si se ha creado correctamente.

  contador = (int *) shmat(shmid, NULL, 0);
  *contador = 0;

//Creación de hijos.
  for (i = 0; i < HIJOS; i++) {
    if (fork() == 0) {procesoHijo(i); exit(EXIT_SUCCESS);}
  }

//Espera a los hijos para finalizar.
  for (i = 0; i < HIJOS; i++) {
    int pID = wait(&estado);
    if (pID == -1) {exit(EXIT_FAILURE);}
    printf("\nEl proceso HIJO <%d> ha terminado con estado: <%d>.\n", pID, WEXITSTATUS(estado));
  }
  printf("Resultado final: %d\n", *contador);

//Desconexión de memoria compartida.
  shmdt(contador);

//Destrucción del segmento.
  shmctl(shmid, IPC_RMID, &buffer);

  printf("\n");
  return 0;
}


//Ejercicio 2.
/*Los tres hijos comparten un vector de 100 enteros. Cada uno ha de realizar lo siguiente:
  - Pedir un íncide del vector y un valor entero por teclado y almacenarlo en el vector. Ha de repetirse 10 veces.
  - Cambiar aleatoriamente un elemento del vesctor y bloquearse durante 1 segundo. Ha de repetirse 100 veces.
  - Sumar todos los elementos del vector, mostrar la suma y bloquearse durante 30 segundos. Ha de repetirse  5 veces.*/

void procesoHijo1() {

}

void procesoHijo2() {

}

void procesoHijo3() {

}

int main(int argc, char const *argv[]) {
  int i, shmid, estado, pID;
  key_t clave;
  shmid_ds &buffer;
  int vector[TAM];

//Memoria compartida.
  clave = ftok("Pract1_SO.c", 1);

  shmid = shmget(clave, (TAM * sizeof(int)), IPC_CREAT | 0777);
  if(shmid == -1) {exit(EXIT_FAILURE);}

  vector = (int *) shmat(shmid, NULL, 0);

//Creación de Hijos.
for (i = 0; i < HIJOS; i++) {
  if (i == 0) {procesoHijo1(i);}
  else if (i == 1) {procesoHijo2(i);}
  else {procesoHijo3(i);}
}

//Espera de hijos.
  for (i = 0; i < HIJOS; i++) {
    pID = wait(&estado);
    if (pID == -1) {exit(EXIT_FAILURE);}
    printf("Proceso Hijo <%d> terminado con estado: <%d>.\n", pID, WEXITSTATUS(estado));
  }

//Desconexión.
  shmdt(vector);

//Destrucción de memoria compartida.
  shmctl(shmid, IPC_RMID, &buffer);

  return 0;
}


//Ejercicio 3.
//El proceso es inicialmente rellenado por el proceso PADRE aleatoriamente.
