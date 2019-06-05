/*!
   \file 	  Polinomio.cpp
   \brief 	Fichero que contiene el código de las funciones de la clase Polinomio
	 \author  Julen Pérez Hernández
   \date    31/03/2019
 */


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

// Operadores de asignación

/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	this->monomios_.clear();

	for(int i=0; i < p.size(); i++)
	{
		this->setMonomios(p.monomios_[i]);
	}

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	this->monomios_.clear();

  this->monomios_.push_back(m);


	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	this->monomios_.clear();

	Monomio m(x,0);

	this->monomios_.push_back(m);
	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{

	for(int i=0; i < p.size(); i++)
	{
		this->setMonomios(p.monomios_[i]);
	}

	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m)
{

  this->setMonomios(m);


	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x)
{

	for(int i=0;	i < this->size();	i++)
	{
		this->monomios_[i].setCoeficiente(this->monomios_[i].getCoeficiente()+x);
	}
	// Se devuelve el objeto actual
	return *this;
}

///////////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p)
{

	for(int i=0; i < p.size(); i++)
	{
		this->setMonomios(-p.monomios_[i]);
	}

	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &m)
{

  this->setMonomios(-m);


	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x)
{

	for(int i=0;	i < this->size();	i++)
	{
		this->monomios_[i].setCoeficiente(this->monomios_[i].getCoeficiente()-x);
	}
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p)
{


	// Se devuelve el objeto actual
	return *this;
// COMPLETAR EL RESTO DE OPERADORES
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m)
{
 return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x)
{
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p)
{


	// Se devuelve el objeto actual
	return *this;
// COMPLETAR EL RESTO DE OPERADORES
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m)
{
 return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x)
{
	return *this;
}

///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio
void ed::Polinomio::leerPolinomio()
{
ed::Monomio aux;
int opc;

do
{
	aux.leerMonomio();

	this->setMonomios(aux);

	std::cout<<"1 Para introducir monomio y 0 para parar:"<<std::endl;
	std::cin>>opc;
}

while(opc!=0);
}
// COMPLETAR

void ed::Polinomio::escribirPolinomio()
{
	for(int i=0;	i < this->size();	i++)
	{
		this->monomios_[i].escribirMonomio();
	}
	std::cout<<std::endl;
}

bool ed::Polinomio::esNulo()
{
	ed::Monomio aux;

	for(int i=0;	i < this->size();	i++)
	{
		if(monomios_[i]!=aux)
		{
			return false;
		}
	}
	return true;
}

int ed::Polinomio::getGrado()
{
	return this->monomios_[0].getGrado();
}

int ed::Polinomio:: getNumeroMonomios()
{
	int contador=0;

	for(int i=0;	i < this->size();	i++)
	{
		contador++;
	}
	return contador;
}

bool ed::Polinomio::existeMonomio(int grado)
{
	for(int i=0;	i < this->size();	i++)
	{
		if(this->monomios_[i].getGrado()==grado)
		{
			return true;
		}
	}
	return false;
}

ed::Monomio ed::Polinomio::getMonomio(int grado)
{
	Monomio m;
	for(int i=0;	i < this->size();	i++)
	{
		if(this->monomios_[i].getGrado()==grado)
		{
			return this->monomios_[i];
		}
	}
	return m;
}
///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio
