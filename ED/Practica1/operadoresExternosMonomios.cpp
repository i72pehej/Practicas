/*!
	\file		operadoresExternosMonomios.cpp
	\brief	Ficheros con el código de los operadores externos de la clase Monomio.
  \author	Julen Pérez Hernández
  \date		26/02/2019
*/


// Ficheros de cabecera.
#include <iostream>

#include "operadoresExternosMonomios.hpp"


// Se incluyen los operadores sobrecargados dentro del espacio de nombres ed.
namespace ed {


////////////////////////////////////////////////////////////////////////////////


	// Operadores de igualdad.

	// Comprueba si dos monomios son iguales.
	bool operator == (ed::Monomio const &m1, ed::Monomio const &m2) {
		// Postcondiciones.
		if ((m1.getGrado() == m2.getGrado()) and (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)) {return true;}
		else {return false;}

		exit (EXIT_FAILURE); // En caso de resultados imprevistos.
	}


	// Comprueba si un monomio es igual a un número real: "m == x".
	bool operator == (ed::Monomio const &m, double const &x) {
		// Postcondiciones.
		if ((m.getGrado() == 0) and (std::abs(m.getCoeficiente() - x) < COTA_ERROR)) {return true;}
		else {return false;}

		exit (EXIT_FAILURE); // En caso de resultados imprevistos.
	}


	// Comprueba si un número real es igual a un monomio: "x == m".
	bool operator == (double const &x, ed::Monomio const &m) {
		// Postcondiciones.
		if ((m.getGrado() == 0) and (std::abs(m.getCoeficiente() - x) < COTA_ERROR)) {return true;}
		else {return false;}

		exit (EXIT_FAILURE); // En caso de resultados imprevistos.
	}


////////////////////////////////////////////////////////////////////////////////


	// Operadores de desigualdad.

	// Comprueba si dos monomios NO son iguales: "m1 != m2".
	bool operator != (ed::Monomio const &m1, ed::Monomio const &m2) {
		// Postcondiciones.
		if ((m1.getGrado() not_eq m2.getGrado()) or (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR)) {return true;}
		else {return false;}

		exit (EXIT_FAILURE); // En caso de resultados imprevistos.
	}


	// Comprueba si un monomio NO es igual a un número real: "m != x".
	bool operator != (ed::Monomio const &m, double const &x) {
		// Postcondiciones.
		if ((m.getGrado() not_eq 0) or (std::abs(m.getCoeficiente() - x) > COTA_ERROR)) {return true;}
		else {return false;}

		exit (EXIT_FAILURE); // En caso de resultados imprevistos.
	}


	// Comprueba si un número real NO es igual a un monomio: "x != m".
	bool operator != (double const &x, ed::Monomio const &m) {
		// Postcondiciones.
		if ((m.getGrado() not_eq 0) or (std::abs(m.getCoeficiente() - x) > COTA_ERROR)) {return true;}
		else {return false;}

		exit (EXIT_FAILURE); // En caso de resultados imprevistos.
	}


////////////////////////////////////////////////////////////////////////////////


	// Operadores unarios prefijos.

	// Devuelve una copia del monomio pasado por referencia: "+m".
	ed::Monomio &operator + (ed::Monomio const &m) {
		// Se crea un nuevo monomio con igual atributos que el actual.
		ed::Monomio *nuevo = new ed::Monomio(m.getCoeficiente(), m.getGrado());

		// Se devuelve el resultado.
		return *nuevo;
	}


	// Devuelve el monomio opuesto al pasado por referencia: "-m".
	ed::Monomio &operator - (ed::Monomio const &m) {
		// Se crea un nuevo monomio con igual grado al actual y coeficiente opuesto.
		ed::Monomio *nuevo = new ed::Monomio(-(m.getCoeficiente()), m.getGrado());

		// Se devuelve el resultado.
		return *nuevo;
	}


////////////////////////////////////////////////////////////////////////////////


	// Operadores aritméticos binarios.

	// Devuelve un monomio resultado de la suma de otros dos: "m1 + m2".
	ed::Monomio &operator + (ed::Monomio const &m1, ed::Monomio const &m2) {
		// Precondiciones.
		if (m1.getGrado() == m2.getGrado()) {
			// Se crea un nuevo monomio con igual grado que el actual y coeficiente igual a la suma de los coeficientes.
			ed::Monomio *nuevo = new ed::Monomio((m1.getCoeficiente() + m2.getCoeficiente()), m1.getGrado());

			// Se devuelve el resultado.
			return *nuevo;
		}

		exit (EXIT_FAILURE); // En caso de resultados imprevistos.
	}


////////////////////////////////////////////////////////////////////////////////


	// Devuelve un monomio resultado de la resta de otros dos: "m1 - m2".
	ed::Monomio &operator - (ed::Monomio const &m1, ed::Monomio const &m2) {
		// Precondiciones.
		if (m1.getGrado() == m2.getGrado()) {
			// Se crea un nuevo monomio con igual grado que el actual y coeficiente igual a la resta de los coeficientes.
			ed::Monomio *nuevo = new ed::Monomio((m1.getCoeficiente() - m2.getCoeficiente()), m1.getGrado());

			// Se devuelve el resultado.
			return *nuevo;
		}

		exit (EXIT_FAILURE); // En caso de resultados imprevistos.
	}


////////////////////////////////////////////////////////////////////////////////


	// Devuelve un monomio resultado del producto de otros dos: "m1 * m2".
	ed::Monomio &operator * (ed::Monomio const &m1, ed::Monomio const &m2) {
		// Se crea un nuevo monomio con grado igual a la suma de los grados y coeficiente igual al producto de los coeficientes.
		ed::Monomio *nuevo = new ed::Monomio((m1.getCoeficiente() * m2.getCoeficiente()), (m1.getGrado() + m2.getGrado()));

		// Se devuelve el resultado.
		return *nuevo;
	}


	// Devuelve un monomio resultado del producto de un monomio por un número real: "m * x".
	ed::Monomio &operator * (ed::Monomio const &m, double const &x) {
		// Se crea un nuevo monomio con grado igual al del monomio y coeficiente igual al producto del coeficiente del monomio por el número real.
		ed::Monomio *nuevo = new ed::Monomio((m.getCoeficiente() * x), m.getGrado());

		// Se devuelve el resultado.
		return *nuevo;
	}


	// Devuelve un monomio resultado del producto de un número real por un monomio: "x * m".
	ed::Monomio &operator * (double const &x, ed::Monomio const &m) {
		// Se crea un nuevo monomio con grado igual al del monomio y coeficiente igual al producto del coeficiente del monomio por el número real.
		ed::Monomio *nuevo = new ed::Monomio((x * m.getCoeficiente()), m.getGrado());

		// Se devuelve el resultado.
		return *nuevo;
	}


////////////////////////////////////////////////////////////////////////////////


	// Devuelve un monomio resultado de la división de otros dos: "m1 / m2".
	ed::Monomio &operator / (ed::Monomio const &m1, ed::Monomio const &m2) {
		// Precondiciones.
		#ifndef NDEBUG
			assert(m2.getGrado() <= m1.getGrado());
			assert(m2.getCoeficiente() not_eq 0.0);
		#endif

		// Se crea un nuevo monomio con grado igual a la resta de los monomios y coeficiente igual a la división de los coeficientes de los monomios.
		ed::Monomio *nuevo = new ed::Monomio((m1.getCoeficiente() / m2. getCoeficiente()), (m1.getGrado() - m2.getGrado()));

		// Postcondiciones.
		#ifndef NDEBUG
			assert(nuevo -> getGrado() == (m1.getGrado() - m2.getGrado()));
			assert(nuevo -> getCoeficiente() == (m1.getCoeficiente() / m2. getCoeficiente()));
		#endif

		// Se devuelve el resultado.
		return *nuevo;
	}


	// Devuelve un monomio resultado de la división de un monomio por un número real: "m / x".
	ed::Monomio &operator / (ed::Monomio const &m, double const &x) {
		// Precondiciones.
		#ifndef NDEBUG
			assert(x not_eq 0.0);
		#endif

		// Se crea un nuevo monomio resultado de la división del monomio actual por el número.
		ed::Monomio *nuevo = new ed::Monomio((m.getCoeficiente() / x), m.getGrado());

		#ifndef NDEBUG
			assert(nuevo -> getGrado() == m.getGrado());
			assert(nuevo -> getCoeficiente() == (m.getCoeficiente() / x));
		#endif

		// Se devuelve el resultado.
		return *nuevo;
	}


	// Devuelve un monomio resultado de la división de un número real por un monomio: "x / m".
	ed::Monomio &operator / (double const &x, ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			assert((m.getGrado() == 0.0) and (m.getCoeficiente() not_eq 0.0));
		#endif

		// Se crea un nuevo monomio resultado de la división del monomio actual por el número.
		ed::Monomio *nuevo = new ed::Monomio((x / m.getCoeficiente()), m.getGrado());

		#ifndef NDEBUG
			assert(nuevo -> getGrado() == 0);
			assert(nuevo -> getCoeficiente() == (x / m.getCoeficiente()));
		#endif

		// Se devuelve el resultado.
		return *nuevo;
	}


////////////////////////////////////////////////////////////////////////////////


	// Sobrecarga del operador de entrada ">>".
	istream &operator >> (istream &stream, ed::Monomio &m) {
		double coeficiente;
		int grado;

		stream >> grado;
		m.setGrado(grado);

		stream >> coeficiente;
		m.setCoeficiente(coeficiente);

		// Se devuelve el flujo de entrada.
		return stream;
	}


	// Sobrecarga del operador de salida "<<".
	ostream &operator << (ostream &stream, ed::Monomio const &m) {
		stream << m.getGrado() << " " << m.getCoeficiente();

		// Se devuelve el flujo de salida.
		return stream;
	}


////////////////////////////////////////////////////////////////////////////////


} // namespace ed.
