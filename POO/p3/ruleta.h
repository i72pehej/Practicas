//ruleta.h
//Definition of class Ruleta.

#ifndef RULETA_H
#define RULETA_H

#include <ctime>

#include "persona.h"
#include "crupier.h"
#include "jugador.h"

class Ruleta{
  private:
    int banca_, bola_;
    std::list <Jugador> jugadores_;
    Crupier crupier_;
  public:
    Ruleta(); //Constructor de la clase Ruleta.

    bool setBanca(int banca);  //Asigna el valor introducido a la banca.
    bool setBola(int bola); //Asigna el valor introducido a la bola.
    inline void setCrupier(Crupier c) {crupier_ = c;};  //Asigna el valor introducido a crupier.

    inline int getBanca() const {return banca_;};  //Devuelve el valor de la banca.
    inline int getBola() const {return bola_;};  //Devuelve el valor de la bola.
    inline Crupier getCrupier() const {return crupier_;};  //Devuelve la información de crupier.
    inline std::list <Jugador> getJugadores() const {return jugadores_;};  //Devuelve la información de los jugadores.

    bool addJugador(Jugador j); //Recibe un jugador como parámetro y añade el jugador al final de la lista de jugadores y crea un fichero tipo texto de apuestas vacío.
    int deleteJugador(std::string dni); //Borra de la lista de jugadores el jugador con el DNI introducido.
    int deleteJugador(Jugador j); //Borra de la lista de jugadores el jugador con mismo DNI que el del jugador recibido.
    void escribeJugadores();  //Escribe los datos de la lista de jugadores en un fichero texto denominado "jugadores.txt", borrando todo su contenido anterior.
    void leeJugadores();  //Lee los datos de los jugadores del fichero "jugadores.txt" y los mete en la lista de jugadores, borrándola antes de añadir los jugadores.

    void giraRuleta();  //Simula el giro de la ruleta y la obtención de un número aleatorio entre 0 y 36.
    void getPremios();  //Recorre la lista de jugadores y carga sus apuestas de los ficheros correspondientes, y actualiza el dinero de cada jugador y banca con lo ganado o perdido en cada apuesta.
};

#endif
