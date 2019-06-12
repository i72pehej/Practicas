/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"


////////////////////////////////////////////////////////////////////////////////

// Constructores.
ed::Monomio::Monomio(double coeficiente, int grado) {
	setCoeficiente(coeficiente);
	setGrado(grado);
}

ed::Monomio::Monomio(Monomio const &monomio) {
	setCoeficiente(monomio.getCoeficiente());
	setGrado(monomio.getGrado());
}

////////////////////////////////////////////////////////////////////////////////

// Operadores de asignación

ed::Monomio &ed::Monomio::operator=(ed::Monomio const &m)
{
	setCoeficiente(m.getCoeficiente());
	setGrado(m.getGrado());

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio &ed::Monomio::operator=(double const &x)
{
	setCoeficiente(x);
	setGrado(0);

	// Se devuelve el objeto actual
	return *this;
}

////////////////////////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

ed::Monomio &ed::Monomio::operator+=(ed::Monomio const &m)
{
	if (m.getGrado() == this->getGrado()) {
		this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());
	}

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio &ed::Monomio::operator-=(ed::Monomio const &m)
{
	if (m.getGrado() == this->getGrado()) {
		this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());
	}

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio &ed::Monomio::operator*=(ed::Monomio const &m)
{
	this->setCoeficiente(this->getCoeficiente() * m.getCoeficiente());
	this->setGrado(this->getGrado() + m.getGrado());

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio &ed::Monomio::operator/=(ed::Monomio const &m)
{
	if ((m.getGrado() <= this->getGrado()) && !((std::abs(m.getCoeficiente() - 0.0)) < COTA_ERROR)) {
		this->setCoeficiente(this->getCoeficiente() / m.getCoeficiente());
		this->setGrado(this->getGrado() - m.getGrado());
	}

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio &ed::Monomio::operator*=(double const x)
{
	this->setCoeficiente(this->getCoeficiente() * x);

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio &ed::Monomio::operator/=(double const x)
{
	if (!((std::abs(m.getCoeficiente() - 0.0)) < COTA_ERROR)) {
		this->setCoeficiente(this->getCoeficiente() / x);
	}

	// Se devuelve el objeto actual
	return *this;
}

////////////////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio() {
	double auxCoeficiente;
	int auxGrado;

	std::cout << "Introduce los valores del monomio: " << '\n';
	std::cout << "\tCoeficiente: ";
	std::cin >> auxCoeficiente;
	std::cout << "\tGrado (mayor o igual a 0): ";
	std::cin >> auxGrado;

	// Control de errores.
	while (auxGrado < 0) {
		std::cout << "ERROR al introducir el grado.\nCompruebe que es mayor o igual a 0." << '\n';
		std::cout << "\tGrado (mayor o igual a 0): ";
		std::cin >> auxGrado;
	}

	// Asignación de los valores finales.
	setCoeficiente(auxCoeficiente);
	setGrado(auxGrado);
}


void ed::Monomio::escribirMonomio() {
	// Si el monomio es 0, se escribe 0.
	if (std::abs(getCoeficiente() - 0.0) < COTA_ERROR) {std::cout << "0" << '\n';}

	// Si el monomio no tiene X^x, se imprime el coeficiente.
	if (getGrado() == 0) {std::cout << getCoeficiente() << '\n';}

	// Si el monomio tiene coeficiente y X sin grado, lo escribimos para después evaluar el grado.
	else {
		if (std::abs(getCoeficiente() - 1.0) < COTA_ERROR) {std::cout << "X" << '\n';}
		else if (std::abs(getCoeficiente() - (-1.0)) < COTA_ERROR) {std::cout << "-X" << '\n';}
		else {std::cout << getCoeficiente() << "X";}
	}

	// En caso de que tengamos un grado != 0, escribimos el grado.
	if (getGrado() > 1) {std::cout << "^" << getGrado() << '\n';}
	// Si no tenemos grado, terminamos de escribir el monomio.
	else {std::cout << '\n';}
}

////////////////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio.

double ed::Monomio::calculaValor(double x) {
	return(getCoeficiente() * pow(x, getGrado()));
}
