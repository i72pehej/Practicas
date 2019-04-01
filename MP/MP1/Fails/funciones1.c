#include <stdio.h>
#include <math.h>
#include "funciones1.h"
#define e 2,71828


float funFX(float x){
  printf("Se efecutará la función [f(x) = 3*e^(x)-2x].\n");
  float res = 3 * pow(e, x) - 2*x;

  return res;
}

float funGX(float x){
  printf("Se efecutará la función [g(x) = -x*sin(x)+1.5].\n");
  float res = (0 - x) * sin(x) + 1.5;

  return res;
}

float funZX(float x){
  printf("Se efecutará la función [z(x) = x^(3)-2x+1].\n");
  float res = pow(x, 3) - 2*x + 1;

  return res;
}
