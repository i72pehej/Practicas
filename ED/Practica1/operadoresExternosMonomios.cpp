/*!
  \file operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio.
*/


// Ficheros de cabecera.
#include <iostream>

#include "operadoresExternosMonomios.hpp"


// Se incluyen los operadores sobrecargados dentro del espacio de nombres ed.
namespace ed {


////////////////////////////////////////////////////////////////////////////////


	// Operadores de igualdad.

	// COMPLETAR

	// Comprueba si dos monomios son iguales.
	bool operator == (ed::Monomio const &m1, ed::Monomio const &m2) {
		// COMPLETAR Y MODIFICAR

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}


	// Comprueba si un monomio es igual a un número real: "m == x".
	bool operator == (ed::Monomio const &m, double const &x) {

	}


	// Comprueba si un número real es igual a un monomio: "x == m".
	bool operator == (double const &x, ed::Monomio const &m) {

	}


////////////////////////////////////////////////////////////////////////////////


	// Operadores de desigualdad.

	// COMPLETAR

	// Comprueba si dos monomios NO son iguales: "m1 != m2".
	bool operator!=(ed::Monomio const &m1, ed::Monomio const &m2) {
		// COMPLETAR Y MODIFICAR

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}


	// Comprueba si un monomio NO es igual a un número real: "m != x".
	bool operator != (ed::Monomio const &m, double const &x) {

	}


	// Comprueba si un número real NO es igual a un monomio: "x != m".
	bool operator != (double const &x, ed::Monomio const &m) {

	}


////////////////////////////////////////////////////////////////////////////////


	// Operadores unarios prefijos.

	// COMPLETAR
	ed::Monomio &operator + (ed::Monomio const &m) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();

		// Se devuelve el resultado.
		return *nuevo;
	}


	ed::Monomio &operator - (ed::Monomio const &m) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();

		// Se devuelve el resultado.
		return *nuevo;
	}


	// Operadores aritméticos binarios.


////////////////////////////////////////////////////////////////////////////////


	// Suma.
	ed::Monomio &operator + (ed::Monomio const &m1, ed::Monomio const &m2) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado.
		return *nuevo;
	}


////////////////////////////////////////////////////////////////////////////////


	// Resta
	ed::Monomio &operator - (ed::Monomio const &m1, ed::Monomio const &m2) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado.
		return *nuevo;
	}
	// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


	// Multiplicación.
	ed::Monomio &operator * (ed::Monomio const &m1, ed::Monomio const &m2) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado.
		return *nuevo;
	}


	ed::Monomio &operator * (ed::Monomio const &m, double const &x) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado.
		return *nuevo;
	}


	ed::Monomio &operator * (double const &x, ed::Monomio const &m) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado.
		return *nuevo;
	}


////////////////////////////////////////////////////////////////////////////////


	// División.
	ed::Monomio &operator / (ed::Monomio const &m1, ed::Monomio const &m2) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado.
		return *nuevo;
	}


	ed::Monomio &operator / (ed::Monomio const &m, double const &x) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado.
		return *nuevo;
	}


	ed::Monomio &operator / (double const &x, ed::Monomio const &m) {

		// COMPLETAR Y MODIFICAR

		// Se crea un nuevo objeto.
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado.
		return *nuevo;
	}
	// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


	// Sobrecarga del operador de entrada
	istream &operator >> (istream &stream, ed::Monomio &m) {
		// COMPLETAR

  		// Se devuelve el flujo de entrada.
		return stream;
	}


	// Sobrecarga del operador de salida
	ostream &operator << (ostream &stream, ed::Monomio const &m) {
		// COMPLETAR

		// Se devuelve el flujo de salida.
		return stream;
	}


////////////////////////////////////////////////////////////////////////////////


} // namespace ed
