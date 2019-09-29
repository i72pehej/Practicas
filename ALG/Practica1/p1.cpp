/*!a pesar de que se puede trabajar con nanosegundos, se devuelven los tiempos en microsegundos*/

// http://man7.org/linux/man-pages/man2/clock_gettime.2.html
/*
Data Type: struct timespec

    The struct timespec structure represents an elapsed time. It is declared in sys/time.h and has the following members:

    time_t tv_sec
       This represents the number of whole seconds of elapsed time.
    long  tv_nsec
    This is the rest of the elapsed time (a fraction of a second), represented as the number of nanoseconds.
*/

// Ojo hay que compilar g++ -Wall main.cpp -lrt para incluir las librerías de tiempos.


#include <cassert>
#include <ctime>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>  // Para usar memset
#include <stdint.h> // Para usar uint64_t
#include <vector>   // Para usar vectores
#include <fstream>  // Para ficheros


#define MAX 10000

////////////////////////////////////////////////////////////////////////////////

/*!\brief Models a clock to measure performace.*/
  class Clock {
    private:
      timespec _start;
      timespec _stop;
      bool _isStarted;

////////////////////////////////////////////////////////////////////////////////


    public:
      Clock () {
        memset(&_start, 0, sizeof(timespec));
        memset(&_stop, 0, sizeof(timespec));
        _isStarted = false;
      }

////////////////////////////////////////////////////////////////////////////////

      /*!\brief Starts the clock.
      * \pre not isStarted()
      * \post isStarted()
      */
      void start() {
        assert(!isStarted());
        clock_gettime (CLOCK_REALTIME, &_start);
        _isStarted = true;
      }

////////////////////////////////////////////////////////////////////////////////

      /*!\brief Re-starts the clock.
      * \post isStarted()
      */
      void restart() {
        clock_gettime (CLOCK_REALTIME, &_start);
        _isStarted = true;
      }

////////////////////////////////////////////////////////////////////////////////

      /*!\brief Stops the clock.
      * \pre isStarted()
      * \post not isStarted()
      */
      void stop() {
        assert(_isStarted);
        clock_gettime(CLOCK_REALTIME, &_stop);
        _isStarted = false;
      }

////////////////////////////////////////////////////////////////////////////////

      /*!\brief Is the clock started?
      * \return true if the clock is started currently.
      */
      bool isStarted() const {
        return _isStarted;
      }

////////////////////////////////////////////////////////////////////////////////

      /*!\brief Return the elapsed time in mcs.*/
      uint64_t elapsed() const {
        assert(!_isStarted);
        uint64_t startT = (uint64_t)_start.tv_sec * 1000000LL + (uint64_t)_start.tv_nsec / 1000LL;
        uint64_t stopT = (uint64_t)_stop.tv_sec * 1000000LL + (uint64_t)_stop.tv_nsec / 1000LL;
        return stopT-startT;
      }
  };

////////////////////////////////////////////////////////////////////////////////

  // Función para mostrar el vector por pantalla
  void imprimeVector(std::vector<int> &vector) {
    std::cout << "\nVector:" << '\n';
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
      std::cout <<" / "<< *it;
    }
    std::cout << " /\n";
  }

////////////////////////////////////////////////////////////////////////////////

  // Función para mostrar el vector de tiempos por pantalla
  void imprimeVectorTiempos(std::vector<double> &vector) {
    std::cout << "\nVector de tiempos:" << '\n';
    for (std::vector<double>::iterator it = vector.begin(); it != vector.end(); it++) {
      std::cout <<" / "<< *it;
    }
    std::cout << " /\n";
  }

////////////////////////////////////////////////////////////////////////////////

// Funcion para relenar el vector con valores aleaorios de 0 a 9999
void rellenaVector(std::vector<int> &vec) {
  // Se rellena el vector
  for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++) {
    *i = rand() % MAX;
  }
}

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
                              // QUICKSORT
////////////////////////////////////////////////////////////////////////////////

// Función para dividir el array y hacer los intercambios
int divide(std::vector<int> &array, int start, int end) {
  int left;
  int right;
  int pivot;
  int temp;

  pivot = array[start];
  left = start;
  right = end;

  // Mientras no se cruzen los índices
  while (left < right) {
    while (array[right] > pivot) {right--;}

    while ((left < right) && (array[left] <= pivot)) {left++;}

    // Si todavía no se cruzan los indices seguimos intercambiando
    if (left < right) {
      temp = array[left];
      array[left] = array[right];
      array[right] = temp;
    }
  }

  // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
  temp = array[right];
  array[right] = array[start];
  array[start] = temp;

  // La nueva posición del pivot
  return right;
}

// Función recursiva para hacer el ordenamiento
void quicksort(std::vector<int> &array, int start, int end) {
  int pivot;

  if (start < end) {
    pivot = divide(array, start, end);

    // Ordeno la lista de los menores
    quicksort(array, start, pivot - 1);

    // Ordeno la lista de los mayores
    quicksort(array, pivot + 1, end);
  }
}

////////////////////////////////////////////////////////////////////////////////

  // Función que comprueba que la ordenación se ha realizado correctamente
  bool estaOrdenado(const std::vector<int> &v) {
    for (size_t i = 0; i < (v.size() - 1); i++) {
      // Comprobación de errores
      #ifndef NDEBUG
        assert(v[i]  <= (v[i + 1]));
      #endif

      // Comprobación de errores en caso de eliminar asertos.
      if (v[i]  > (v[i + 1])) {return false;}
    }

    return true;
  }

////////////////////////////////////////////////////////////////////////////////

  // Se almacenan en un fichero de texto los valores de N y Tiempos correspondientes
  void guardaEnFichero(double times, int nEle) {
    // Abre el fichero para añadir al final
    std::ofstream ficheroTiempos("tiempos.txt", std::ios::app);

    if (ficheroTiempos.is_open()) {ficheroTiempos << times << "\t----\t" << nEle << '\n';}
    else {std::cout << "\n\nERROR al abrir el fichero." << '\n';}

    ficheroTiempos.close();
  }

////////////////////////////////////////////////////////////////////////////////
  // Elimina cualquier fichero coincidente
  void eliminaFichero() {
    if (std::remove("tiempos.txt") == 0) {
      std::cout << "Fichero <'tiempos.txt'> existente.\nEliminando . . ." << '\n';
    }
  }

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

  void realizarExperimento(std::vector<int> &vector, int minimo, int maximo, int incremento, int repeticiones) {
    Clock time;
    // Comienza a contar el contador
    time.start();

    float suma = 0;
    float contador = 0;

    std::vector<double> tiempos;

    // Bucle para realizar las pruebas.
    while (minimo <= maximo) {
      // Reasignación del tamaño del vector.
      vector.resize(minimo);
      rellenaVector(vector);


      std::cout << "---------------------------------------------------------" << "\n\n";
      for (int i = 0; i < repeticiones; i++) {
        // Reinicia el cronómetro
        time.restart();

        // Se ordena el vector.
        quicksort(vector, 0, minimo - 1);

        // Se detiene el cronómetro.
        if (time.isStarted()) {
          time.stop();
          std::cout << "\tHan pasado " << time.elapsed() << " microsegundos.\n";

          // Suma acumulada de los tiempos.
          suma += time.elapsed();
          contador++;
        }
      }

      // Valores de las variables de la media
      std::cout << "\nSuma = " << suma << "\nN = " << contador << "\nElementos = " << minimo << '\n';
      std::cout << "\nLa media de los tiempos es: " << suma / contador << " microsegundos\n\n";

      // Guardado de los valores en un vector
      tiempos.push_back(suma / contador);
      imprimeVectorTiempos(tiempos);

      // Reinicio de las variables para calcular la media
      suma = 0;
      contador = 0;

      // Se visualiza el vector por pantalla.
      imprimeVector(vector);

      // Comprueba que el vector esté ordenado
      if (estaOrdenado(vector) == false) {std::cout << "\n\tEl vector NO está ordenado." << '\n';}
      else {std::cout << "\n\nEl vector está ordenado." << "\n\n";}

      // Almacenar numero de elementos y tiempo medio en un fichero de texto
      guardaEnFichero(tiempos.back(), minimo);

      // Incremento del tamaño del vector.
      minimo += incremento;
    }
  }











int main() {
  system("clear");

  int min;  // Número mínimo de elementos del vector.
  int max;  // Número máximo de elementos del vector.
  int incremento; // Número por el que se incrementará el tamaño del vector.
  int repeticiones; // Número de repeticiones por cada tamaño del vector.
  // int tam;  // Tamaño del vector.

  // int tam;  // Tamaño del vector. Introducido por el usuario.
  // std::cout << "Introduzca la capacidad del vector: ";
  // std::cin >> tam;
  // std::cout << '\n';


  std::cout << "Introduzca el mínimo número de elementos del vector: ";
  std::cin >> min;
  std::cout << '\n';

  std::cout << "Introduzca el número máximo de elementos del vector: ";
  std::cin >> max;
  std::cout << '\n';

  while (min > max) {
    std::cout << "ERROR.\n" << '\n';
    std::cout << "Introduzca el número máximo de elementos del vector: ";
    std::cin >> max;
    std::cout << '\n';
  }

  std::cout << "Introduzca el incremento: ";
  std::cin >> incremento;
  std::cout << '\n';

  std::cout << "Introduzca las repeticiones: ";
  std::cin >> repeticiones;
  std::cout << '\n';

  std::vector<int> v; // Vector a ordenar.

  // Se elimina el fichero de trabajo para tenerlo limpio
  eliminaFichero();

  // Se realizan las pruebas
  realizarExperimento(v, min, max, incremento, repeticiones);

  // std::cout << "\nSIN ORDENAR" << '\n';
  // // Se visualiza el vector por pantalla.
  // imprimeVector(v, tam);
  //
  // // Comprueba que el vector esté ordenado
  // if (estaOrdenado(v) == false) {std::cout << "\n\nEl vector NO está ordenado." << '\n';}
  // else {std::cout << "\n\nEl vector está ordenado." << '\n';}
  //
  // // Se ordena el vector.
  // quicksort(v, 0, tam - 1);
  //
  // std::cout << "\nORDENADO" << '\n';
  // // Se visualiza el vector por pantalla.
  // imprimeVector(v, tam);

  // // Comprueba que el vector esté ordenado
  // if (estaOrdenado(v) == false) {std::cout << "\n\tEl vector NO está ordenado." << '\n';}
  // else {std::cout << "\n\tEl vector está ordenado." << '\n';}






	for(unsigned int i = 0; i <= 1000000000; i++) {

	}


	// if (time.isStarted()) {
	// 	time.stop();
	// 	std::cout << "\n\tHan pasado " << time.elapsed() << " microsegundos.\n\n";
	// }

	return 0;
}
