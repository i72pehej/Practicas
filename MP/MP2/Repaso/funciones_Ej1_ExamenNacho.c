#include "funciones_Ej1_ExamenNacho.h"


////////////////////////////////////////////////////////////////////////////////

int selecionaInsertar(int *selec) {
  printf("\n\nMétodos de inserción:\n");
  printf("\n0 -> Inserción por DELANTE.\n1 -> Inserción por DETRÁS. (Por defecto)");
  printf("\n\nSeleccione el método deseado para la inserción: ");
  fscanf(stdin, "%d", selec);

  if (selec == 0) {return 0;}
  else {return 1;}
}

////////////////////////////////////////////////////////////////////////////////

struct lista *nuevoElemento() {
  // Lista auxiliar para añadir los elementos.
  struct lista *aux;

  // Reserva de memoria.
  aux = (struct lista *) malloc(sizeof(struct lista));

  // Introducción del elemento deseado.
  printf("\nIntroduzca el número a añadir a la lista: ");
  fscanf(stdin, "%d", &aux -> n);

  return(aux);
}

////////////////////////////////////////////////////////////////////////////////

void insertarDelante(struct lista **cabeza) {
  struct lista *nuevo = NULL;

  // Se crea el nuevo elemento/nodo de la lista.
  nuevo = nuevoElemento();

  // Se modifica la cabeza para que sea el nuevo elemento creado.
  nuevo -> sig = *cabeza;
  *cabeza = nuevo;
}

////////////////////////////////////////////////////////////////////////////////

void insertarDetras(struct lista **cabeza) {
  struct lista *nuevo = NULL;
  struct lista *aux = NULL;

  // Reserva para el nuevo elemento.
  nuevo = nuevoElemento();
  // Creamos el final de la lista.
  nuevo -> sig = NULL;

  // Caso 1: La lista está vacía, el nuevo elemento es la cabeza.
  if (*cabeza == NULL) {*cabeza = nuevo;}

  // Caso 2: La lista no está vacía, se inserta el nuevo elemento.
  else {
    aux = *cabeza;
    // Recorremos la lista hasta llegar al último elemento, donde paramos.
    while (aux -> sig != NULL) {
      aux = aux -> sig;
    }
    aux -> sig = nuevo;
  }
}

////////////////////////////////////////////////////////////////////////////////

void imprimirLista(struct lista *cabeza) {
  struct lista *aux = NULL;

  // Recorremos la lista entera imprimiendo los valores.
  aux = cabeza;
  printf("\n\tLista: ");
  while (aux != NULL) {
    printf("%d ", aux -> n);
    aux = aux -> sig;
  }
  printf("\n\n");
}

////////////////////////////////////////////////////////////////////////////////

void imprimirListaRecursivo(struct lista *cabeza) {
  struct lista *aux = NULL;

  aux = cabeza;
  if (aux != NULL) {
    printf("%d ", aux -> n);
    imprimirListaRecursivo(aux -> sig);
  }
}

////////////////////////////////////////////////////////////////////////////////

void mayor_menor(int *maximo, int *minimo, struct lista *cabeza) {
  struct lista *aux;

  aux = cabeza;
  while (aux != NULL) {
    if (aux -> n > *maximo) {*maximo = aux -> n;}
    if (aux -> n < *minimo) {*minimo = aux -> n;}

    aux = aux -> sig;
  }
}

////////////////////////////////////////////////////////////////////////////////

int buscarElemento(struct lista *cabeza, int *n) {
  int encontrado = 0;
  struct lista *aux = NULL;

  aux = cabeza;
  while ((aux != NULL) && (encontrado == 0)) {
    if (aux -> n == *n) {encontrado = 1;}
    else {aux = aux -> sig;}
  }

  return(encontrado);
}

////////////////////////////////////////////////////////////////////////////////

void borrarElemento(struct lista **cabeza, int *n) {
  // Elemento anterior al borrado.
  struct lista *anterior = NULL;
  // Elemento a borrar.
  struct lista *aux = NULL;

  // Búsqueda del elemento a buscar.
  if ((buscarElemento(*cabeza, n)) == 0) {
    printf("\nNo se ha encontrado el elemento buscado.\n");
  }
  // Búsqueda del elemento que se desea borrar y su anterior.
  else {
    aux = *cabeza;
    while (aux -> n != *n) {
      anterior = aux;
      aux = aux -> sig;
    }

    // Caso 1: El elemento a borrar es la cabeza. La nueva cabeza es el siguiente.
    if (aux == *cabeza) {
      *cabeza = aux -> sig;

      // Se libera la antigua cabeza.
      free(aux);
    }

    // Caso 2: El elemento a borrar no es la cabeza. El siguiente al anterior es el siguiente del elemento borrado.
    else {
      anterior -> sig = aux -> sig;

      // Se libera el nodo.
      free(aux);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
