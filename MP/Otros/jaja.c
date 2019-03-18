#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int **m;
  int i, j;
  i = j = 1;

  m[i][j] = 1;
  int valor = m[i][j];

  printf("Valor i j: %d\n", valor);


  return 0;
}
