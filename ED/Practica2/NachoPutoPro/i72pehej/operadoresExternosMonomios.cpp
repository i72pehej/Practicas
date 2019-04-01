/*!
   \file    operadoresExternosMonomios.cpp
	 \brief   Ficheros con el código de los operadores externos de la clase Monomio
	 \author  Julen Pérez Hernández
   \date    31/03/2019
 */



//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if(m1.getCoeficiente()==m2.getCoeficiente() &&  m1.getGrado()==m2.getGrado())
		{
			return true;
		}
			return false;
	}

	bool operator==(ed:: Monomio const &m, double x)
	{

		if(m.getGrado()==0 && m.getCoeficiente()==x)
		{
			return true;
		}
			return false;
	}


	bool operator==(double x, ed:: Monomio const &m)
	{

		if(m.getGrado()==0 && m.getCoeficiente()==x)
		{
			return true;
		}
			return false;
	}



	// Operadores de desigualdad

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{

				if(m1.getCoeficiente()!=m2.getCoeficiente() ||  m1.getGrado()!=m2.getGrado())
				{
					return true;
				}
					return false;
			}


			bool operator!=(ed::Monomio const &m, double x)
			{

				if(m.getGrado()!=0 || m.getCoeficiente()!=x)
				{
					return true;
				}
					return false;
			}


			bool operator!=(double x, ed::Monomio const &m)
			{

				if(m.getGrado()!=0 || m.getCoeficiente()!=x)
				{
					return true;
				}
					return false;
			}


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	ed::Monomio & operator+(ed::Monomio const & m)
	{
//Creamos un nuevo monomio para la copia
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert((nuevo->getCoeficiente()- m.getCoeficiente())<COTA_ERROR);
			assert(nuevo->getGrado()==m.getGrado());
		#endif

		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m)
	{
		//Creamos un nuevo monomio para la copia

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(-m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert((nuevo->getCoeficiente() + m.getCoeficiente())<COTA_ERROR);
			assert(nuevo->getGrado()==m.getGrado());
		#endif

		return *nuevo;
	}

	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios


	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		//Creamos un nuevo monomio para la copia

		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
			assert(m1.getGrado()==m2.getGrado());
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado()==m1.getGrado() && nuevo->getGrado()==m2.getGrado());
			assert(nuevo->getCoeficiente() - (m1.getCoeficiente() + m2.getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}



	ed::Monomio & operator -(ed::Monomio const &m1, ed::Monomio const &m2)
	{
		//Creamos un nuevo monomio para la copia

		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
			assert(m1.getGrado()==m2.getGrado());
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado()==m1.getGrado() && nuevo->getGrado()==m2.getGrado());
			assert(nuevo->getCoeficiente() - (m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	ed::Monomio & operator *(ed::Monomio const &m1, ed::Monomio const &m2)
	{
		//Creamos un nuevo monomio para la copia

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() * m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() + m2.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado()==m1.getGrado() + m2.getGrado());
			assert(nuevo->getCoeficiente() - (m1.getCoeficiente() * m2.getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;

	}

	ed:: Monomio &operator *(ed::Monomio const &m, double x)
	{
		//Creamos un nuevo monomio para la copia

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente() * x);
		nuevo->setGrado(m.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado()==m.getGrado());
			assert(nuevo->getCoeficiente() - (m.getCoeficiente() * x) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;

	}

	ed:: Monomio &operator *( double x, ed::Monomio const &m)
	{
		//Creamos un nuevo monomio para la copia

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(x * m.getCoeficiente());
		nuevo->setGrado(m.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado()==m.getGrado());
			assert(nuevo->getCoeficiente() - (x * m.getCoeficiente() ) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;


	}



	ed::Monomio & operator /(ed::Monomio const &m1, ed::Monomio const &m2)
	{
		//Creamos un nuevo monomio para la copia

		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
			assert(m2.getGrado()<=m1.getGrado());
			assert(m2.getCoeficiente()!=0.0);
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() / m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() - m2.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado()==m1.getGrado() - m2.getGrado());
			assert(nuevo->getCoeficiente() - (m1.getCoeficiente() / m2.getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;

	}

	ed:: Monomio &operator /(ed::Monomio const &m, double x)
	{
		//Creamos un nuevo monomio para la copia

		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
			assert(x!=0.0);
		#endif

		nuevo->setCoeficiente(m.getCoeficiente() / x);
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado()==m.getGrado());
			assert(nuevo->getCoeficiente() - (m.getCoeficiente() / x) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;

	}

	ed:: Monomio &operator /( double x, ed::Monomio const &m)
	{

		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
			assert(m.getGrado()==0);
			assert(m.getCoeficiente()!=0.0);
		#endif


		nuevo->setCoeficiente(x / m.getCoeficiente());

		#ifndef NDEBUG
			assert(nuevo->getGrado()==0);
			assert(nuevo->getCoeficiente() - (x / m.getCoeficiente() ) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;


	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		double cof;
		int gra;
		stream>>cof;

		m.setCoeficiente(cof);

		stream>>gra;

		m.setGrado(gra);

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		stream<<m.getCoeficiente();
		stream<<" ";
		stream<<m.getGrado();

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
