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
	this->limpiarVector();

  	this->setMonomios(m);


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
	Polinomio p2(*this);

	this->limpiarVector();


	Monomio m;

	for(int i = 0; i < p2.size(); i++)
	{
		for(int j=0; j < p.size(); j++)
		{
			m = ( p2.getMonomios()[i] * p.getMonomios()[j] );

			this->setMonomios(m);
		}
	}



	// Se devuelve el objeto actual
	return *this;
// COMPLETAR EL RESTO DE OPERADORES
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m)
{
	Polinomio p;

	p.limpiarVector();

	p.setMonomios(m);


	(*this)*=p;

 	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x)
{
	for(int i=0;i < this->size() ; i++)
	{
			this->setMonomios(this->getMonomios()[i].getCoeficiente() * x);
	}
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p)
{
	Polinomio p2(*this), p3;
	p3.limpiarVector();
	this->limpiarVector();

	Monomio aux, aux2;

	while (p2.getGrado() >= p.getGrado() )
	{
		aux = p2.getMonomio(p2.getGrado());
		aux2 = p.getMonomio(p.getGrado());

		aux/=aux2;

		this->setMonomios(aux);

		p3=p;

		p3*=aux;

		p2-=p3;

		p2.eliminaCeros();

		/*p2.escribirPolinomio();
		p.escribirPolinomio();
		this->escribirPolinomio();*/

	}

	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m)
{
	Polinomio p,p2(*this), p3;

	p.limpiarVector();
	p.setMonomios(m);

	p3.limpiarVector();

	this->limpiarVector();

	Monomio aux, aux2;


	while (p2.getGrado() >= p.getGrado() )
	{
		aux = p2.getMonomio(p2.getGrado());
		aux2 = p.getMonomio(p.getGrado());

		aux/=aux2;

		/*std::cout<<"aux, aux2 y aux/aux2"<<std::endl;
		aux.escribirMonomio();
		aux2.escribirMonomio();
		aux.escribirMonomio();*/

		this->setMonomios(aux);



		p3=p;
		p3*=aux;
		p2-=p3;
		p2.eliminaCeros();

	}
 return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x)
{
	for(int i=0;	i < this->size();	i++)
	{
		this->monomios_[i]/=x;
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio
void ed::Polinomio::leerPolinomio()
{
ed::Monomio aux;
int opc;

this->monomios_.clear();

do
{
	aux.leerMonomio();

	this->setMonomios(aux);

	std::cout<<"1 Para introducir monomio y 0 para parar:"<<std::endl;
	std::cin>>opc;
}while(opc!=0);

}
// COMPLETAR

void ed::Polinomio::escribirPolinomio()const 
{
	for(int i=0;	i < this->size();	i++)
	{
		this->getMonomios()[i].escribirMonomio();
	}

}

bool ed::Polinomio::esNulo()const
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

ed::Monomio ed::Polinomio::getMonomio(int grado)const
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
void ed::Polinomio::limpiarVector()
{
	this->monomios_.clear();
}
// Funciones auxiliares de la clase Polinomio

double ed::Polinomio::calcularValor(double x)
{
	int valor=0;

	for(int i=0;	i < this->size();	i++)
	{
			valor+=this->monomios_[i].getCoeficiente()*pow(x,this->monomios_[i].getGrado());
	}
	return valor;
}

void ed::Polinomio::eliminaCeros()
{
	for(int i=0;	i < this->size();)
	{
		if(abs(this->monomios_[i].getCoeficiente())<COTA_ERROR)//COEFICIENTE =0
		{
			this->monomios_.erase(this->monomios_.begin()+i);
			i=0;
		}else{
			i++;
		}
	}

	if(this->size() == 0)
	{
		Monomio m;
		this->monomios_.push_back(m);
	}
}
