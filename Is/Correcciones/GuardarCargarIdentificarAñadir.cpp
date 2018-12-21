//GuardarCargarIdentificarAñadir.cpp
//Métodos de las funciones.

#include "GuardarCargarIdentificarAñadir.hpp"

bool stringToBool(std::string str){
  if (str == "true" || str == "TRUE") {return true;}
  else {return false;}
}

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
  std::ofstream copiaSeguridad(fichero, std::ios::binary);

  for (std::list <Alumno>::iterator iAlumno = getListaAlumnos().begin(); iAlumno != getListaAlumnos().end(); iAlumno++) {
    copiaSeguridad << iAlumno.getDNI() + ',' << iAlumno.getNombre() + ',' << iAlumno.getApellidos() + ',' << iAlumno.getTelefono() + ','
      << iAlumno.getEmail() + ',' << iAlumno.getDireccion() + ',' << iAlumno.getCurso() + ',' << iAlumno.getFechaNacimiento() + ','
      << iAlumno.getGrupo() + ',' << iAlumno.getLider() + '\n';
  }
  copiaSeguridad.close();
}

bool Profesor::cargarCopia(std::string fichero){
  std::ifstream copiaSeguridad(fichero, std::ios::binary);
  std::string aux;

  for (std::list <Alumno>::iterator iAlumno = getListaAlumnos().begin(); iAlumno != getListaAlumnos().end(); iAlumno++) {
    getline(copiaSeguridad, aux, ',');
    iAlumno.setDNI(aux);

    getline(copiaSeguridad, aux, ',');
    iAlumno.setNombre(aux);

    getline(copiaSeguridad, aux, ',');
    iAlumno.setApellidos(aux);

    getline(copiaSeguridad, aux, ',');
    iAlumno.setTelefono(aux);

    getline(copiaSeguridad, aux, ',');
    iAlumno.setEmail(aux);

    getline(copiaSeguridad, aux, ',');
    iAlumno.setDireccion(aux);

    getline(copiaSeguridad, aux, ',');
    iAlumno.setCurso(atoi(aux));

    getline(copiaSeguridad, aux, ',');
    iAlumno.setFechaNacimiento(aux);

    getline(copiaSeguridad, aux, ',');
    iAlumno.setGrupo(atoi(aux));

    getline(copiaSeguridad, aux, '\n');
    iAlumno.setLider(stringToBool(aux));
  }
  copiaSeguridad.close();
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
