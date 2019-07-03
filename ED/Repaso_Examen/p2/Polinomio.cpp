/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"



ed::Polinomio::Polinomio() {
	ed::Monomio m(0.0, 0);
	this -> getVector().push_back(m);
}

ed::Polinomio::Polinomio(ed::Polinomio const &p) {
	this -> getVector() = p.getVector();
}

bool ed::Polinomio::existeGrado(int gradoB) const {
	std::vector<ed::Monomio>::iterator m;

	for (m = this -> getVector().begin(); m < this -> getVector().end(); m++) {
		if (m -> getGrado() == gradoB) {return true;}
	}

	return false;
}

ed::Monomio ed::Polinomio::getMonomio(int gradoB) const {
	ed::Monomio *nuevo = new ed::Monomio(0.0, 0);
	std::vector<ed::Monomio>::iterator m;

	if (existeGrado(gradoB)) {
		for (m = this->getVector().begin(); m < this->getVector().end(); m++) {
			if (m->getGrado() == gradoB) {nuevo = m;}
		}
	}

	return *nuevo;
}


// Operadores de asignación

/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p) {
	if (*this != p) {this->getVector() = p.getVector();}

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	this->getVector().clear();
	this->getVector().push_back(m);

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	ed::Monomio *nuevo = new ed::Monomio(x, 0);

	this->getVector().clear();
	this->getVector().push_back(nuevo);

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

//Operadores aritméticos y de asignación

//Suma

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p) {
	std::vector<ed::Monomio>::iterator m1;	//Iterador para el polinomio pasado.
	std::vector<ed::Monomio>::iterator m2;	//Iterador para el polinomio *this.

	for (m1 = p.getVector().begin(); m1 < p.getVector().end(); m1++) {
		if (this->existeGrado(m1->getGrado())) {
			for (m2 = this->getVector().begin(); m2 < this->getVector().end(); m2++) {
				if (m2->getGrado() == m1->getGrado()) {m2 += m1;}
			}
		}
		else {
			this->getVector().push_back(m1);
		}
	}

	// Se ordena el polinomio.
	this->_ordenaPolinomio();

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
