/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
	 \author Ignacio Antonio Ruiz Martin-Romo
*/


//  Ficheros de cabecera
#include <iostream>
#include "macros.hpp"

#include "Monomio.hpp"

using namespace std;
// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	// COMPLETAR
	setCoeficiente(m.getCoeficiente());
	setGrado(m.getGrado());

	#ifndef NDEBUG
		assert(std::abs(getCoeficiente()- m.getCoeficiente())<COTA_ERROR);
		assert(getGrado()==m.getGrado());
	#endif
	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	// COMPLETAR

		setCoeficiente(x);
		setGrado(0);

		#ifndef NDEBUG
		assert(std::abs(getCoeficiente()- x)<COTA_ERROR);
		assert (getGrado()==0);
		#endif
	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR
//////////////////////SUMA//////////////////////////////////////////
ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	// COMPLETAR

	#ifndef NDEBUG
	assert(getGrado() == m.getGrado());
	#endif

	setCoeficiente(getCoeficiente() + m.getCoeficiente());

	#ifndef NDEBUG
	assert(getGrado()==m.getGrado());
	#endif
	// Se devuelve el objeto actual
	return *this;
}
/////////////////////RESTA////////////////////////////////////////
ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
#ifndef NDEBUG
assert(getGrado() == m.getGrado());
#endif

	setCoeficiente(getCoeficiente()-m.getCoeficiente());

#ifndef NDEBUG
	assert(getGrado()==m.getGrado());
#endif

	return *this;
}
//////////////////////MULTIPLICACION///////////////////////////////////
ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m)
{
	setCoeficiente(getCoeficiente()*m.getCoeficiente());
	setGrado(getGrado()+m.getGrado());

	return *this;
}
//////////////////DIVISION//////////////////////////////////////
ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m)
{
	int grado=getGrado();
	int coeficiente=getCoeficiente();
	#ifndef NDEBUG
	assert (m.getGrado()<=getGrado());
	assert (m.getCoeficiente()!=0.0);
	#endif

	setCoeficiente(getCoeficiente()/m.getCoeficiente());
	setGrado(getGrado() - m.getGrado());
	#ifndef NDEBUG
		assert(abs(getCoeficiente() -(coeficiente/m.getCoeficiente()))<COTA_ERROR);
		assert(getGrado()==grado - m.getGrado());

	#endif

	return *this;
}
////////////////MULTIPLICACION REAL////////////////////////////////////
ed::Monomio & ed::Monomio::operator*=(double const &x)
{

	int grado = getGrado();

	setCoeficiente(getCoeficiente()*x);

	#ifndef NDEBUG
		assert(grado==getGrado());
	#endif

	return *this;
}
// COMPLETAR EL RESTO DE OPERADORES
ed::Monomio & ed::Monomio::operator/=(double const &x)
{
	int grado = getGrado();
	#ifndef NDEBUG
	assert (x!=0.0);
	#endif

	setCoeficiente((getCoeficiente() / x));

	#ifndef NDEBUG
		assert(getGrado() == grado);
	#endif

	return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// COMPLETAR
	void ed::Monomio:: leerMonomio()
{
	double coeficiente;
	int grado;
	cout<<IYELLOW;
	cout<<"Introduzca por pantalla el grado del monomio"<<endl;
	cout<<RESET;
	cin>>grado;

	cout<<IYELLOW;
	cout<<"Introduzca por pantalla el coeficiente del monomio"<<endl;
	cout<<RESET;
	cin>>coeficiente;

	setGrado(grado);
	setCoeficiente(coeficiente);
	#ifndef NDEBUG
	assert (getGrado() >= 0);
	#endif
}
	void ed::Monomio:: escribirMonomio()
{
	if(getCoeficiente()==1){
		cout<<" X^"<<getGrado()<<endl;
	}
	else if(getCoeficiente()==0){
				cout<<" -X^"<<getGrado()<<endl;
			}
			else if(getGrado()==0){
						cout<<getCoeficiente()<<endl;
					}
					else if(getGrado()==1){
			cout<<getCoeficiente()<<"X"<<endl;
							}
							else
									cout<<getCoeficiente()<<"X^"<<getGrado()<<endl;

}

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio
double ed::Monomio:: calcularValor(double x)
{
 return getCoeficiente()*pow(x,getGrado());
}
// COMPLETAR
