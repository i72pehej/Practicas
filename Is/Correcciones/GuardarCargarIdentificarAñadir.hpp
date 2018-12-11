//GuardarCargarIdentificarAñadir.hpp
//Los prototipos para las funciones sobre la copia de seguridad y los profesores.

#include <string>

class Profesor{
  private:
    std::string nombreUsuario;
    bool esCoordinador;
//    bbdd;
  public:
    Profesor(std::string usuario);  //Constructor de la clase Profesor.
    inline bool getCoordinador() const {return (esCoordinador)};  //Devuelve si el profesor es coordinador o no.
    bool identificar(std::string usuario, std::string contraseña);  //Devuelve si el usuario introducido existe.
    bool mostrarAlumnos(int opcion = 0, bool ascendente);  //Devuelve la lista de alumnos completa.
    bool guardarCopia(std::string fichero = "default");  //Guarda en un fichero binario la lista de alumnos.
    bool cargarCopia(std::fichero = "default");  //Carga en la base de datos los alumnos desde un fichero binario.
};

class Coordinador : Profesor{
  private:
  public:
    Coordinador(std::string usuario);  //Constructor de la calse Coordinador.
    bool addProfesor(std::string usuario, std::string contraseña);  //Añade un profesor ayudante.
};
