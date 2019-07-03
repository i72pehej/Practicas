#include "vector.h"


// -----------------------------------------------------------------------------

void reservaVector(int *tam, int *vec) {
  if ((vec = (int *) malloc(*tam * sizeof(int))) == NULL) {
    printf("\n\n\tERROR. Fallo al reservar memoria para el vector.\n\n");
  }
}

// -----------------------------------------------------------------------------

void liberaVector(int *vec) {
  free(vec);
}

// -----------------------------------------------------------------------------

void imprimeVector(int *tam, int *vec) {
  printf("\n\tVector: ");
  for (size_t i = 0; i < *tam; i++) {
    printf("%d  ", vec[i]);
  }
}

// -----------------------------------------------------------------------------

void ordenaVector(int *tam, int *vec) {
  int aux;

  for (size_t i = 0; i < *tam; i++) {
    for (size_t j = 0; j < (*tam - i - 1); j++) {
      if (vec[j] < vec[j + 1]) {
        aux = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = aux;
      }
    }
  }
}

// -----------------------------------------------------------------------------
