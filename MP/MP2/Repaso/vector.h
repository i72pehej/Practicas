#ifndef VECTOR_H

#include <stdlib.h>
#include <stdio.h>


// Reserva de memoria para el vector.
void reservaVector(int *tam, int *vec);

// Libera memoria del vector.
void liberaVector(int *vec);

// Imprime el vector.
void imprimeVector(int *tam, int *vec);

// Ordenación del vector.
void ordenaVector(int *tam, int *vec);


#define VECTOR_H
#endif
