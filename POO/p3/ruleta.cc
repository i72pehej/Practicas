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

int Ruleta::deleteJugador(std::string dni){
  for (std::list <Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++) {
    if (i -> getDNI() == dni) {
      jugadores_.erase(i);
      return 1;
    }
  }

  if (jugadores_.empty()) {
    return -1;
  }

  return -2;
}

int Ruleta::deleteJugador(Jugador j){
  return deleteJugador(j.getDNI());
}

void Ruleta::escribeJugadores(){
  std::ofstream ficheroNuevo ("jugadores.txt"); //Crea + Abre fichero en modo escritura.

  for (std::list <Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++) {
    ficheroNuevo << i -> getDNI() + ",";
    ficheroNuevo << i -> getCodigo() + ",";
    ficheroNuevo << i -> getNombre() + ",";
    ficheroNuevo << i -> getApellidos() + ",";
    ficheroNuevo << i -> getDireccion() + ",";
    ficheroNuevo << i -> getLocalidad() + ",";
    ficheroNuevo << i -> getProvincia() + ",";
    ficheroNuevo << i -> getPais() + ",";
    ficheroNuevo << i -> getDinero() << std::endl;
  }

  ficheroNuevo.close();
}
