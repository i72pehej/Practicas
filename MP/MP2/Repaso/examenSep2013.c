#include "ficheros.h"
#include "vector.h"


int main(int argc, char const *argv[]) {
  char *nombreBinario, *nombreTexto;
  int tam, *vector = NULL;

  nombreBinario = argv[1];
  nombreTexto   = argv[2];
  compruebaFicheros(argc, nombreBinario, nombreTexto);

  leeFicheroBinario(&tam, nombreBinario, vector);
  imprimeVector(&tam, vector);

  ordenaVector(&tam, vector);
  imprimeVector(&tam, vector);

  cargaVectorFichero(&tam, vector, nombreTexto);

  liberaVector(vector);

  return 0;
}
