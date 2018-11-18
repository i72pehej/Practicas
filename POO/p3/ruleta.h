//ruleta.h
//Definition of class Ruleta.

#ifndef RULETA_H
#define RULETA_H

#include <list>
#include "crupier.h"
#include "jugador.h"

class Ruleta{
  private:
    int banca_, bola_;
    list <Jugador> jugadores_;
    Crupier crupier_;
  public:
    Ruleta();

    setBanca();
    setBola();

    getBanca();
    getBola();

};

#endif
