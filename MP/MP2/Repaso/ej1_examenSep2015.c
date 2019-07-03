#include <stdio.h>
#include <stdlib.h>


struct nodo {
  int n;
  struct nodo *sig;
};


struct nodo *nuevoElemento() {
  return((struct nodo *) malloc(sizeof(struct nodo)));
}


void insertaDelante(struct nodo **cabeza, int n) {
  struct nodo *nuevo = NULL;

  nuevo = nuevoElemento();
  nuevo -> n = n;

  nuevo -> sig = *cabeza;
  *cabeza = nuevo;
}


void insertaDetras(struct nodo **cabeza, int n) {
  struct nodo *nuevo = NULL;
  struct nodo *aux = NULL;

  nuevo = nuevoElemento();
  nuevo -> n = n;
  nuevo -> sig = NULL;

  // Lista vacía.
  if (*cabeza == NULL) {*cabeza = nuevo;}
  // Lista no vacía.
  else {
    aux = *cabeza;
    while (aux -> sig != NULL) {aux = aux -> sig;}
    aux -> sig = nuevo;
  }
}


void impimirListaRecursiva(struct nodo *cabeza) {
  if (cabeza != NULL) {
    struct nodo *aux = NULL;

    aux = cabeza;
    printf("%d  ", aux -> n);
    impimirListaRecursiva(aux -> sig);
  }
}


void menorMayor(struct nodo *cabeza, int *vec) {
  struct nodo *aux = NULL;

  aux = cabeza;
  vec[0] = aux -> n;
  vec[1] = aux -> n;

  while (aux != NULL) {
    if (aux -> n < vec[0]) {vec[0] = aux -> n;}
    if (aux -> n > vec[1]) {vec[1] = aux -> n;}

    aux = aux -> sig;
  }
}


int buscarElemento(struct nodo *cabeza, int n) {
  struct nodo *aux = NULL;
  int encontrado = 0;

  aux = cabeza;
  while ((aux != NULL) && (encontrado == 0)) {
    if (aux -> n == n) {encontrado = 1;}
    else {aux = aux -> sig;}
  }

  return(encontrado);
}


void borrarElemento(struct nodo **cabeza, int *n) {
  if (buscarElemento(*cabeza, *n) == 0) {
    printf("\n\nERROR. El elemento que desea borrar no se encuentra en la lista.\n");
  }
  else {
    struct nodo *aux = NULL;
    struct nodo *anterior = NULL;

    aux = *cabeza;
    while (aux -> n != *n) {
      anterior = aux;
      aux = aux -> sig;
    }

    // El elemento a borrar es la cabeza.
    if (aux == *cabeza) {
      *cabeza = aux -> sig;
      free(aux);
    }
    // El elemento a borrar no es la cabeza.
    else {
      anterior -> sig = aux -> sig;
      free(aux);
    }
  }
}



int main(int argc, char const *argv[]) {
  system("clear");

  struct nodo *cabeza = NULL;
  int cant, opcion, elem;
  void (*punteroFun) (struct nodo **, int);
  int menor_mayor[2];

  printf("\n\t¿Cuantos elementos desea insertar?  -> ");
  fscanf(stdin, "%d", &cant);
  printf("\n");

  printf("\n[0] Insertar por DELANTE.\n[1] Insertar por DETRAS.\n");
  printf("\n\t¿Cómo los desea insertar? -> ");
  fscanf(stdin, "%d", &opcion);
  printf("\n");
  if (opcion == 0) {punteroFun = &insertaDelante;}
  else {punteroFun = &insertaDetras;}

  for (size_t i = 0; i < cant; i++) {
    printf("\nIntroduzca el elemento a insertar: ");
    fscanf(stdin, "%d", &elem);
    (*punteroFun) (&cabeza, elem);
  }

  printf("\n\tLista: ");
  impimirListaRecursiva(cabeza);
  printf("\n\n");

  menorMayor(cabeza, menor_mayor);
  printf("El menor elemento es: <%d>\nEl mayor elemento es: <%d>\n\n", menor_mayor[0], menor_mayor[1]);

  printf("\nSeleccione el elemento que desea borrar: ");
  fscanf(stdin, "%d", &elem);
  printf("\n");
  borrarElemento(&cabeza, &elem);

  printf("\n\tNueva Lista: ");
  impimirListaRecursiva(cabeza);
  printf("\n\n");

  return 0;
}
