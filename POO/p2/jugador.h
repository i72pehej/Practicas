//jugador.h
//The code of class Jugador.

#ifndef JUGADOR_H
#define  JUGADOR_H

#include <string>
#include <list>
#include <iostream>
#include "persona.h"

class Apuestas {
private:
  int tipoApuesta;
  std::string valorApuesta;
  int cantidadApuesta;
};

class Jugador : public Persona {
private:
  int dinero_;
  std::string codigoJugador_;
  std::list<Apuestas> apuestas_;
public:
  inline Jugador(std::string dni, std::string codigoJugador, std::string nombre = "", std::string apellidos = "", int edad = 0, std::string direccion = "", std::string localidad = "", std::string provincia = "", std::string pais = "") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais) {codigoJugador_ = codigoJugador; dinero_ = 1000;}
  inline void setCodigo(std::string codigoJugador) {codigoJugador_ = codigoJugador;};
  inline void setDinero(int dinero) {dinero_ = dinero;};
  void setApuestas();

  inline int getDinero() const {return (dinero_);};
  inline std::string getCodigo() const {return (codigoJugador_);};
  inline std::list <Apuestas> getApuestas() const {return (apuestas_);};
};

#endif
