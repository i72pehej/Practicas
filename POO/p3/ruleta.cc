//Ruleta.cc
//Methods of class Ruleta.

#include "ruleta.h"

bool Ruleta::setBanca(int banca){
    if (banca < 0) {
    return false;
  } else {
    setBanca(banca);
    return true;
  }
}

bool Ruleta::setBola(int bola){
  if (bola < 0 || bola > 36 ) {
    return false;
  } else {
    setBola(bola);
    return true;
  }
}

bool Ruleta::addJugador(Jugador j){
  for (std::list <Jugador>::iterator i = getJugadores().begin(); i != getJugadores().end(); i++) {
    if (i -> getDNI() == j.getDNI()) {  //Si el DNI del jugador que queremos añadir se encuentra en nuestra lista...
      return false;
    }
  }

  getJugadores().push_back(j);

  std::string nomFicheroNuevo = (j.getDNI() + ".txt");
  std::fstream ficheroNuevo (nomFicheroNuevo.c_str());

  ficheroNuevo.close();
  return true;
}

int Ruleta::deleteJugador(std::string dni){
  for (std::list <Jugador>::iterator i = getJugadores().begin(); i != getJugadores().end(); i++) {
    if (i -> getDNI() == dni) {
      getJugadores().erase(i);
      return 1;
    }
  }

  if (getJugadores().empty()) {
    return -1;
  }

  return -2;
}

int Ruleta::deleteJugador(Jugador j){
  return deleteJugador(j.getDNI());
}

void Ruleta::escribeJugadores(){
  std::ofstream ficheroNuevo ("jugadores.txt"); //Crea + Abre fichero en modo escritura.

  for (std::list <Jugador>::iterator i = getJugadores().begin(); i != getJugadores().end(); i++) {
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

void Ruleta::leeJugadores(){
  std::ifstream ficheroJugadores("jugadores.txt");
  getJugadores().clear();

  std::string cadAux; //Cadena auxuliar para introducir los datos leidos del fichero y después añadirlos a una variable jugadorAux.
  Jugador jugadorAux("dniAux", "cadAux"); //Variable para introducir cada dato de cadAux y después añadir a la lista de jugadores.

  while (!ficheroJugadores.eof()) {
    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setDNI(cadAux);

    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setCodigo(cadAux);

    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setNombre(cadAux);

    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setApellidos(cadAux);
/*
    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setEdad(atoi(cadAux.c_str());
*/
    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setDireccion(cadAux);

    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setLocalidad(cadAux);

    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setProvincia(cadAux);

    getline(ficheroJugadores, cadAux, ',');
    jugadorAux.setPais(cadAux);

    getline(ficheroJugadores, cadAux, '\n');
    jugadorAux.setDinero(atoi(cadAux.c_str()));

    getJugadores().push_back(jugadorAux);
  }

  ficheroJugadores.close();
}

void Ruleta::giraRuleta(){
  int giroBola = rand() % 37;

  setBola(giroBola);
}

void Ruleta::getPremios(){
  std::list<Apuesta> auxApuesta;

  for (std::list<Jugador>::iterator iJugador = getJugadores().begin(); iJugador != getJugadores().end(); iJugador++) {
    iJugador -> setApuestas();  //Carga las apuestas de cada jugador en la lista de apuestas.
    auxApuesta = iJugador -> getApuestas();

    for (std::list<Apuesta>::iterator iApuestas = auxApuesta.begin(); iApuestas != auxApuesta.end(); iApuestas++) {
      seleccionPremios(*iJugador, *iApuestas);
    }
  }
}

void Ruleta::seleccionPremios(Jugador &jugador, Apuesta apuesta){
  int opcion = apuesta.getTipoApuesta();

  switch (opcion){
    case 1:  //Apuesta sencilla.
    if(atoi(apuesta.getValorApuesta().c_str()) == getBola()){  //Si se acierta el número, se gana el 35:1 de lo que se apuesta.
      jugador.setDinero(jugador.getDinero() + (35 * apuesta.getCantidadApuesta()));  //Se le suma lo ganado al jugador.
      setBanca(getBanca() - (35 * apuesta.getCantidadApuesta()));  //Se le resta lo perdido a la banca.
    }
    else{ //En caso contrario, se pierde lo apostado y lo gana la banca.
      jugador.setDinero(jugador.getDinero() - (apuesta.getCantidadApuesta()));  //El jugador pierde el dinero.
      setBanca(getBanca() + (apuesta.getCantidadApuesta()));  //La banca lo gana.
    }
    break;

    case 2:  //Apuesta rojo o negro.
    if(getBola() == 0){  //Si sale cero se pierde lo apostado.
      jugador.setDinero(jugador.getDinero() - apuesta.getCantidadApuesta());
      setBanca(getBanca() + apuesta.getCantidadApuesta());
    }
    else{ //Si se acierta el color se gana el 1:1 de lo que se apuesta.
      if((apuesta.getValorApuesta() == "rojo" && ((getBola() % 2 + ((getBola() / 10) % 2)) % 2) == 0) ||
        (apuesta.getValorApuesta() == "negro" && ((getBola() % 2 + ((getBola() / 10) % 2)) % 2) == 1 )){  //Si el número de la  bola corresponde con el color de la apuesta.
        jugador.setDinero(jugador.getDinero() + apuesta.getCantidadApuesta());
        setBanca(getBanca() - apuesta.getCantidadApuesta());
      }
      else{ //Si no se acierta el color, se pierde lo apostado.
        jugador.setDinero(jugador.getDinero() - apuesta.getCantidadApuesta());
        setBanca(getBanca() + apuesta.getCantidadApuesta());
      }
    }
    break;

    case 3:  //Apuesta par o impar.
    if(getBola() == 0){  //Si sale cero se pierde lo apostado.
      jugador.setDinero(jugador.getDinero() - apuesta.getCantidadApuesta());
      setBanca(getBanca() + apuesta.getCantidadApuesta());
    }
    else{  //Se se acierta par/impar se gana 1:1 lo apostado.
      if((apuesta.getValorApuesta() == "par" && getBola() % 2 == 0) ||
        (apuesta.getValorApuesta() == "impar" && getBola() % 2 == 1)){  //Si el valor de la bola coincide con la apuesta.
        jugador.setDinero(jugador.getDinero() + apuesta.getCantidadApuesta());
        setBanca(getBanca() - apuesta.getCantidadApuesta());
      }
      else{  //Si no se acierta, se pierde lo apostado y lo gana la banca.
        jugador.setDinero(jugador.getDinero() - apuesta.getCantidadApuesta());
        setBanca(getBanca() + apuesta.getCantidadApuesta());
      }
    }
    break;

    case 4:  //Apuesta alto o bajo.
    if(getBola() == 0){  //Si sale cero se pierde lo apostado.
      jugador.setDinero(jugador.getDinero() - apuesta.getCantidadApuesta());
      setBanca(getBanca() + apuesta.getCantidadApuesta());
    }
    else{  //Si se acierta bajo/alto, se gana 1:1 lo apostado.
      if((apuesta.getValorApuesta() == "bajo" && (getBola() >= 1 && getBola() <= 18)) ||
        (apuesta.getValorApuesta() == "alto" && (getBola() >= 19 && getBola() <= 36))){  //Si el valor de la bola coincide con la apuesta.
        jugador.setDinero(jugador.getDinero() + apuesta.getCantidadApuesta());
        setBanca(getBanca() - apuesta.getCantidadApuesta());
    }
    else{  //Si no se acierta, se pierde lo apostado y lo gana la banca.
      jugador.setDinero(jugador.getDinero() - apuesta.getCantidadApuesta());
      setBanca(getBanca() + apuesta.getCantidadApuesta());
    }
  }
  break;

  default:
  exit(-1);
  }
}
