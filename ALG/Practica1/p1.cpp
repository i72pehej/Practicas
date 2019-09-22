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
#include <cstring> //Para usar memset
#include <iostream>
#include <stdint.h> // Para usar uint64_t
#include <vector>  //para usar vectores
#include <stdlib.h>
#include <stdio.h>


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
  void imprimeVector(std::vector<int> &vector, int size) {
    std::cout << "\nVector:\n" << '\n';
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
      std::cout <<" / "<< *it;
    }
    std::cout << " /\n\n";
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
    #ifndef NDEBUG
      assert(*v < (*v + 1));
    #endif

    if (*v < *v + 1) {
      estaOrdenado(v);
    }

    return true;
  }




int main() {
  system("clear");

  Clock time;
  // srand(time(0));

  // Comienza a contar el contador
  time.start();

  int tam;  // Tamaño del vector. Introducido por el usuario.


  std::cout << "Introduzca la capacidad del vector: ";
  std::cin >> tam;
  std::cout << '\n';

  std::vector<int> v (tam); // Vector a ordenar.
  rellenaVector(v);

  // Se visualiza el vector por pantalla.
  imprimeVector(v, tam);

  // Se ordena el vector.
  quicksort(v, 0, tam - 1);

  // Se visualiza el vector por pantalla.
  imprimeVector(v, tam);



	for(unsigned int i = 0; i <= 1000000000; i++) {



	}


	if (time.isStarted()) {
		time.stop();
		std::cout << "Han pasado " << time.elapsed() << " microsegundos.\n\n";
	}
	return 0;
}
