/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación
ed::Monomio & ed::Monomio::operator = (ed::Monomio const &m) {
	setCoeficiente(m.getCoeficiente());
	setGrado(m.getGrado());

	#ifndef NDEBUG
		assert(std::abs(getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
		assert(getGrado() == m.getGrado());
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator = (double const &coeficiente) {
	setCoeficiente(coeficiente);
	setGrado(0);

	// Se devuelve el objeto actual
	return *this;
}


////////////////////////////////////////////////////////////////////////////////


// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+= (ed::Monomio const &m) {
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}



// COMPLETAR EL RESTO DE OPERADORES



////////////////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// COMPLETAR


////////////////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR
