// dados.cc
// The list of methods of "Dados" class.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "dados_V2.h"

Dados::Dados(){ // El constructor inicia la semilla, y los dados a valor 1.
  srand(time(NULL));
  d1_ = d2_ = 1;
  contador1_ = contador2_ = 0;   // Los contadores también se inician a cero.
  suma1_ = suma2_ = 0;
  v1_.resize(5, 0);
  v2_.resize(5, 0);
}
// ----------------------------------------------------------------------------
void Dados::lanzamiento(){
  setDado1((rand() % 6) + 1);
  setDado2((rand() % 6) + 1);
}
// ----------------------------------------------------------------------------
bool Dados::setDado1(int num1){
  if ((num1 < 1) || (num1 > 6)) {
    return false;
  }
  contador1_++;
  d1_ = num1;
  suma1_ += getDado1();
  pushDado1(d1_);

  return true;
}
// ----------------------------------------------------------------------------
bool Dados::setDado2(int num2){
  if ((num2 < 1) || (num2 > 6)) {
    return false;
  }
  contador2_++;
  d2_ = num2;
  suma2_ += getDado2();
  pushDado2(d2_);

  return true;
}
// ----------------------------------------------------------------------------
void Dados::pushDado1(int valor){
  if (contador1_ > 1) {
    for (size_t i = 4; i > 0; i--) {
      v1_[i] = v1_[i - 1];
    }
    v1_[0] = valor;
  }
  v1_[0] = valor;
}

void Dados::pushDado2(int valor){
  if (contador2_ > 1) {
    for (size_t i = 4; i > 0; i--) {
      v2_[i] = v2_[i - 1];
    }
    v2_[0] = valor;
  }
  v2_[0] = valor;
}
// ----------------------------------------------------------------------------
