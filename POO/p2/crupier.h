// crupier.h
// The code of class crupier.

#ifndef CRUPIER_H
#define  CRUPIER_H

#include <string>
#include "persona.h"

class Crupier : public Persona {
private:
  std::string codigo_;
public:
  inline Crupier(std::string dni, std::string codigo, std::string nombre = "", std::string apellidos = "",
   int edad = 0, std::string direccion = "", std::string localidad = "", std::string provincia = "",
   std::string pais = "") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais)
   {codigo_ = codigo;}  // Constructor de la clase crupier.

  inline void setCodigo(std::string codigo) {codigo_ = codigo;};  // Asigna un código introducido.
  inline std::string getCodigo() const {return (codigo_);}; // Devuelve el código introducido.
};

#endif
