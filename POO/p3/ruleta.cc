//Ruleta.cc
//Methods of class Ruleta.

#include "ruleta.h"

bool Ruleta::setBanca(int banca){
    if (banca < 0) {
    return false;
  } else {
    banca_ = banca;
    return true;
  }
}

bool Ruleta::setBola(int bola){
  if (bola < 0 || bola > 36 ) {
    return false;
  } else {
    bola_ = bola;
    return true;
  }
}

bool Ruleta::addJugador(Jugador j){
  for (std::list <Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++) {
    if (i -> getDNI() == j.getDNI()) {  //Si el DNI del jugador que queremos añadir se encuentra en nuestra lista...
      return false;
    }
  }

  jugadores_.push_back(j);

  std::string nomFicheroNuevo = (j.getDNI() + ".txt");
  std::fstream ficheroNuevo (nomFicheroNuevo.c_str());

  ficheroNuevo.close();
  return true;
}

int deleteJugador(std::string dni){

}

int deleteJugador(Jugador j){
  return deleteJugador(j.getDNI());
}
