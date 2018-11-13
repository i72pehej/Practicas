//jugador.cc
//Methods of class Jugador.

#include "jugador.h"

void Jugador::setApuestas(){
  getApuestas().clear();

  std::string tipoFichero, cantidadFichero, valorFichero;
  Apuestas a;

  std::string nomFichero = getDNI() + ".txt";
  std::ifstream fichero;
  fichero.open(nomFichero.c_str()); //Usamos la función .c_str() para crear el nombre del fichero de forma correcta con '\n'

  while (!fichero.eof()) {
    std::getline(fichero, tipoFichero, ',');
    // Hacer CASTING de string a int.
    a.setTipoApuesta(tipoFichero);
    std::getline(fichero, valorFichero, ',');
    a.setValorApuesta(valorFichero));
    std::getline(fichero, cantidadFichero, '\n');
    // Hacer CASTING de string a int.
    a.setCantidadApuesta(cantidadFichero);

    apuestas_.push_back(a);
  }

/*
  while (std::getline(fichero, apuestaFichero, '\n')) { // Bucle while para leer los elementos del fichero.
    apuestas_.push_back(apuestaFichero); // Introduce cada elemento de uno en uno en la lista de apuestas.
  }
*/
  fichero.close();
}
