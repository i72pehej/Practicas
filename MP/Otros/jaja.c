#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  float **tabla;// = {{1, 2, 3}, {4, 5, 6}};

//  printf("Valores de tabla: %p, (tabla+1): %p, *(tabla+1): %p, (*(tabla+1)+1): %p, (*(tabla)+1): %p.\n", (void*)tabla, (void*)(tabla+1), (void*)*(tabla+1), (void*)(*(tabla+1)+1), (void*)(*(tabla)+1));
  printf("Valores de *(*(tabla+1)+1): %f, *(*(tabla)+1): %f, *(*(tabla+1)): %f.\n", *(*(tabla+1)+1), *(*(tabla)+1), *(*(tabla+1)));

  return 0;
}
