#include <stdio.h>


int minimo(int num1, int num2) {
  if (num1 < num2) {return num1;}
  else {return num2;}
}

void minimo_referencia(int num1, int num2, int *res) {
  if (num1 < num2) {*res = num1;}
  else {*res = num2;}
}

int main(int argc, char const *argv[]) {
  int num1, num2, *res;

  printf("\nHola, introduce el num1.\n");
  scanf("%d", &num1);
  printf("\nAhora, el num2.\n");
  scanf("%d", &num2);

  printf("\n\tLa función minimo: <%d>.\n", minimo(num1, num2));

  minimo_referencia(num1, num2, res);
  printf("\n\tLa función minimo_referencia: <%d>.\n", *res);

  printf("\n");
  return 0;
}
