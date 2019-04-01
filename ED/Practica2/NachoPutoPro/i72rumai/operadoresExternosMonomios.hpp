/*!
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
	\author Ignacio Antonio Ruiz Martin-Romo
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad

	/*!
	\brief     Operador de igualdad: Comprueba si dos Monomios son iguales: m1 == m2
	\attention Sobrecarga mediante el operador "=="
	\param m1: Tipo Monomio por referencia constante
	\param m2: Tipo Monomio por referencia constante
	\pre       Ninguna
	\post	 		 El valor devuelto es verdadero si los dos monomios tienen el mismo grado y el mismo coeficiente, si no es falso
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
	*/

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);


	/*!
	\brief     Operador de igualdad: Comprueba si un monomio es igual a un número real: m == x
	\attention Sobrecarga mediante el operador "=="
	\param  m: Tipo Monomio por referencia constante
	\param  x: Tipo double
	\pre       Ninguna
	\post	 		 El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al número “x”, si no es falso
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	bool operator==(ed:: Monomio const &m, double x);


	/*!
	\brief     Operador de igualdad: Comprueba si un monomio es igual a un número real: x == m
	\attention Sobrecarga mediante el operador "=="
	\param  x: Tipo double
	\param  m: Tipo Monomio por referencia constante
	\pre       Ninguna
	\post	 		 El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al número “x”, si no es falso
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	bool operator==(double x, ed:: Monomio const &m);


	//! \name Operadores de desigualdad

	/*!
	\brief     Operador de desigualdad: Comprueba si dos monomios son diferentes: m1 != m2
	\attention Sobrecarga mediante el operador "!="
	\param m1: Tipo Monomio por referencia constante
	\param m2: Tipo Monomio por referencia constante
	\pre       Ninguna
	\post	 		 El valor devuelto es verdadero si los dos monomios no tienen el mismo grado o no tienen el mismo coeficiente, si no es falso
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);


	/*!
	\brief     Operador de desigualdad: Comprueba si un monomio no es igual a un número real: m == x
	\attention Sobrecarga mediante el operador "!="
	\param  m: Tipo Monomio por referencia constante
	\param  x: Tipo double
	\pre       Ninguna
	\post	 		 El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente no es igual al número “x”, si no es falso
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	bool operator!=(double x, ed::Monomio const &m);


	/*!
	\brief     Operador de desigualdad: Comprueba si un monomio no es igual a un número real: x == m
	\attention Sobrecarga mediante el operador "!="
	\param  x: Tipo double
	\param  m: Tipo Monomio por referencia constante
	\pre       Ninguna
	\post	 		 El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente no es igual al número “x”, si no es falso
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	bool operator!=(ed::Monomio const &m, double x);

	///////////////////////////////////////////////////

	//! \name Operadores aritmeticos unarios prefijos

	/*!
	\brief     Operador aritmético unario prefijo: Devuelve una copia del Monomio “m”: +m
	\attention Sobrecarga mediante el operador "+"
	\param  m: Objeto de tipo Monomio por referencia constante
	\pre       Ninguna
	\post	 		 El monomio devuelto es igual al monomio “m”, es decir, tiene el mismo grado y el mismo coeficiente
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	ed::Monomio & operator+(ed::Monomio const & m);


	/*!
	\brief     Operador aritmético unario prefijo: Devuelve el opuesto del Monomio “m”: -m
	\attention Sobrecarga mediante el operador "-"
	\param  m: Objeto de tipo Monomio por referencia constante
	\pre       Ninguna
	\post	 	 	 El Monomio devuelto tiene el mismo grado que el monomio “m” pero su coeficiente es el opuesto
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	ed:: Monomio & operator-(ed::Monomio const &m);

	//////////////////////////////////////////////////////////

	//! \name Operador aritmético binario de la suma

	/*!
	\brief     Operador aritmético binario: Devuelve otro monomio que es la suma de dos monomios: m1 + m2
	\attention Sobrecarga mediante el operador "+"
	\param m1: Tipo Monomio por referencia constante
	\param m2: Tipo Monomio por referencia constante
	\pre       Los monomios m1 y m2 tienen el mismo grado
	\post	 	 	 El monomio devuelto tiene el mismo grado que los monomios m1 y m2, y su coeficiente es la suma de los coeficientes de los monomios
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);



//////////////////////////////////////////////////////////
	//! \name Operador aritmético binario de la resta


	/*!
	\brief     Operador aritmético binario: Devuelve otro monomio que es la resta de dos monomios: m1 – m2
	\attention Sobrecarga mediante el operador "-"
	\param m1: Tipo Monomio por referencia constante
	\param m2: Tipo Monomio por referencia constante
	\pre       Los monomios m1 y m2 tienen el mismo grado
	\post	 	 	 El monomio devuelto tiene el mismo grado que los monomios m1 y m2, y su coeficiente es la resta de los coeficientes de los monomios
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	ed:: Monomio & operator-(ed:: Monomio const &m1, ed:: Monomio const &m2);


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación


	/*!
	\brief     Operador aritmético binario: Devuelve otro monomio que es el producto de dos monomios: m1 * m2
	\attention Sobrecarga mediante el operador "*"
	\param m1: Tipo Monomio por referencia constante
	\param m2: Tipo Monomio por referencia constante
	\pre       Los monomios m1 y m2 tienen el mismo grado
	\post	 	 	 El monomio devuelto tiene un grado que es la suma de los grados de los monomios m1 y m2
	\post      El coeficiente del monomio devuelto es el producto de los coeficientes de los monomios m1 y m2
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


ed:: Monomio & operator*( ed:: Monomio const &m1, ed:: Monomio const &m2);


	/*!
	\brief     Operador aritmético binario: Devuelve otro monomio que es el producto de un monomio por un número real: m * x
	\attention Sobrecarga mediante el operador "*"
	\param m:  Tipo Monomio por referencia constante
	\param x:  Tipo double
	\pre       Los monomios m1 y m2 tienen el mismo grado
	\post	 	 	 El monomio devuelto tiene el mismo grado que el monomio “m”
	\post      El coeficiente del monomio devuelto es el producto del coeficiente del monomio “m” por el número “x”
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


ed:: Monomio & operator*(ed:: Monomio const &m, double x);


	/*!
	\brief     Operador aritmético binario: Devuelve otro monomio que es el producto de un monomio por un número real: x * m
	\attention Sobrecarga mediante el operador "*"
	\param x:  Elemento de tipo double
	\param m:  Objeto de tipo Monomio por referencia constante
	\pre       Los monomios m1 y m2 tienen el mismo grado
	\post	 	 	 El monomio devuelto tiene el mismo grado que el monomio “m”
	\post      El coeficiente del monomio devuelto es el producto del coeficiente del monomio “m” por el número “x”
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


ed:: Monomio & operator*(double x,ed:: Monomio const &m);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división


	/*!
	\brief     Operador aritmético binario: Devuelve otro monomio que es la división de dos monomios: m1 / m2
	\attention Sobrecarga mediante el operador "/"
	\param m1: Tipo Monomio por referencia constante
	\param m2: Tipo Monomio por referencia constante
	\pre       El grado del monomio m2 es menor o igual que el grado del monomio m1
	\pre       El coeficiente del monomio m2 no es 0.0
	\post	 	 	 El monomio devuelto tiene un grado que es la resta de los grados de los monomios m1 y m2
	\post      El coeficiente del monomio devuelto es la division de los coeficientes de los monomios m1 y m2
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/


	ed:: Monomio & operator/( ed:: Monomio const &m1, ed:: Monomio const &m2);


	/*!
	\brief     Operador aritmético binario: Devuelve otro monomio que es la division de un monomio por un número real: m / x
	\attention Sobrecarga mediante el operador "/"
	\param m:  Tipo Monomio por referencia constante
	\param x:  Tipo double
	\pre       El número “x” no es 0.0
	\post	 	 	 El monomio devuelto tiene el mismo grado que el monomio “m”
	\post      El coeficiente del monomio devuelto es la division del coeficiente del monomio “m” por el número “x”
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/

	ed:: Monomio & operator/(ed:: Monomio const &m, double x);


	/*!
	\brief     Operador aritmético binario: Devuelve otro monomio que es la división del número “x” por el monomio “m”: x / m
	\attention Sobrecarga mediante el operador "/"
	\param x:  Tipo double
	\param m:  Tipo Monomio por referencia constante
	\pre       El grado del monomio es 0
	\pre			 El coeficiente del monomio es distinto de 0.0
	\post	 	 	 El monomio devuelto tiene grado igual a 0
	\post      El coeficiente del monomio devuelto es la division del número “x” por el coeficiente del monomio “m”
	\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
*/

	ed:: Monomio & operator/(double x,ed:: Monomio const &m);



	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida


	/*!
	\brief  Sobrecarga del operador de flujo de entrada o lectura ">>"
	     \n Lee desde el flujo de entrada los atributos de un monomio separados por espacios
	\param   stream: Flujo de entrada
 	\param   m: Objeto de tipo Monomio por referencia
	\pre     Ninguna
	\post    Ninguna
	\sa      operator<<
*/


	 istream &operator>>(istream &stream, ed::Monomio &m);


	/*!
	\brief  Sobrecarga del operador de flujo de salida o escritura "<<"
	\n Escribe en el flujo de salida los atributos del monomio separados por espacios
	\param  stream: Flujo de salida
	\param  m: Objeto de tipo Monomio por referencia constante
	\pre    Ninguna
	\post   Ninguna
	\sa     operator>>
*/


	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
