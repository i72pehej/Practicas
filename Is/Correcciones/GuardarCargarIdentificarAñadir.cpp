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
  credenciales.close();
  return false;
}

bool Profesor::guardarCopia(std::string fichero){
  std::ofstream ficheroAlumnos(fichero, std::ios::binary);

  for (std::list <Alumno>::iterator iAlumno = alumnos_.begin(); iAlumno != alumnos_.end(); iAlumno++) {
    ficheroAlumnos << iAlumno.getDNI() + ',' << iAlumno.getNombre() + ',' << iAlumno.getApellidos() + ',' << iAlumno.getTelefono() + ','
      << iAlumno.getEmail() + ',' << iAlumno.getDireccion() + ',' << iAlumno.getCurso() + ',' << iAlumno.getFechaNacimiento() + ','
      << iAlumno.getGrupo() + ',' << iAlumno.getLider() + '\n';
  }
  ficheroAlumnos.close();
}

bool Profesor::cargarCopia(std::string fichero){
/*
  for (std::list <Alumno>::iterator iAlumno = alumnos_.begin(); iAlumno != alumnos_.end(); iAlumno++) {

  }
*/
}

bool Coordinador::addProfesor(std::string usuario, std::string password){
  if(identificar(usuario, password) == true){
    return false;
  }
  std::ofstream credenciales("credenciales.bin", std::ios::binary);
  credenciales << usuario + ", " + password;

  credenciales.close();
  return true;
}
