// juego.cc
// A program that simulates a game with two dices.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "dados_V2.h"

int main(int argc, char const *argv[]) {
  Dados d;
  int num1, num2;
  std::vector<int> vec1, vec2;
  vec1.resize(5, 0);
  vec2.resize(5, 0);
// ----------------------------------------------------------------------------
  d.lanzamiento();
  std::cout << "\nEl valor del primer dado es: " << d.getDado1() << ".\n";
  std::cout << "\nEl valor del segundo dado es: " << d.getDado2() << ".\n";
// ----------------------------------------------------------------------------
  std::cout << "\nIntroduzca un valor para el primer dado." << '\n';
  std::cin >> num1;
  std::cout << "\nIntroduzca un valor para el segundo dado." << '\n';
  std::cin >> num2;
// ----------------------------------------------------------------------------
  if ((d.setDado1(num1)) == true) {
    std::cout << "\nEl número <" << num1 << "> se ha asignado al primer dado." << '\n';
  }
  else{
    std::cout << "ERROR. Dado 1 no asignado." << '\n';
  }
  if ((d.setDado2(num2)) == true) {
    std::cout << "\nEl número <" << num2 << "> se ha asignado al segundo dado." << '\n';
  }
  else{
    std::cout << "ERROR. Dado 2 no asignado." << '\n';
  }
// ----------------------------------------------------------------------------
  std::cout << "\nLa suma de los dados es: " << d.getSuma() << ".\n";
// ----------------------------------------------------------------------------
  std::cout << "\nLa diferencia entre los valores de los dados es: " << d.getDiferencia() <<".\n\n";
// ----------------------------------------------------------------------------
  std::cout << "El número de lanzamientos realizados para el primer dado es: " << d.getLanzamientos1() << ".\n\n";
  std::cout << "El número de lanzamientos realizados para el segundo dado es: " << d.getLanzamientos2() << ".\n\n";
// ----------------------------------------------------------------------------
  std::cout << "La media de los valores del primer dado es: " << d.getMedia1() << ".\n\n";
  std::cout << "La media de los valores del segundo dado es: " << d.getMedia2() << ".\n\n";
// ----------------------------------------------------------------------------
  d.getUltimos1(vec1);
  d.getUltimos2(vec2);
// ----------------------------------------------------------------------------
  return 0;
}
