#include "ficheros.h"
#include "vector.h"


// -----------------------------------------------------------------------------

void compruebaFicheros(int nArgs, char nomBin[50], char nomTxt[50]) {
  // Control de argumentos.
  if (nArgs != 3) {
    printf("\n\n\tERROR. Argumentos no reconocidos.\n\n");
    exit(-1);
  }

  // Creación de ficheros.
  FILE *ficheroBinario;
  FILE *ficheroTexto;

  // Comprobación de la existencia de los ficheros.
  if ((ficheroBinario = fopen(/*nomBin*/"enteros.bin", "rb")) == NULL) {
    printf("\n\n\tERROR. Fichero binario no existente.\n\n");
    exit(-1);
  }
  if ((ficheroTexto = fopen(nomTxt, "r")) == NULL) {
    printf("\n\n\tERROR. Fichero de texto no existente.\n\n");
    printf("\tSe creará el fichero de texto con el nombre introducido.\n");
  }
  // Se cierran los ficheros abiertos.
  else {fclose(ficheroTexto);}

  fclose(ficheroBinario);
}

// -----------------------------------------------------------------------------

void leeFicheroBinario(int *n_registros, char nomBin[50], int *vec) {

  FILE *ficheroBinario;

  // Control de errores.
  if ((ficheroBinario = fopen(/*nomBin*/"enteros.bin", "rb")) == NULL) {
    printf("\n\n\tERROR. Imposible abrir el fichero binario.\n\n");
    exit(-1);
  }

  // Conteo de los registros del fichero binario.
  fseek(ficheroBinario, 0L, SEEK_END);
  *n_registros = ftell(ficheroBinario);
  *n_registros = *n_registros / sizeof(int);

  reservaVector(n_registros, vec);

  // Cerrar fichero.
  fclose(ficheroBinario);
  
  // Control de errores.
  if ((ficheroBinario = fopen(/*nomBin*/"enteros.bin", "rb")) == NULL) {
    printf("\n\n\tERROR. Imposible abrir el fichero binario.\n\n");
    exit(-1);
  }

  // Lectura desde el fichero binario hasta el vector.
  if ((fread(vec, *n_registros, sizeof(int), ficheroBinario)) <= 0) {
    printf("\n\n\tERROR. Imposible leer el fichero binario.\n\n");
    exit(-1);
  }

  // Cerrar fichero.
  fclose(ficheroBinario);
}

// -----------------------------------------------------------------------------

void cargaVectorFichero(int *tam, int *vec, char nomTxt[50]) {
  FILE *ficheroTexto;

  // Control de errores y apertura.
  if ((ficheroTexto = fopen(nomTxt, "w")) == NULL) {
    printf("\n\n\tERROR. Imposible abrir el fichero de texto.\n\n");
  }

  // Introducción del vector en el fichero de texto.
  for (size_t i = 0; i < *tam; i++) {
    fprintf(ficheroTexto, "%d\n", vec[i]);
  }

  // Cerrar fichero.
  fclose(ficheroTexto);
}

// -----------------------------------------------------------------------------
