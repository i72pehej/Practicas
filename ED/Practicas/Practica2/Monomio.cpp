/*!
	\file		Monomio.cpp
	\brief	Fichero que contiene el código de las funciones de la clase Monomio.
  \author	Julen Pérez Hernández
  \date		26/02/2019
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"
#include "macros.hpp"


////////////////////////////////////////////////////////////////////////////////


	// Operadores de asignación.

	// Devuelve el monomio actual que ha sido modificado con los atributos del monomio "m".
	ed::Monomio & ed::Monomio::operator = (ed::Monomio const &m) {
		#ifndef NDEBUG
			assert((std::abs(getCoeficiente() - m.getCoeficiente())) > COTA_ERROR);
			assert(getGrado() not_eq m.getGrado());
		#endif

		setCoeficiente(m.getCoeficiente());
		setGrado(m.getGrado());

		// Postcondiciones.
		#ifndef NDEBUG
			assert((std::abs(getCoeficiente() - m.getCoeficiente())) < COTA_ERROR);
			assert(getGrado() == m.getGrado());
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	// Devuelve el monomio actual que ha sido modificado para que su grado sea 0
	// y su coeficiente el número real "x".
	ed::Monomio & ed::Monomio::operator = (double const &coeficiente) {
		// #ifndef NDEBUG
			// assert(std::abs(getCoeficiente() - coeficiente) > COTA_ERROR);
		// #endif

		if ((std::abs(getCoeficiente() - coeficiente)) > COTA_ERROR) {
			setCoeficiente(coeficiente);
		}

		setGrado(0);

		// Postcondiciones.
		#ifndef NDEBUG
			assert((std::abs(getCoeficiente() - coeficiente)) < COTA_ERROR);
			assert(getGrado() == 0);
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


////////////////////////////////////////////////////////////////////////////////


	// Operadores aritméticos y asignación.

	// Modifica el monomio sumándole otro monomio de igual grado.
	ed::Monomio & ed::Monomio::operator += (ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			assert(m.getGrado() == getGrado());
		#endif

		setCoeficiente(getCoeficiente() + m.getCoeficiente());

		// Postcondiciones.
		#ifndef NDEBUG
			assert((std::abs(getCoeficiente()) - (std::abs(oldCoeficiente + m.getCoeficiente()))) < COTA_ERROR);
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	// Modifica el monomio restándole otro monomio de igual grado.
	ed::Monomio & ed::Monomio::operator -= (ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			int oldGrado = getGrado();
			assert(m.getGrado() == getGrado());
		#endif

		setCoeficiente(getCoeficiente() - m.getCoeficiente());

		// Postcondiciones.
		#ifndef NDEBUG
			assert((std::abs(getCoeficiente()) - (std::abs(oldCoeficiente - m.getCoeficiente()))) < COTA_ERROR);
			assert(oldGrado == getGrado());
		#endif

			// Se devuelve el objeto actual.
			return *this;
	}


	// Modifica el monomio actual multiplicándolo por otro monomio.
	ed::Monomio & ed::Monomio::operator *= (ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			int oldGrado = getGrado();
		#endif

		setCoeficiente(getCoeficiente() * m.getCoeficiente());
		setGrado(getGrado() + m.getGrado());

		// Postcondiciones.
		#ifndef NDEBUG
			assert((std::abs(getCoeficiente()) - (std::abs(oldCoeficiente * m.getCoeficiente()))) < COTA_ERROR);
			assert(getGrado() == oldGrado + m.getGrado());
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	// Modifica el monomio actual dividiéndolo por otro monomio.
	ed::Monomio & ed::Monomio::operator /= (ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			int oldGrado = getGrado();
			assert((m.getGrado() <= getGrado()) and (std::abs(m.getCoeficiente()) > COTA_ERROR));
		#endif

		setCoeficiente(getCoeficiente() / m.getCoeficiente());
		setGrado(getGrado() - m.getGrado());

		// Postcondiciones.
		#ifndef NDEBUG
			assert((oldCoeficiente - (std::abs(getCoeficiente() * m.getCoeficiente()))) < COTA_ERROR);
			assert(oldGrado == (getGrado() + m.getGrado()));
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	// Modifica el monomio actual multiplicándolo por un número real.
	ed::Monomio & ed::Monomio::operator *= (double const &x) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			int oldGrado = getGrado();
		#endif

		setCoeficiente(getCoeficiente() * x);

		// Postcondiciones.
		#ifndef NDEBUG
			assert((std::abs(getCoeficiente()) - (std::abs(oldCoeficiente * x))) < COTA_ERROR);
			assert(getGrado() == oldGrado);
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	// Modifica el monomio actual dividiéndolo por un número real.
	ed::Monomio & ed::Monomio::operator /= (double const &x) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = std::abs(getCoeficiente());
			int oldGrado = getGrado();
			assert(x not_eq 0.0);
		#endif

		setCoeficiente(getCoeficiente() / x);

		// Postcondiciones.
		#ifndef NDEBUG
			assert((std::abs(getCoeficiente()) - std::abs(oldCoeficiente / x)) < COTA_ERROR);
			assert(getGrado() == oldGrado);
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


////////////////////////////////////////////////////////////////////////////////


	// Funciones lectura y escritura de la clase Monomio

	// Lee desde teclado los atributos del monomio.
	void ed::Monomio::leerMonomio() {
		std::cout << "Introduzca el ";
		std::cout << UCYAN;
		std::cout << "coeficiente";
		std::cout << RESET;
		std::cout << " del monomio." << '\n';
		double coeficiente;
		std::cin >> coeficiente;
		setCoeficiente(coeficiente);

		std::cout << "Introduzca el ";
		std::cout << UCYAN;
		std::cout << "grado";
		std::cout << RESET;
		std::cout << " del monomio." << '\n';
		int grado;
		std::cin >> grado;

		while (grado < 0) {
			printf("ERROR. Debe introducir un valor positivo para el grado.\n");
			printf("Vuleva a intentarlo.\n");

			std::cin >> grado;
		}
		setGrado(grado);

		// Postcondiciones.
		#ifndef NDEBUG
			assert(getGrado() >= 0);
		#endif
	}


	// Escribe por pantalla los atributos del monomio con formato: "coeficiente X ^ grado".
	void ed::Monomio::escribirMonomio() {
		// Diferentes casos para el ahorro de elementos sin valor.
		if (getGrado() == 0) {std::cout << getCoeficiente() << '\n';}
		else if (getGrado() == 1) {std::cout << getCoeficiente() << "x" << '\n';}
		else if (getCoeficiente() == 1) {std::cout << "x ^ " << getGrado() << '\n';}
		else if (getCoeficiente() == -1) {std::cout << "-x ^ " << getGrado() << '\n';}

		else {
			// std::cout << CYAN;
			// std::cout << "Monomio: ";
			// std::cout << RESET;
			std::cout << getCoeficiente() << "x ^ " << getGrado() << '\n';}
	}


////////////////////////////////////////////////////////////////////////////////


	// Funciones auxiliares de la clase Monomio.

	// Calcula el valor del monomio para un número real "x".
	double ed::Monomio::calcularValor(double const &x) {
		double valorFinal;

		valorFinal = getCoeficiente() * pow(x, getGrado());

		// Se devuelve el valor del monomio tras sustituir la variable.
		return valorFinal;
	}
