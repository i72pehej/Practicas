//GuardarCargarIdentificarAñadir.hpp
//Los prototipos para las funciones sobre la copia de seguridad y los profesores.

#include <string>
#include <fstream>
#include <list>

class Profesor{
  private:
    std::string nombreUsuario;
    bool esCoordinador;
//    bbdd;
  public:
    Profesor(std::string usuario);  //Constructor de la clase Profesor.
    inline bool getCoordinador() {return (esCoordinador);};  //Devuelve si el profesor es coordinador o no.
    bool identificar(std::string usuario, std::string password);  //Devuelve si el usuario introducido existe.
    bool mostrarAlumnos(int opcion, bool ascendente = false);  //Devuelve la lista de alumnos completa.
    bool guardarCopia(std::string ficheroCopia = "default");  //Guarda en un fichero binario la lista de alumnos.
    bool cargarCopia(std::string ficheroCopia = "default");  //Carga en la base de datos los alumnos desde un fichero binario.
};

class Coordinador : Profesor{
    Coordinador(std::string usuario);  //Constructor de la calse Coordinador.
    bool addProfesor(std::string usuario, std::string password);  //Añade un profesor ayudante.
};
