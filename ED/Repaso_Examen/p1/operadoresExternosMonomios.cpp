/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if (m1.getCoeficiente() == m2.getCoeficiente()) {
			if (m1.getGrado() == m2.getGrado()) {return true;}
		}

		return false;
	}

	bool operator==(ed::Monomio const &m, double x) {
		if ((m.getCoeficiente() - x) < COTA_ERROR) {
			if (m.getGrado() == 0) {return true;}
		}

		return false;
	}

	bool operator==(double x, ed::Monomio const &m) {
		if ((m.getCoeficiente() - x) < COTA_ERROR) {
			if (m.getGrado() == 0) {return true;}
		}

		return false;
	}



	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if (m1 == m2) {return false;}

		return true;
	}

	bool operator!=(ed::Monomio const & m, double x)
	{
		if (m == x) {return false;}

		return true;
	}

	bool operator!=(double x, ed::Monomio const & m)
	{
		if (m == x) {return false;}

		return true;
	}


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio(m.getCoeficiente(), m.getGrado());

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio((-1) * m.getCoeficiente(), m.getGrado());

		// Se devuelve el resultado
		return *nuevo;
	}


	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente() + m2.getCoeficiente(), m1.getGrado());

		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta

	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente() - m2.getCoeficiente(), m1.getGrado());

		// Se devuelve el resultado
		return *nuevo;
	}


	//////////////////
	// Multiplicación

	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente() * m2.getCoeficiente(), m1.getGrado() + m2.getGrado());

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// División

	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(m1.getGrado() >= m2.getGrado());
			assert((m2.getCoeficiente() - 0.0) > COTA_ERROR);
		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente() / m2.getCoeficiente(), m1.getGrado() - m2.getGrado());

		// Se devuelve el resultado
		return *nuevo;
	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		std::string aux;

		getline(stream, aux, ' ');
		m.setCoeficiente(atof(aux.c_str()));
		getline(stream, aux);
		m.setGrado(atoi(aux.c_str()));

		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		stream << m.getCoeficiente() << " " << m.getGrado();

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
