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
#include <cmath>    // Para log10()
#include <string>   // Para string y stod

#include "sistemaEcuaciones.cpp"

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

////////////////////////////////////////////////////////////////////////////////

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
    std::fstream ficheroTiempos("tiempos.txt", std::ios::app);

    if (ficheroTiempos.is_open()) {ficheroTiempos << nEle << " " << times << '\n';}
    else {std::cout << "\n\n\nERROR al abrir el fichero." << '\n';}

    ficheroTiempos.close();
  }

////////////////////////////////////////////////////////////////////////////////

  // Elimina cualquier fichero coincidente
  void eliminaFichero() {
    if (std::remove("tiempos.txt") == 0) {
      std::cout << "\nFichero <'tiempos.txt'> existente.\nEliminando . . .\n" << '\n';
    }
  }

////////////////////////////////////////////////////////////////////////////////

  // Función para realizar los sumatorios de los tamaños de las pruebas
  void sumatorioX(std::vector< std::vector<double> > &A, const std::vector<double> v) {
    A.clear();  // Se limpia la matriz.
    int sumaA;  // Sumatorio

    // Recorre la matriz para ir colocando los sumatorios en sus posiciones
    for (size_t i = 0; i < A.size(); i++) {
      for (size_t j = 0; j < A.size(); j++) {
        sumaA = 0; // Reiniciamos el valor.

        for (size_t k = 0; k < v.size(); k++) {
          sumaA += pow(v.at(k), i + j);  // Sumatorio de los valores de tamaño de cada posición de A.
        }
        A[i][j] = sumaA;  // Se asigna el valor a su posicion
      }
    }
  }

////////////////////////////////////////////////////////////////////////////////

  // Función para realizar los sumatorios de los tiempos de las pruebas
  void sumatorioY(std::vector< std::vector<double> > &B, const std::vector<double> v, const std::vector<double> treal) {
    B.clear();  // Se limpia la matriz.
    int sumaB;  // Sumatorio

    for (size_t i = 0; i < B.size(); i++) {
      sumaB = 0; // Reiniciamos el valor.

      for (size_t k = 0; k < v.size(); k++) {
        sumaB += (treal.at(k) * pow(v.at(k), i));  // Sumatorio de los valores de tiempos de cada posición de B.
      }
      B[i][0] = sumaB;  // Se asigna el valor a su posicion
    }
  }

////////////////////////////////////////////////////////////////////////////////

  // Funcion para imprimir una matriz por pantalla
  void imprimeMatriz(std::vector< std::vector<double> > &matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix.size(); j++) {
        std::cout << "| " << matrix[i].at(j) << " |"; // De cada fila todas las columnas.
      }
      std::cout << '\n';
    }
  }

////////////////////////////////////////////////////////////////////////////////

  // Funcion para ajustar la curva de Tiempos
  void ajusteNlogN(const std::vector<double> &n, const std::vector<double> &tiemposReales, double &a0, double &a1) {
    std::vector< std::vector<double> > A(2, std::vector<double>(2)); // Matriz nxn de coeficientes
    std::vector< std::vector<double> > B(2, std::vector<double>(1)); // Matriz nx1 de terminos independientes
    std::vector< std::vector<double> > X(2, std::vector<double>(2)); // Matriz 2x2 de soluciones
    std::vector<double> nlogs;  // Vector para almacenar "n*log(n)", para después el sumatorio

    // std::vector< std::vector<double> > A;
    // std::vector< std::vector<double> > B;
    // std::vector< std::vector<double> > X;
    // std::vector<double> nlogs;  // Vector para almacenar "n*log(n)", para después el sumatorio
    //
    // A = std::vector< std::vector<double> > (2, std::vector<double>(2)); // Matriz nxn de coeficientes
    // B = std::vector< std::vector<double> > (2, std::vector<double>(1)); // Matriz nx1 de terminos independientes
    // X = std::vector< std::vector<double> > (2, std::vector<double>(2)); // Matriz 2x2 de soluciones


    for (size_t i = 0; i < n.size(); i++) {
      nlogs.push_back(n.at(i) * log10(n.at(i)));
    }

    // std::cout << "\nVector de NLogN:" << '\n';
    // imprimeVectorTiempos(nlogs);

    sumatorioX(A, nlogs);
    std::cout << "\nMatriz de sumatorios de tamaños:" << '\n';
    imprimeMatriz(A);

    sumatorioY(B, nlogs, tiemposReales);
    std::cout << "\nMatriz de términos independientes:" << '\n';
    imprimeMatriz(B);

    // Resolucion del ajuste para hallar las incógnitas "a0" y "a1"
    resolverSistemaEcuaciones(A, B, 2, X);
    std::cout << "\nMatriz de soluciones:" << '\n';
    imprimeMatriz(X);

  }

////////////////////////////////////////////////////////////////////////////////

  // Funcion de obtencion de los tiempos estimados mediante ajuste
  void calcularTiemposEstimadosNlogN(const std::vector<double> &n, const std::vector<double> &tiemposReales, const double &a0, const double &a1, std::vector<double> &tiemposEstimados) {

  }

////////////////////////////////////////////////////////////////////////////////

  // Funcion para calcular el coeficiente de determinacion
  double calcularCoeficienteDeterminacion(const std::vector<double> &tiemposReales, const std::vector<double> &tiemposEstimados) {

    return 0;
  }

////////////////////////////////////////////////////////////////////////////////

  // Funcion que calcula el tiempo estimado a partir de un tamaño dado
  double calcularTiempoEstimadoNlogN(const double &n, const double &a0, const double &a1) {


    return 0;
  }

////////////////////////////////////////////////////////////////////////////////

  // Funcion para extraer nº de elementos y tiempos del fichero
  void extraerTiempos(std::vector<double> &n, std::vector<double> &tiemposReales) {
    std::ifstream ficheroTiempos;
    string tam, tim;

    ficheroTiempos.open("tiempos.txt", std::ifstream::in);

    if (ficheroTiempos.is_open()) {
      while (getline(ficheroTiempos, tam, ' ')) { // Lectura del tamaño
        n.push_back(std::stod(tam));

        getline(ficheroTiempos, tim); // Lectura del tiempo
        tiemposReales.push_back(std::stod(tim));
      }
    }
    else {std::cout << "\n\n\nERROR. No se pudo abrir el fichero." << '\n';}
  }

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

  // Funcion que realiza las pruebas
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


  std::vector<double> n;  // Vector de tamaños de las pruebas
  std::vector<double> tiemposReales;  // Vector de tiempos de las pruebas

  extraerTiempos(n, tiemposReales);

  double a0, a1;  // Variables para guardar el resultado del sistema, incognitas del ajuste

  // Ajuste de la curva tipo: t(n)=a0+a1*n*log(n).
  ajusteNlogN(n, tiemposReales, a0, a1);





	for(unsigned int i = 0; i <= 1000000000; i++) {

	}


	// if (time.isStarted()) {
	// 	time.stop();
	// 	std::cout << "\n\tHan pasado " << time.elapsed() << " microsegundos.\n\n";
	// }

	return 0;
}
