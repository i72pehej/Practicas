//jugador.cc
//Methods of class Jugador.

#include "jugador.h"

using namespace std;

void Jugador::setApuestas(){
  getApuestas().clear();

  string tipoFichero, valorFichero, cantidadFichero;
  Apuesta a;

  string nomFichero = getDNI() + ".txt";
  ifstream fichero (nomFichero.c_str()); //Usamos la función .c_str() para crear el nombre del fichero de forma correcta con '\n'.

  if (fichero.is_open()) {
    while (!fichero.eof()) {
      getline(fichero, tipoFichero, ',');
      int tipo = stoi(tipoFichero.c_str());  //De string a int.
      a.setTipoApuesta(tipo);
//      a.tipo_ = tipo;

      getline(fichero, valorFichero, ',');
      a.setValorApuesta(valorFichero);
//      a.valor_ = valorFichero;

      getline(fichero, cantidadFichero, '\n');
      int cantidad = stoi(cantidadFichero.c_str());  //De string a int.
      a.setCantidadApuesta(cantidad);
//      a.cantidad_ = cantidad;

      apuestas_.push_back(a);
    }
    fichero.close();
  } else {
    cout << "El fichero de datos no se ha podido abrir correctamente." << '\n';
    exit(-1);
  }
}
