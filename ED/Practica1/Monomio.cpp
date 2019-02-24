/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

	// Operadores de asignación.

	ed::Monomio & ed::Monomio::operator = (ed::Monomio const &m) {
		setCoeficiente(m.getCoeficiente());
		setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(std::abs(getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
			assert(getGrado() == m.getGrado());
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	ed::Monomio & ed::Monomio::operator = (double const &coeficiente) {
		setCoeficiente(coeficiente);
		setGrado(0);

		#ifndef NDEBUG
			assert(std::abs(getCoeficiente() - coeficiente) < COTA_ERROR);
			assert(getGrado() == 0);
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


////////////////////////////////////////////////////////////////////////////////


	// Operadores aritméticos y asignación

	ed::Monomio & ed::Monomio::operator += (ed::Monomio const &m) {
		if (m->getGrado() == *this->getGrado()) {
			setCoeficiente(m->getCoeficiente() + *this->getCoeficiente());

			// Se devuelve el objeto actual.
			return *this;
		}
		else {
			return EXIT_FAILURE;
		}
	}

	ed::Monomio & ed::Monomio::operator -= (ed::Monomio const &m) {

		// Se devuelve el objeto actual.
		return *this;
	}


	ed::Monomio & ed::Monomio::operator *= (ed::Monomio const &m) {

		// Se devuelve el objeto actual.
		return *this;
	}


	ed::Monomio & ed::Monomio::operator /= (ed::Monomio const &m) {

		// Se devuelve el objeto actual.
		return *this;
	}


	ed::Monomio & ed::Monomio::operator += (ed::Monomio const &m) {

		// Se devuelve el objeto actual.
		return *this;
	}


	ed::Monomio & ed::Monomio::operator -= (ed::Monomio const &m) {

		// Se devuelve el objeto actual.
		return *this;
	}


////////////////////////////////////////////////////////////////////////////////


	// Funciones lectura y escritura de la clase Monomio

	void leerMonomio() {

		// Se devuelve el objeto actual.
		return *this;
	}


	void escribirMonomio() {

		// Se devuelve el objeto actual.
		return *this;
	}


////////////////////////////////////////////////////////////////////////////////


	// Funciones auxiliares de la clase Monomio

	double calcularValor(double const &x) {

		// Se devuelve el objeto actual.
		return *this;
	}
