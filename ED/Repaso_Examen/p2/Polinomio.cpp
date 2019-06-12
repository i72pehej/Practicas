/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

// Operadores de asignación

// COMPLETAR


/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	// Se recorre el polinomio que se pasa como argumento.
	for (size_t i = 0; i < p.getVector().size(); i++) {
		// Si existe en nuestro polinomio un monomio con mismo grado al de alguno de los del otro polinomio...
		if (this->existeGrado(p.getVector()[i].getGrado())) {
			// Se recorre nuestro polinomio en busca del monomio con mismo grado.
			for (size_t j = 0; j < this->getVector().size(); j++) {
				// Cuando se encuentre el monomio con el mismo grado, se realiza la suma.
				if (this->getVector()[j].getGrado() == p.getVector()[i].getGrado()) {
					this->getVector()[j] = this->getVector()[j] + p.getVector()[i];
				}
			}
		}

		// En caso de no existir ningún monomio con igual grado, se inserta y ordena.
		else {this->getVector().push_back(p.getVector()[i]);}
	}

	// Para terminar se ordena el vector resultante.
	this->ordenaPolinomio();

	// Se devuelve el objeto actual
	return *this;
}


Polinomio & Polinomio::operator+=(Monomio const &monomio) {
	// Variable para comprobar si se ha sumado el monomio o no.
	bool sumado = false;

	// Se recorre nuestro polinomio en busca de un monomio con igual grado al pasado.
	for(int i = 0; i < this->getNumeroMonomios(); i++) {
		// Si se encuentra, se suman los monomios.
		if(this->getVector()[i].getGrado() == monomio.getGrado()) {
			this->getVector()[i] = this->getVector()[i] + monomio;
			// Se indica que el monomio ha sido sumado.
			sumado = true;
		}
	}

	// Si no se ha encontrado un monomio de igual grado al que sumarle el pasado...
	// se inserta el nuevo monomio al polinomio.
	if(sumado == false) {this->getVector().push_back(monomio);}
	// Se ordena el polinomio.
	this->_ordenaPolinomio();

	// Se devuelve el objeto actual.
	return *this;

////////////////////////////////////////////////////////////////////////////////
// ¿!¿!¿!¿!¿!¿¿! Se podía utilizar la función anterior como Polinomio de un sólo elemento y así ahorrar.?¿?¿¿
// Al igual que se hace en la siguiente función ??¿?¿¿?¿?

	// // Se crea un polinomio auxiliar vacío.
	// Polinomio auxPolinomio;
	// // Se le inserta el monomio que se pasa como argumento.
	// auxPolinomio.push_back(monomio);
	//
	// // Se devuelve lo que nos devuelve la función "+=" anterior, teniendo el polinomio como argumento.
	// return(*this += auxPolinomio);
////////////////////////////////////////////////////////////////////////////////
}


Polinomio & Polinomio::operator+=(double numero_real) {
	// Se crea un monomio con únicamente el coeficiente.
	Monomio aux_monomio(numero_real, 0);

	// Se devuelve lo que devuelve la función "+=" teniendo un monomio como argumento.
	return(*this += aux_monomio);
}



// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

// COMPLETAR
