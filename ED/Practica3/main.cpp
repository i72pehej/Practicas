#include <iostream>
#include <cstdlib> //para usar srand()
#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

#include "macros.hpp"

using namespace ed;


// Muestra el menú por pantalla.
void mostrarMenu();

// Insertar un número de personas, dado por el usuario, en el árbol.
void insertarPersonas(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);

// Comprobar si una persona está en el árbol dados sus datos.
void buscarPersonas(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);

// Mostrar todos los elementos del árbol usando los recorridos Preorden, PostOrden, InOrden.
void mostrarArbol(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);

// Borrar una persona dados sus datos.
void borrarPersonas(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);

// Borrar el árbol completo.
void borrarTodo(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);


int main() {
  srand(time(0));
  ArbolBinarioOrdenadoEnlazado<Persona> a;

  int opcion = -1;
  EscribirNodo<Persona> operador;

	do {
    // Se muestran las opciones a elegir.
    mostrarMenu();

		// Se elige la opción del menú.
  	std::cout << BIYELLOW;
  	std::cout << "\nOpción: ";
  	std::cout << RESET;
  	std::cin  >> opcion;

		std::cout << CLEAR_SCREEN;

		// Se ejecuta la opción del menú elegida.
		switch (opcion) {
      // Finaliza el programa.
			case 0:
				std::cout << BRED;
				std::cout << "\t[0] Fin del programa.\n" << '\n';
        std::cout << "\n\tSaliendo del programa . . .\n" << '\n';
				std::cout << RESET;
			break;

      // Insertar un número de personas, dado por el usuario, en el árbol.
			case 1:
			  std::cout << BIBLUE;
				std::cout << "\t[1] Test insertar." << '\n';
				std::cout << RESET;

        insertarPersonas(a);

			break;

      // Comprobar si una persona está en el árbol dados sus datos.
			case 2:
			  std::cout << BIBLUE;
				std::cout << "\t[2] Test buscar." << '\n';
				std::cout << RESET;

        buscarPersonas(a);

			break;

      // Mostrar todos los elementos del árbol usando los recorridos Preorden, PostOrden, InOrden.
      case 3:
			  std::cout << BIBLUE;
				std::cout << "\t[3] Test recorridos." << '\n';
				std::cout << RESET;

        mostrarArbol(a);

			break;

      // Borrar una persona dados sus datos.
      case 4:
			  std::cout << BIBLUE;
				std::cout << "\t[4] Test borrar elemento." << '\n';
				std::cout << RESET;

        borrarPersonas(a);

			break;

      // Borrar el árbol completo.
      case 5:
			  std::cout << BIBLUE;
				std::cout << "\t[5] Test borrar árbol." << '\n';
				std::cout << RESET;

        borrarTodo(a);

			break;

      // Opción por defecto en caso de no introducir ninguna de las anteriores.
			default:
				std::cout << BIRED;
				std::cout << "\tOpción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  std::cout << ONIRED;
				std::cout << opcion << '\n';
				std::cout << RESET;

        // Pausa
        std::cin.ignore();
    }


      if (opcion != 0) {
        std::cout << "\tPara mostrar el ";
        std::cout << BIGREEN ;
        std::cout << "menú, ";
        std::cout << RESET;
      	std::cout << "pulse ";
      	std::cout << INVERSE ;
      	std::cout << "ENTER";
      	std::cout << RESET;

      	// Pausa
      	std::cin.ignore();

        // Limpia la pantalla.
      	std::cout << CLEAR_SCREEN;
      }

  } while(opcion != 0);

  return 0;
}


// Muestra el menú por pantalla.
void mostrarMenu() {
  std::cout << CLEAR_SCREEN;

  std::cout << BIYELLOW;
  std::cout << "Seleccione una ";
  std::cout << UYELLOW;
  std::cout << "opción:" << '\n';
  std::cout << '\n';
  std::cout << RESET;

  std::cout << BICYAN;
  std::cout << "\t[1] ";
  std::cout << BIGREEN;
  std::cout << "Test insertar." << '\n';
  std::cout << RESET;

  std::cout << BICYAN;
  std::cout << "\t[2] ";
  std::cout << BIGREEN;
  std::cout << "Test buscar." << '\n';
  std::cout << RESET;

  std::cout << BICYAN;
  std::cout << "\t[3] ";
  std::cout << BIGREEN;
  std::cout << "Test recorridos." << '\n';
  std::cout << RESET;

  std::cout << BICYAN;
  std::cout << "\t[4] ";
  std::cout << BIGREEN;
  std::cout << "Test borrar elemento." << '\n';
  std::cout << RESET;

  std::cout << BICYAN;
  std::cout << "\t[5] ";
  std::cout << BIGREEN;
  std::cout << "Test borrar árbol." << '\n';
  std::cout << RESET;

  std::cout << BICYAN;
  std::cout << "\t[0] ";
  std::cout << BIRED;
  std::cout << "Fin del programa." << '\n';
  std::cout << RESET;
}

////////////////////////////////////////////////////////////////////////////////

// Insertar un número de personas, dado por el usuario, en el árbol.
void insertarPersonas(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a) {
  int nPersonas = 0;

  std::cout << "\nIntroduza el número de personas que deasea insertar:" << '\n';
  std::cin >> nPersonas;

  // Control de errores.
  while (nPersonas < 1) {
    std::cout << "\nPor favor, introduzca un número válido." << '\n';
    std::cin >> nPersonas;
  }

  // Se generan personas de forma "aleatoria", y se introducen en el árbol.
  for (int i = 0; i < nPersonas; i++) {
    if (not (a.insertar(generarDatosPersonales()))) {
      std::cout << "\nHa habido un error al insertar la persona nº <" << (i + 1) << ">." << '\n';
    }
  }
  std::cout << "\nTodas las personas deseadas introducidas correctamente." << '\n';

  // Pausa
  std::cin.ignore();
}

////////////////////////////////////////////////////////////////////////////////

// Comprobar si una persona está en el árbol dados sus datos.
void buscarPersonas(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a) {
  Persona persona;

  std::cout << "\nIntroduza la persona que desea buscar." << '\n';
  std::cout << "\n<NOMBRE> <APELLIDOS> <DNI>\n" << '\n';
  std::cin >> persona;

  if (a.buscar(persona)) {std::cout << "\nLa persona buscada se encuentra en el árbol.\n" << '\n';}
  else {std::cout << "\nLa persona que busca no se encuentra en el árbol.\n" << '\n';}

  // Pausa
  std::cin.ignore();
}

////////////////////////////////////////////////////////////////////////////////

// Mostrar todos los elementos del árbol usando los recorridos Preorden, PostOrden, InOrden.
void mostrarArbol(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a) {
  EscribirNodo<Persona> operador;

  std::cout << "\n\tRecorrido Pre-orden.\n" << '\n';
  a.recorridoPreOrden(operador);

  std::cout << "\n\tRecorrido In-orden.\n" << '\n';
  a.recorridoInOrden(operador);

  std::cout << "\n\tRecorrido Post-orden.\n" << '\n';
  a.recorridoPostOrden(operador);

  // Pausa
  std::cin.ignore();
}

////////////////////////////////////////////////////////////////////////////////

// Borrar una persona dados sus datos.
void borrarPersonas(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a) {
  Persona persona;

  std::cout << "\nIntroduza la persona que desea borrar." << '\n';
  std::cout << "\n<NOMBRE> <APELLIDOS> <DNI>\n" << '\n';
  std::cin >> persona;

  if (a.buscar(persona)) {
    std::cout << "\nLa persona buscada se encuentra en el árbol.\n" << '\n';
    std::cout << "\nBorrando persona . . .\n" << '\n';
    a.borrar();
  }
  else {
    std::cout << "\nLa persona que desea borrar no se encuentra en el árbol.\n" << '\n';
    std::cout << "\nImposible borrar.\n" << '\n';
  }

  // Pausa
  std::cin.ignore();
}

////////////////////////////////////////////////////////////////////////////////

// Borrar el árbol completo.
void borrarTodo(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a) {
  int confirmacion = 0;

  std::cout << BIYELLOW;
  std::cout << "\nSe procederá a borrar el árbol.";
  std::cout << UYELLOW;
  std::cout << "¿Desea continuar?\n" << '\n';
  std::cout << RESET;
  std::cout << BIRED;
  std::cout << "[0] Cancelar." << '\n';
  std::cout << BIGREEN;
  std::cout << "[1] Aceptar." << '\n';
  std::cout << BIYELLOW;
  std::cout << "\nOpción: ";
  std::cout << RESET;
  std::cin  >> confirmacion;

  if (confirmacion == 0) {
    std::cout << "\nCancelando borrado . . .\n" << '\n';
  }
  else if (confirmacion == 1) {
    std::cout << "\nBorrando árbol completo . . .\n" << '\n';
    a.borrarArbol();
    std::cout << "\nÁrbol borrado con";
    std::cout << BIGREEN;
    std::cout << "éxito.\n" << '\n';
    std::cout << RESET;
  }
  else {
    // Control de errores.
    while ((confirmacion != 0) && (confirmacion != 1)) {
      std::cout << "\nPor favor, seleccione una ";
      std::cout << UCYAN;
      std::cout << "opción válida." << '\n';
      std::cout << RESET;
      std::cout << BIYELLOW;
      std::cout << "\nOpción: ";
      std::cout << RESET;
      std::cin  >> confirmacion;
    }
  }
  std::cin.ignore();
}

////////////////////////////////////////////////////////////////////////////////
