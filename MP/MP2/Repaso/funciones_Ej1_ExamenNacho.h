#include <stdio.h>
#include <stdlib.h>


// Estructura para formar la lista.
struct lista {
  int n;
  struct lista *sig;
};


// Selecciona el método deseado para insertar.
int selecionaInsertar(int *selec);

// Imprime los elementos de la lista.
void imprimirLista(struct lista *cabeza);

// Imprime los elementos de la lista mediante llamadas recursivas.
void imprimirListaRecursivo(struct lista *cabeza);

// Reserva memoria para una lista de N elementos.
struct lista *nuevoElemento();

// Inserta el elemento pasado como argumento por delante.
void insertarDelante(struct lista **cabeza);

// Inserta el elemento pasado como argumento por detrás.
void insertarDetras(struct lista **cabeza);

// Devuelve el mayor y menor elemento de la lista.
void mayor_menor(int *maximo, int *minimo, struct lista *cabeza);

// Busca un elemento en la lista. Retorna 1 si lo encuentra y 0 en caso contrario.
int buscarElemento(struct lista *cabeza, int *n);

// Elimina el elemento seleccionado.
void borrarElemento(struct lista **cabeza, int *n);
