//jugador.h
//The code of class Jugador.

#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include "persona.h"

/*
// Para solucionar parte de los conflictos con el último test.
struct Apuesta{
	int tipo;
	std::string valor;
	int cantidad;
};
*/

class Apuesta {
private:
  int tipo_;
  std::string valor_;
  int cantidad_;
public:
  inline void setTipoApuesta(int t) {tipo_ = t;};
  inline void setValorApuesta(std::string v) {valor_ = v;};
  inline void setCantidadApuesta(int c) {cantidad_ = c;};

	inline int getTipoApuesta() const {return (tipo_);}; // Devuelve el tipo de apuesta introducido.
	inline std::string getValorApuesta() const {return (valor_);}; // Devuelve el valor de la apuesta introducido.
	inline int getCantidadApuesta() const {return (cantidad_);}; // Devuelve la cantidad de la apuesta introducida.
};

class Jugador : public Persona {
private:
  int dinero_;
  std::string codigoJugador_;
  std::list <Apuesta> apuestas_;
public:
  inline Jugador(std::string dni, std::string codigoJugador, std::string nombre = "",
    std::string apellidos = "", int edad = 0, std::string direccion = "", std::string localidad = "",
    std::string provincia = "", std::string pais = "") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais)
    {codigoJugador_ = codigoJugador; dinero_ = 1000;}; // Constructor de la clase Jugador.

  inline void setCodigo(std::string codigoJugador) {codigoJugador_ = codigoJugador;}; // Asigna el código.
  inline void setDinero(int dinero) {dinero_ = dinero;};  // Asigna el dinero jugado.
  void setApuestas(); // Borra las apuestas actuales y asigna las apuestas recogidas en un fichero.

  inline int getDinero() const {return (dinero_);}; // Devuelve el dinero introducido.
  inline std::string getCodigo() const {return (codigoJugador_);};  // Devuelve el código del jugador.
  inline std::list <Apuesta> getApuestas() const {return (apuestas_);};  // Devuelve las Apuesta leídas.
};

#endif
