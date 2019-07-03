#ifndef FICHEROS_H

#include <stdlib.h>
#include <stdio.h>

// Comprueba la existencia de los ficheros.
void compruebaFicheros(int nArgs, char nomBin[50], char nomTxt[50]);

// Lee el fichero binario e introduce los valores en el vector.
void leeFicheroBinario(int *n_registros, char nomBin[50], int *vec);

// Introduce el vector con los valores en un fichero de texto.
void cargaVectorFichero(int *tam, int *vec, char nomTxt[50]);


#define FICHEROS_H
#endif
