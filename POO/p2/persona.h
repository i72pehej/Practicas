//Class persona.h
//A class of type persona.

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona{
  private:
    std::string DNI_, nombre_, apellidos_, direccion_, localidad_, provincia_, pais_;
    int edad_;
  public:
    Persona(std::string dni, std::string nombre, std::string apellidos, int edad, std::string direccion, std::string localidad, std::string provincia, std::string pais);  // Constructor de la clase Persona.
    Persona(std::string dni);
    inline void setDNI(std::string dni) {DNI_ = dni;};  // Asigna valor a DNI.
    inline void setNombre(std::string nombre) {nombre_ = nombre;}; // Asigna valor a nombre.
    inline void setApellidos(std::string apellidos) {apellidos_ = apellidos;};  // Asigna valor a apellidos.
    bool setEdad(int edad); // Asigna valor a edad y comprueba si cumple la condición.
    inline void setDireccion(std::string direccion) {direccion_ = direccion;};  // Asigna valor a direccion.
    inline void setLocalidad(std::string localidad) {localidad_ = localidad;};  // Asigna valor a localidad.
    inline void setProvincia(std::string provincia) {provincia_ = provincia;};  // Asigna valor a provincia.
    inline void setPais(std::string pais) {pais_ = pais;}; // Asigna valor a pais.

    inline std::string getDNI() const {return DNI_;};  // Devuelve el valor de DNI.
    inline std::string getNombre() const {return nombre_;}; // Devuelve el valor de nombre.
    inline std::string getApellidos() const {return apellidos_;};  // Devuelve el valor de apellidos.
    inline int getEdad() const {return edad_;}; // Devuelve el valor de edad.
    inline std::string getDireccion() const {return direccion_;};  // Devuelve el valor de direccion.
    inline std::string getLocalidad() const {return localidad_;};  // Devuelve el valor de localidad.
    inline std::string getProvincia() const {return provincia_;}; // Devuelve el valor de provincia.
    inline std::string getPais() const {return pais_;}; // Devuelve el valor de pais.
    inline std::string getApellidosyNombre() const {return(apellidos_ + ',' + ' ' + nombre_);}; //Devuelve "apellidos, nombre" resultado de la concatenación.
    inline bool mayor() const {return(edad_ >= 18 ? true : false);};  //Devuelve si una persona es mayor de edad.
};

#endif
