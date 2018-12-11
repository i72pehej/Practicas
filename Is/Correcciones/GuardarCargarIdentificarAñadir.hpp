//GuardarCargarIdentificarAñadir.hpp
//Los prototipos para las funciones sobre la copia de seguridad y los profesores.

#include <string>

class Profesor{
  private:
    std::string nombreUsuario;
    bool esCoordinador;
//    bbdd;
  public:
    bool getCoordinador();  //Devuelve el nombre del coordinador que lo ha creado.
    bool identificar(std::string usuario, std::string contraseña);  //Devuelve si el usuario introducido existe.
    bool mostrarAlumnos(int opcion = 0, bool ascendente);  //Devuelve la lista de alumnos completa.
    bool guardarCopia(std::string fichero = "default");  //Guarda en un fichero binario la lista de alumnos.
    bool cargarCopia(std::fichero = "default");  //Carga en la base de datos los alumnos desde un fichero binario.
};

class Coordinador : Profesor{
  private:
  public:
    bool anadirProfesor(std::string usuario, std::string contraseña);  //Añade un profesor ayudante.
};
