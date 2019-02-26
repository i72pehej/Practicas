/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio.
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"


////////////////////////////////////////////////////////////////////////////////


	// Operadores de asignación.

	// Devuelve el monomio actual que ha sido modificado con los atributos del monomio "m".
	ed::Monomio & ed::Monomio::operator = (ed::Monomio const &m) {
		setCoeficiente(m.getCoeficiente());
		setGrado(m.getGrado());

		// Postcondiciones.
		#ifndef NDEBUG
			assert(std::abs(getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
			assert(getGrado() == m.getGrado());
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	// Devuelve el monomio actual que ha sido modificado para que su grado sea 0
	// y su coeficiente el número real "x".
	ed::Monomio & ed::Monomio::operator = (double const &coeficiente) {
		setCoeficiente(coeficiente);
		setGrado(0);

		// Postcondiciones.
		#ifndef NDEBUG
			assert(std::abs(getCoeficiente() - coeficiente) < COTA_ERROR);
			assert(getGrado() == 0);
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


////////////////////////////////////////////////////////////////////////////////


	// Operadores aritméticos y asignación.

	// Modifica el monomio sumándole otro monomio de igual  grado.
	ed::Monomio & ed::Monomio::operator += (ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = getCoeficiente();
		#endif

		if (m.getGrado() == getGrado()) {
			setCoeficiente(m.getCoeficiente() + getCoeficiente());

			// Postcondiciones.
			#ifndef NDEBUG
				assert(oldCoeficiente == getCoeficiente() - m.getCoeficiente());
			#endif

			// Se devuelve el objeto actual.
			return *this;
		}
		else { // En caso de error.
			exit (EXIT_FAILURE);
		}
	}


	// Modifica el monomio restándole otro monomio de igual grado.
	ed::Monomio & ed::Monomio::operator -= (ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = getCoeficiente();
			int oldGrado = getGrado();
		#endif

		if (m.getGrado() == getGrado()) {
			setCoeficiente(getCoeficiente() - m.getCoeficiente());

			// Postcondiciones.
			#ifndef NDEBUG
				assert(getCoeficiente() == (oldCoeficiente - m.getCoeficiente()));
				assert(oldGrado == getGrado());
			#endif

			// Se devuelve el objeto actual.
			return *this;
		}
		else { // En caso de error.
			exit (EXIT_FAILURE);
		}
	}


	// Modifica el monomio actual multiplicándolo por otro monomio.
	ed::Monomio & ed::Monomio::operator *= (ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = getCoeficiente();
			int oldGrado = getGrado();
		#endif

		setCoeficiente(getCoeficiente() * m.getCoeficiente());
		setGrado(getGrado() + m.getGrado());

		// Postcondiciones.
		#ifndef NDEBUG
			assert(getCoeficiente() == (oldCoeficiente * m.getCoeficiente()));
			assert(getGrado() == oldGrado + m.getGrado());
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	// Modifica el monomio actual dividiéndolo por otro monomio.
	ed::Monomio & ed::Monomio::operator /= (ed::Monomio const &m) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = getCoeficiente();
			int oldGrado = getGrado();
		#endif

		if ((m.getGrado() <= getGrado()) and (m.getCoeficiente() not_eq 0.0)) {
			setCoeficiente(getCoeficiente() / m.getCoeficiente());
			setGrado(getGrado() - m.getGrado());

			// Postcondiciones.
			#ifndef NDEBUG
				assert(oldCoeficiente == getCoeficiente() * m.getCoeficiente());
				assert(oldGrado == (getGrado() + m.getGrado()));
			#endif

			// Se devuelve el objeto actual.
			return *this;
		}
		else { // En caso de error.
			exit (EXIT_FAILURE);
		}
	}


	// Modifica el monomio actual multiplicándolo por un número real.
	ed::Monomio & ed::Monomio::operator *= (double const &x) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = getCoeficiente();
			int oldGrado = getGrado();
		#endif

		setCoeficiente(getCoeficiente() * x);

		// Postcondiciones.
		#ifndef NDEBUG
			assert(getCoeficiente() == oldCoeficiente * x);
			assert(getGrado() == oldGrado);
		#endif

		// Se devuelve el objeto actual.
		return *this;
	}


	// Modifica el monomio actual dividiéndolo por un número real.
	ed::Monomio & ed::Monomio::operator /= (double const &x) {
		// Precondiciones.
		#ifndef NDEBUG
			double oldCoeficiente = getCoeficiente();
			int oldGrado = getGrado();
		#endif

		if (x not_eq 0.0) {
			setCoeficiente(getCoeficiente() / x);

			// Postcondiciones.
			#ifndef NDEBUG
				assert(getCoeficiente() == oldCoeficiente / x);
				assert(getGrado() == oldGrado);
			#endif

			// Se devuelve el objeto actual.
			return *this;
		}
		else { // En caso de error.
			exit (EXIT_FAILURE);
		}
	}


////////////////////////////////////////////////////////////////////////////////


	// Funciones lectura y escritura de la clase Monomio

	// Lee desde teclado los atributos del monomio.
	void ed::Monomio::leerMonomio() {
		std::cout << "Introduzca el coeficiente del monomio." << '\n';
		double coeficiente;
		std::cin >> coeficiente;
		setCoeficiente(coeficiente);

		std::cout << "Introduzca el grado del monomio." << '\n';
		int grado;
		std::cin >> grado;
		setGrado(grado);

		// Postcondiciones.
		#ifndef NDEBUG
			assert(getGrado() >= 0);
		#endif
	}


	// Escribe por pantalla los atributos del monomio con formato: "coeficiente X ^ grado".
	void ed::Monomio::escribirMonomio() {
		// Diferentes casos para el ahorro de elementos sin valor.
		if (getGrado() == 0) {std::cout << "Monomio (con grado = 0): " << getCoeficiente() << '\n';}
		else if (getGrado() == 1) {std::cout << "Monomio (con grado = 1): " << getCoeficiente() << "x" << '\n';}
		else if (getCoeficiente() == 1) {std::cout << "Monomio (con coeficiente = 1): " << "x ^ " << getGrado() << '\n';}
		else if (getCoeficiente() == -1) {std::cout << "Monomio (con coeficiente = -1): " << "-x ^ " << getGrado() << '\n';}

		else {std::cout << "Monomio: " << getCoeficiente() << "x ^ " << getGrado() << '\n';}
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
