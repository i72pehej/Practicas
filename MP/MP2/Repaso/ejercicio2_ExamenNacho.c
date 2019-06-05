#include <stdlib.h>
#include <stdio.h>

#include <time.h>

int main(int argc, char const *argv[]) {
  system("clear");

  srand(time(NULL));
  int Tam, *vec, aux;

  // Se pide el tamaño del vector.
  printf("\nIntroduzca el tamaño del vector: ");
  fscanf(stdin, "%d", &Tam);

  // Reserva de memoria.
  vec = (int *) malloc(Tam * sizeof(int));

  // Rellena el vector con valores aleatorios entre 0 y 999.
  for (size_t i = 0; i < Tam; i++) {
    vec[i] = (rand() % 1000);
  }

  // Imprime el vector por pantalla.
  printf("\n\tVector: ");
  for (size_t i = 0; i < Tam; i++) {
    printf("%d ", vec[i]);
  }
  printf("\n\n");

  // Ordenación menos eficiente posible: ORDENACIÓN BURBUJA.
  for (size_t i = 0; i < Tam; i++) {
    for (size_t j = 0; j < (Tam - i - 1); j++) {
      if (vec[j] > vec[j + 1]) {    //Cambiando el <> ordenas de mayor a menor o a la inversa.
        aux = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = aux;
      }
    }
  }

  // Imprime el vector por pantalla.
  printf("\n\tVector ordenado: ");
  for (size_t i = 0; i < Tam; i++) {
    printf("%d ", vec[i]);
  }
  printf("\n\n");

  // Libera memoria.
  free(vec);

  return 0;
}
