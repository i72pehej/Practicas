//jugador.cc
//Methods of class Jugador.

#include "jugador.h"

void Jugador::setApuestas(){
  getApuestas().clear();

  std::string nomFichero = getDNI() + ".txt";

  std::ifstream fichero(nomFichero);



  fichero.close();
}









int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
