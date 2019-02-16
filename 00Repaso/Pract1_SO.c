//Práctica 1 - Sistemas Operativos.

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define HIJOS 3
#define ITER 3
#define SUCCESS 10
#define TAM 100

//Ejercicio 1.
//Implementar un proceso PADRE que cree 3 hijos y luego espera a que finalicen antes de finalizar él mismo.
/*
void procesoHijo(int id) {
  key_t clave;
  int shmid, i;
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
*/

//Ejercicio 2.
/*Los tres hijos comparten un vector de 100 enteros. Cada uno ha de realizar lo siguiente:
  - Pedir un íncide del vector y un valor entero por teclado y almacenarlo en el vector. Ha de repetirse 10 veces.
  - Cambiar aleatoriamente un elemento del vesctor y bloquearse durante 1 segundo. Ha de repetirse 100 veces.
  - Sumar todos los elementos del vector, mostrar la suma y bloquearse durante 30 segundos. Ha de repetirse  5 veces.*/
/*
//Proceso Hijo 1 -> Pide un indice y un valor y lo almacena.
void procesoHijo1(int *vector) {
  int i, indice, valor;

  for (i = 0; i < 2; i++) {
    printf("Introduzca el índice que quieras actualizar/modificar:\n");
    fscanf(stdin, "%d", &indice);
    printf("Introduzca el valor\n");
    fscanf(stdin, "%d", &valor);

    printf("\nValor actual del vector, índice <%d>: <%d>.\n", indice, vector[indice]);
    vector[indice] = valor;
    printf("\nVector modificado. Valor de índice <%d>: <%d>.\n\n", indice, vector[indice]);
  }

  printf("\n");
  exit(SUCCESS);
}

//Proceso Hijo 2 -> Cambia aleatoriamente un elemento del vector y se bloquea 1s 100 veces.
void procesoHijo2(int *vector) {
  int i;
  int indice = rand() % TAM;
  int valor = rand();

  for (i = 0; i < TAM; i++) {
    vector[indice] = valor;
  }

  sleep(1);
  exit(SUCCESS);
}

//proceso Hijo 3 -> Suma los elementos del vector y muestra la suma. Se bloquea 30s.
void procesoHijo3(int *vector) {
  int i, suma = 0;

  for (i = 0; i < TAM; i++) {
    suma += vector[i];
  }

  printf("El total de la suma de los elementos del vector: <%d>.\n\n", suma);
  sleep(5);
  exit(SUCCESS);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int i, shmid, estado, pID;
  key_t clave;
  struct shmid_ds buffer;
  int *vector;

//Memoria compartida.
  clave = ftok("Pract1_SO.c", 1);

  shmid = shmget(clave, (TAM * sizeof(int)), IPC_CREAT | 0777);
  if(shmid == -1) {exit(EXIT_FAILURE);}

  vector = (int *) shmat(shmid, NULL, 0);

//Creación de Hijos.
  for (i = 0; i < HIJOS; i++) {
    if (fork() == 0) {
      if (i == 0) {procesoHijo1(vector);}
      else if (i == 1) {procesoHijo2(vector);}
      else {procesoHijo3(vector);}

      exit(EXIT_SUCCESS);
    }
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
*/

//Ejercicio 3.
//El proceso es inicialmente rellenado por el proceso PADRE aleatoriamente.

//Proceso Hijo 1 -> Pide un indice y un valor y lo almacena.
void procesoHijo1(int id) {
  int shmid;
  key_t clave;
  int *vector;

  int i, indice, valor;

  clave = ftok("Pract1_SO", 1);

  shmid = shmget(clave, (TAM * sizeof(int)), 0);
  if (shmid == -1) {exit(EXIT_FAILURE);}

  vector = (int *) shmat(shmid, NULL, 0);

  for (i = 0; i < 2; i++) {
    printf("Introduzca el índice que quieras actualizar/modificar:\n");
    fscanf(stdin, "%d", &indice);
    printf("Introduzca el valor\n");
    fscanf(stdin, "%d", &valor);

    printf("\nValor actual del vector, índice <%d>: <%d>.\n", indice, vector[indice]);
    vector[indice] = valor;
    printf("\nVector modificado. Valor de índice <%d>: <%d>.\n\n", indice, vector[indice]);
  }

  printf("\n");
  shmdt(vector);
  exit(SUCCESS);
}

//Proceso Hijo 2 -> Cambia aleatoriamente un elemento del vector y se bloquea 1s 100 veces.
void procesoHijo2(int *vector) {
  int i;
  int indice = rand() % TAM;
  int valor = rand();

  for (i = 0; i < TAM; i++) {
    vector[indice] = valor;
  }

  sleep(1);
  exit(SUCCESS);
}

//proceso Hijo 3 -> Suma los elementos del vector y muestra la suma. Se bloquea 30s.
void procesoHijo3(int *vector) {
  int i, suma = 0;

  for (i = 0; i < TAM; i++) {
    suma += vector[i];
  }

  printf("El total de la suma de los elementos del vector: <%d>.\n\n", suma);
  sleep(5);
  exit(SUCCESS);
}


int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int i, shmid, estado, pID;
  key_t clave;
  struct shmid_ds buffer;
  int *vector;

//Memoria compartida.
  clave = ftok("Pract1_SO.c", 1);

  shmid = shmget(clave, (TAM * sizeof(int)), IPC_CREAT | 0777);
  if(shmid == -1) {exit(EXIT_FAILURE);}

  vector = (int *) shmat(shmid, NULL, 0);

//Rellenado del vector.
  for (i = 0; i < TAM; i++) {
    vector[i] = rand();
  }

//Creación de Hijos.
  for (i = 0; i < HIJOS; i++) {
    if (fork() == 0) {
      if (i == 0) {procesoHijo1(i);}
      else if (i == 1) {procesoHijo2(vector);}
      else {procesoHijo3(vector);}
    }
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

  exit(EXIT_SUCCESS);
}
*/
/*
int main(int argc, char const *argv[]) {
  pid_t pid;
  int estado, pidHijo;

  pid = fork();
  switch (pid) {
    case -1:  //Caso ERROR del fork().
      printf("\nError al crear proceso HIJO.\n");
      exit(EXIT_FAILURE);

    case 0:  //Proceso HIJO.
      //FUNCIONES DE LOS HIJOS
      printf("\nSoy el HIJO <%d>, y mi PADRE <%d>.\n", getpid(), getppid());
      exit(EXIT_SUCCESS);

    default:  //Proceso PADRE.
      printf("\nProceso PADRE, con PID = <%d>.\n", getpid());
      //FUNCIONES DEL PADRE
      pidHijo = wait(&estado);
      if(pidHijo == -1) {exit(EXIT_FAILURE);}
      else {printf("\nProceso HIJO <%d> terminado con estado: <%d>.\n", pidHijo, WEXITSTATUS(&estado));}
  }

  printf("\n");
  return 0;
}
*/
