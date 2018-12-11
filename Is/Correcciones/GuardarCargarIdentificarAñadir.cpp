//GuardarCargarIdentificarAñadir.cpp
//Métodos de las funciones.

#include "GuardarCargarIdentificarAñadir.hpp"

bool Profesor::identificar(std::string usuario, std::string password){
  std::string nomFicheroCredenciales;
  std::ofstream credenciales(nomFicheroCredenciales.c_str(), std::ios::binary);  //Se abre el fichero de credenciales de los profesores.

  for (std::list <datosProfesor>::iterator iProfesor = profesores_.begin(); iProfesor != profesores_.end(); iProfesor++) {
    if ((iProfesor -> getUsuarioFichero() == usuario) && (iProfesor -> getPasswordFichero() == password)) {
      return true;
    }
  }
  credenciales.close();

  return false;
}

bool Profesor::guardarCopia(std::string fichero = "default"){

  for (std::list <Alumno>::iterator iAlumno = alumnos_.begin(); iAlumno != alumnos_.end(); iAlumno++) {
    /* code */
  }

}

bool Profesor::cargarCopia(std::string fichero = "default"){

  for (std::list <Alumno>::iterator iAlumno = alumnos_.begin(); iAlumno != alumnos_.end(); iAlumno++) {
    /* code */
  }

}

bool Coordinador::addProfesor(std::string usuario, std::string password){

}
