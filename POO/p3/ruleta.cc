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

void Ruleta::leeJugadores(){
  std::ifstream ficheroJugadores("jugadores.txt");
  jugadores_.clear();

  std::string cadAux; //Cadena auxuliar para introducir los datos leidos del fichero y después añadirlos a una variable jugadorAux.
  Jugador jugadorAux("dniAux", "codAux"); //Variable para introducir cada dato de cadAux y después añadir a la lista de jugadores.

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

    jugadores_.push_back(jugadorAux);
  }

  ficheroJugadores.close();
}

void Ruleta::giraRuleta(){
  int giroBola = rand() % 37;

  setBola(giroBola);
}

void Ruleta::getPremios(){
//  std::list <Apuesta> auxApuesta;
  int opcion;

  for (std::list <Jugador>::iterator iJugador = jugadores_.begin(); iJugador != jugadores_.end(); iJugador++) {
    iJugador -> setApuestas();  //Carga las apuestas de cada jugador en la lista de apuestas.
//    auxApuesta = iJugador -> getApuestas();  //Lista auxiliar para trabajar con las apuestas.

    for (std::list <Apuesta>::iterator iApuestas = auxApuesta.begin(); iApuestas != auxApuesta.end(); iApuestas++) {
      opcion = apuestas_.getTipoApuesta();

      switch (opcion){

        case 1:  //Apuesta sencilla.
        if(atoi(apuestas_.getValorApuesta().c_str()) == getBola()){  //Si se acierta el número, se gana el 35:1 de lo que se apuesta.
          iJugador.setDinero(iJugador.getDinero() + (35 * apuestas_.getCantidadApuesta()));  //Se le suma lo ganado al jugador.
          setBanca(getBanca() - (35 * apuestas_.getCantidadApuesta()));  //Se le resta lo perdido a la banca.
        }
        else{ //En caso contrario, se pierde lo apostado y lo gana la banca.
          iJugador.setDinero(iJugador.getDinero() - (apuestas_.getCantidadApuesta()));  //El jugador pierde el dinero.
          setBanca(getBanca() + (apuestas_.getCantidadApuesta()));  //La banca lo gana.
        }
        break;

        case 2:  //Apuesta rojo o negro.
        if(getBola() == 0){  //Si sale el cero lo pierdes todo lo que hayas apostado

    			j.setDinero(j.getDinero()-a.cantidad);
    			setBanca(getBanca()+a.cantidad);
    		}
    			else{ //pero si no sale y aciertas color ganas 2.0 de lo que apuestes
    				if((a.valor=="negro" && ((getBola()%2 + ((getBola()/10)%2))%2)==1 )||(a.valor=="rojo"  && ((getBola()%2 + ((getBola()/10)%2))%2)==0)){

    					j.setDinero(j.getDinero()+a.cantidad);
    					setBanca(getBanca()-a.cantidad);
    				}

    				else{ //y si no aciertas color pierdes lo apostado

    					j.setDinero(j.getDinero()-a.cantidad);
    					setBanca(getBanca()+a.cantidad);
    				}
    			}
    		break;

    		case 3:	if(getBola()==0){//si la bola sale cero pierdes lo apostado

    			j.setDinero(j.getDinero()-a.cantidad);
    			setBanca(getBanca()+a.cantidad);
    		}

    				else{ //y si no sale cero y aciertas par/impar ganas 2.0 y la banca lo pierde
    					if((a.valor=="par" && getBola()%2==0) || (a.valor =="impar" && getBola()%2==1)){

    					j.setDinero(j.getDinero()+a.cantidad);
    					setBanca(getBanca()-a.cantidad);
    					}
    					else{//y si no aciertas pierdes lo apostado

    						j.setDinero(j.getDinero()-a.cantidad);
    						setBanca(getBanca()+a.cantidad);
    					}
    				}
    		break;


    		case 4: if(getBola()==0){//si la bola sale 0 pierdes lo apostado

    			j.setDinero(j.getDinero()-a.cantidad);
    			setBanca(getBanca()+a.cantidad);
    		}
    		else{//y si no y aciertas si es bajo o alto ganas 2.0 de tus apuestas
    			if((a.valor=="bajo" && (getBola()>=1 && getBola()<=18)) || ((a.valor=="alto" && (getBola()>=19 && getBola()<=36)))){

    			j.setDinero(j.getDinero()+a.cantidad);
    			setBanca(getBanca()-a.cantidad);
        }
          else{//pero si no aciertas pierdes lo apostado y lo gana la banca
            j.setDinero(j.getDinero()-a.cantidad);
            setBanca(getBanca()+a.cantidad);
          }
        }
        break;

      default:
      exit(-1);
      }
    }
  }
}
