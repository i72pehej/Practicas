// dados.cc
// The list of methods of "Dados" class.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dados.h"

Dados::Dados(){ // El constructor inicia la semilla, y los dados a valor 1.
  srand(time(NULL));
  d1_ = d2_ = 1;
  contador1 = contador2 = 0;   // Los contadores también se inician a cero.
  suma1 = suma2 = 0;
  for (size_t i = 0; i < 5; i++) {  // Inicializamos los vectores a cero.
    v1[i] = v2[i] = 0;
  }
}
// ----------------------------------------------------------------------------
void Dados::lanzamiento(){
  contador1++;
  contador2++;

  d1_ = (rand() % 6) + 1;
  d2_ = (rand() % 6) + 1;

  suma1 += d1_;
  suma2 += d2_;

  if (contador1 > 1) {
    v1[4] = v1[3];
    v1[3] = v1[2];
    v1[2] = v1[1];
    v1[1] = v1[0];
    v1[0] = d1_;
  }else{
    v1[0] = d1_;
  }
  if (contador2 > 1) {
    v2[4] = v2[3];
    v2[3] = v2[2];
    v2[2] = v2[1];
    v2[1] = v2[0];
    v2[0] = d2_;
  }else{
    v2[0] = d2_;
  }
}
// ----------------------------------------------------------------------------
int Dados::getDado1(){
  return (d1_);
}
// ----------------------------------------------------------------------------
int Dados::getDado2(){
  return (d2_);
}
// ----------------------------------------------------------------------------
bool Dados::setDado1(int num1){
  if ((num1 < 1) || (num1 > 6)) {
    return false;
  }
  else{
    d1_ = num1;
    suma1 += getDado1();
    contador1++;

    if (contador1 > 1) {
      v1[4] = v1[3];
      v1[3] = v1[2];
      v1[2] = v1[1];
      v1[1] = v1[0];
      v1[0] = d1_;
    }else{
      v1[0] = d1_;
    }

    return true;
  }
}
// ----------------------------------------------------------------------------
bool Dados::setDado2(int num2){
  if ((num2 < 1) || (num2 > 6)) {
    return false;
  }
  else{
    contador2++;
    d2_ = num2;
    suma2 += getDado2();

    if (contador2 > 1) {
      v2[4] = v2[3];
      v2[3] = v2[2];
      v2[2] = v2[1];
      v2[1] = v2[0];
      v2[0] = d2_;
    }else{
      v2[0] = d2_;
    }

    return true;
  }
}
// ----------------------------------------------------------------------------
int Dados::getSuma(){
  return (getDado1() + getDado2());
}
// ----------------------------------------------------------------------------
int Dados::getDiferencia(){
  if (d1_ > d2_) {
    return (d1_ - d2_);
  }
  if (d1_ < d2_) {
    return (d2_ - d1_);
  }
  else{
    return (d2_ - d1_);
  }
}
// ----------------------------------------------------------------------------
int Dados::getLanzamientos1(){
  return contador1;
}

int Dados::getLanzamientos2(){
  return contador2;
}
// ----------------------------------------------------------------------------
float Dados::getMedia1(){
  if (contador1 == 0) {
    return contador1;
  }
  else{
    return (suma1 / contador1);
  }
}

float Dados::getMedia2(){
  if (contador2 == 0) {
    return contador2;
  }
  else{
    return (suma2 / contador2);
  }
}
// ----------------------------------------------------------------------------
void Dados::getUltimos1(int vec1[5]){
  for (size_t i = 0; i < 5; i++) {
    vec1[i] = v1[i];
  }
}

void Dados::getUltimos2(int vec2[5]){
  for (size_t i = 0; i < 5; i++) {
    vec2[i] = v2[i];
  }
}
// ----------------------------------------------------------------------------
