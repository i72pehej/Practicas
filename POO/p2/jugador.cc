//jugador.cc
//Methods of class Jugador.

#include "jugador.h"

void Jugador::setApuestas(){
  getApuestas().clear();

  std::string apuestaFichero;
  std::string nomFichero = getDNI() + ".txt";
  std::ifstream fichero(nomFichero);

  while (std::getline(fichero, apuestaFichero, '\n')) { // Bucle while para leer los elementos del fichero.
    apuestas_.push_back(apuestaFichero); // Introduce cada elemento de uno en uno en la lista de apuestas.
  }

  fichero.close();
}
