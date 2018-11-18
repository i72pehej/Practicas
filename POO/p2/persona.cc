//Persona.cc
//Methods of class Persona.

#include <iostream>
#include "persona.h"

Persona::Persona(std::string dni, std::string nombre = "", std::string apellidos = "", int edad = 0, std::string direccion = "", std::string localidad = "", std::string provincia = "", std::string pais = ""){
 DNI_ = dni;
 nombre_ = nombre;
 apellidos_ = apellidos;
 edad_ = edad;
 direccion_ = direccion;
 localidad_ = localidad;
 provincia_ = provincia;
 pais_ = pais;
}

Persona::Persona(std::string dni){
  DNI_ = dni;
  nombre_ = apellidos_ = direccion_ = localidad_ = provincia_ = pais_ = "";
  edad_ = 0;
}

bool Persona::setEdad(int edad){
  if (edad >= 0) {
    edad_ = edad;
    return true;
  }
  else{
    return false;
  }
}
