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
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
		#endif

		if (m.getGrado() == getGrado()) {
			setCoeficiente(std::abs(m.getCoeficiente() + getCoeficiente()));

			#ifndef NDEBUG
				assert(oldCoeficiente == std::abs(getCoeficiente() - m.getCoeficiente()));
			#endif

			// Se devuelve el objeto actual.
			return *this;
		}
		else {
			exit (EXIT_FAILURE);
		}
	}

	ed::Monomio & ed::Monomio::operator -= (ed::Monomio const &m) {
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			int oldGrado = getGrado();
		#endif

		if (m.getGrado() == getGrado()) {
			setCoeficiente(std::abs(m.getCoeficiente() - getCoeficiente()));

			#ifndef NDEBUG
				assert(oldCoeficiente == std::abs(getCoeficiente() + m.getCoeficiente()));
				assert(oldGrado == getGrado());
			#endif

			// Se devuelve el objeto actual.
			return *this;
		}
		else {
			exit (EXIT_FAILURE);
		}
	}


	ed::Monomio & ed::Monomio::operator *= (ed::Monomio const &m) {
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			int oldGrado = getGrado();
		#endif

		setCoeficiente(getCoeficiente() * m.getCoeficiente());
		setGrado(getGrado() + m.getGrado());

		#ifndef NDEBUG
			assert(getCoeficiente() == std::abs(oldCoeficiente * m.getCoeficiente()));
			assert(getGrado() == oldGrado + m.getGrado());
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	ed::Monomio & ed::Monomio::operator /= (ed::Monomio const &m) {
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			int oldGrado = getGrado();
		#endif

		if ((m.getGrado() <= getGrado()) and (std::abs(m.getCoeficiente()) not_eq 0.0)) {
			setCoeficiente(std::abs(getCoeficiente() / m.getCoeficiente()));
			setGrado(getGrado() - m.getGrado());

			#ifndef NDEBUG
				assert(oldCoeficiente == std::abs(getCoeficiente() * m.getCoeficiente()));
				assert(oldGrado == (getGrado() + m.getGrado()));
			#endif

			// Se devuelve el objeto actual.
			return *this;
		}
		else {
			exit (EXIT_FAILURE);
		}
	}


	ed::Monomio & ed::Monomio::operator *= (double const &x) {

		// Se devuelve el objeto actual.
		return *this;
	}


	ed::Monomio & ed::Monomio::operator /= (double const &x) {

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
