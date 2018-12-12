//GuardarCargarIdentificarAñadir.cpp
//Métodos de las funciones.

#include "GuardarCargarIdentificarAñadir.hpp"

bool Profesor::identificar(std::string usuario, std::string password){
  std::ifstream credenciales("credenciales.bin", std::ios::binary);
  std::string nombreProfesor, contrProfesor;

  while (!credenciales.eof()) {
    getline(credenciales, nombreProfesor, ',');
    getline(credenciales, contrProfesor, '\n');

    if ((usuario == nombreProfesor) && (password == contrProfesor)) {
      return true;
    }
  }
  return false;
}

bool Profesor::guardarCopia(std::string fichero){
/*
  for (std::list <Alumno>::iterator iAlumno = alumnos_.begin(); iAlumno != alumnos_.end(); iAlumno++) {

  }
*/
}

bool Profesor::cargarCopia(std::string fichero){
/*
  for (std::list <Alumno>::iterator iAlumno = alumnos_.begin(); iAlumno != alumnos_.end(); iAlumno++) {

  }
*/
}

bool Coordinador::addProfesor(std::string usuario, std::string password){
  std::ifstream credenciales("credenciales.bin", std::ios::binary);
//Hcer un push_back() en el fichero para añadir el profesor con la ','.
}
