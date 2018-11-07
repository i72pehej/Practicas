#include <stdio.h>
#include <math.h>
#include "funciones1.h"

int main(int argc, char const *argv[]) {

  float N = 0, resultado;
  int opcion = 0;
  float (*ptrFun)(int);

  printf("Introduzca el valor de N (valor máximo de 'x').\n");
  scanf("%f", &N);

  printf("Seleccione la función que desee evaluar (Pulse 0/1/2).");
  printf("Función [f(x) = 3*e^(x)-2x]-----------> '0'.\n");
  printf("Función [g(x) = -x*sin(x)+1.5]--------> '1'.\n");
  printf("Función [z(x) = x^(3)-2x+1]-----------> '2'.\n");
  scanf("%i", &opcion);

if (opcion == 0) {
  ptrFun = &funFX;
} else if (opcion == 1) {
  ptrFun = &funGX;
} else {
  ptrFun = &funZX;
}
/*
for (float x = 0; x <= N; x + 0.2) {
  resultado = (*ptrFun)(x);
  printf("Valor de 'x' para el valor <%f>: <%f>.\n", x, resultado);
}
*/
  return 0;
}
