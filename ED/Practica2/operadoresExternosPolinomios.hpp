/*!
	\file 	 operadoresExternosPolinomios.hpp
	\brief 	 Ficheros con operadores de monomios y polinomios
	\author  Julen Pérez Hernández
	\date    31/03/2019
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{

////////////////////////////////////////////////////////////////////////////////

	// Funciones y operadores que no pertenecen a la clase Polinomio.

////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores de igualdad

////////////////////////////////////////////////////////////////////////////////

	/*!
 		\brief     Operador de igualdad: Comprueba si dos polinomios son iguales: p1 == p2. Si tienen los mismos monomios.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
 		\attention Se sobrecarga el operador "==".
 		\warning   Se requiere que ciertos parámetros tengan el modificador const.
 		\param     p1: objeto de tipo polinomio pasado como referencia constante.
		\param     p2: objeto de tipo polinomio pasado como referencia constante.
 		\post	     El valor devuelto es verdadero si los dos polinomios tienen los mismos monomios.
		\post	     El valor devuelto es falso, en caso contrario.
 	*/
	bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2);

	/*!
		\brief     Operador de igualdad: Comprueba si el polinomio “p” es igual al monomio “m”, es decir, si el polinomio “p” tiene un único monomio que es igual a “m”.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "==".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el polinomio tiene un único monomio que es igual a “m”.
		\post	     El valor devuelto es falso, en caso contrario.
	*/
	bool operator==(ed::Polinomio const & p1, ed::Monomio const & m1);

	/*!
 		\brief     Operador de igualdad: Comprueba si el polinomio “p” es igual al monomio “m”, es decir, si el polinomio “p” tiene un único monomio que es igual a “m”.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
 		\attention Se sobrecarga el operador "==".
 		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el polinomio tiene un único monomio que es igual a “m”.
		\post	     El valor devuelto es falso, en caso contrario.
 	*/
	bool operator==(ed::Monomio const & m1,ed::Polinomio const & p1);

	/*!
 		\brief     Operador de igualdad: Comprueba si el polinomio “p” es igual al número “x”, es decir, si el polinomio “p” tiene un único monomio que es igual a “x”.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
 		\attention Se sobrecarga el operador "==".
 		\warning   Se requiere que ciertos parámetros tengan el modificador const.
 		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     x: objeto de tipo real pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el polinomio tiene un único monomio que es igual a “x”.
		\post	     El valor devuelto es falso, en caso contrario.
 	*/
	bool operator==(ed::Polinomio const & p1, double const &x);

	/*!
 		\brief     Operador de igualdad: Comprueba si el polinomio “p” es igual al número “x”, es decir, si el polinomio “p” tiene un único monomio que es igual a “x”.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
 		\attention Se sobrecarga el operador "==".
 		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el polinomio tiene un único monomio que es igual a “x”.
		\post	     El valor devuelto es falso, en caso contrario.
 	*/
	bool operator==(double const &x, ed::Polinomio const & p1);

////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores de desigualdad.

////////////////////////////////////////////////////////////////////////////////

	/*!
		\brief     Operador de desigualdad: Comprueba si dos polinomios no son iguales: p1 != p2. Si no tienen los mismos monomios.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "!=".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p1: objeto de tipo polinomio pasado como referencia constante.
		\param     p2: objeto de tipo polinomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si los dos polinomios no tienen los mismos monomios.
		\post	     El valor devuelto es falso, en caso contrario.
	*/
	bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2);


	/*!
		\brief     Operador de desigualdad: Comprueba si el polinomio “p” es no igual al monomio “m”, es decir, si el polinomio “p” no tiene un único monomio que es igual a “m”.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "!=".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el polinomio no tiene un único monomio que es igual a “m”.
		\post	     El valor devuelto es falso, en caso contrario.
	*/
	bool operator!=(ed::Polinomio const & p1, ed::Monomio const & m1);

	/*!
		\brief     Operador de desigualdad: Comprueba si el polinomio “p” es no igual al monomio “m”, es decir, si el polinomio “p” no tiene un único monomio que es igual a “m”.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "!=".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el polinomio no tiene un único monomio que es igual a “m”.
		\post	     El valor devuelto es falso, en caso contrario.
	*/
	bool operator!=( ed::Monomio const & m1, ed::Polinomio const & p1);

	/*!
		\brief     Operador de desigualdad: Comprueba si el polinomio “p” no es igual al número “x”, es decir, si el polinomio “p” no tiene un único monomio que es igual a “x”.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "!=".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     x: objeto de tipo real pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el polinomio no tiene un único monomio que es igual a “x”.
		\post	     El valor devuelto es falso, en caso contrario.
	*/
	bool operator!=(ed::Polinomio const & p1, double const &x);

	/*!
		\brief     Operador de desigualdad: Comprueba si el polinomio “p” no es igual al número “x”, es decir, si el polinomio “p” no tiene un único monomio que es igual a “x”.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "!=".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el polinomio no tiene un único monomio que es igual a “x”.
		\post	     El valor devuelto es falso, en caso contrario.
	*/
	bool operator!=(double const &x, ed::Polinomio const & p1);

////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores unarios

////////////////////////////////////////////////////////////////////////////////

	/*!
		\brief     Operador aritmético unario prefijo: Devuelve una copia del Polinomio “p”: +p.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "+".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\post	     El polinomio devuelto es igual al polinomio “p”, es decir, tiene los mismos monomios.
	*/
	ed::Polinomio & operator+(ed::Polinomio const & p);

	/*!
		\brief     Operador aritmético unario prefijo: Devuelve el opuesto del Polinomio “p”: -p.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "+".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\post	     El polinomio devuelto tiene todos sus monomios opuestos, es decir, el mismo grado pero su coeficiente opuesto.
	*/
	ed::Polinomio & operator-(ed::Polinomio const & p);

////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la suma

////////////////////////////////////////////////////////////////////////////////

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la suma de dos polinomios: p1 + p2.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "+".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p1: objeto de tipo polinomio pasado como referencia constante.
		\param     p2: objeto de tipo polinomio pasado como referencia constante.
	*/
	ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2);


	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la suma de un polinomio y un monomio.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "+".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
	*/
	ed::Polinomio & operator+(ed::Polinomio const &p,  ed::Monomio const & m);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la suma de un polinomio y un monomio.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "+".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
	*/
	ed::Polinomio & operator+(ed::Monomio const &m,  ed::Polinomio const &p);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la suma de un polinomio y un número real.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "+".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     x: objeto de tipo real pasado como referencia constante.
	*/
	ed::Polinomio & operator+(ed::Polinomio const &p,  double const x);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la suma de un polinomio y un número real.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "+".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
	*/
	ed::Polinomio & operator+(double const x,  ed::Polinomio const &p);

////////////////////////////////////////////////////////////////////////////////

		//! \name Operador binario de la resta

////////////////////////////////////////////////////////////////////////////////

/*!
	\brief     Operador aritmético binario: Devuelve otro polinomio que es la resta de dos polinomios: p1 - p2.
	\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
	\attention Se sobrecarga el operador "-".
	\warning   Se requiere que ciertos parámetros tengan el modificador const.
	\param     p1: objeto de tipo polinomio pasado como referencia constante.
	\param     p2: objeto de tipo polinomio pasado como referencia constante.
*/
ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2);

/*!
	\brief     Operador aritmético binario: Devuelve otro polinomio que es la resta de un polinomio y un monomio.
	\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
	\attention Se sobrecarga el operador "-".
	\warning   Se requiere que ciertos parámetros tengan el modificador const.
	\param     p: objeto de tipo polinomio pasado como referencia constante.
	\param     m: objeto de tipo monomio pasado como referencia constante.
*/
ed::Polinomio & operator-(ed::Polinomio const &p,  ed::Monomio const & m);

/*!
	\brief     Operador aritmético binario: Devuelve otro polinomio que es la resta de un monomio y un polinomio.
	\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
	\attention Se sobrecarga el operador "-".
	\warning   Se requiere que ciertos parámetros tengan el modificador const.
	\param     m: objeto de tipo monomio pasado como referencia constante.
	\param     p: objeto de tipo polinomio pasado como referencia constante.
*/
ed::Polinomio & operator-(ed::Monomio const &m,  ed::Polinomio const &p);

/*!
	\brief     Operador aritmético binario: Devuelve otro polinomio que es la resta de un polinomio y un número real.
	\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
	\attention Se sobrecarga el operador "-".
	\warning   Se requiere que ciertos parámetros tengan el modificador const.
	\param     p: objeto de tipo polinomio pasado como referencia constante.
	\param     x: objeto de tipo real pasado como referencia constante.
*/
ed::Polinomio & operator-(ed::Polinomio const &p,  double const x);

/*!
	\brief     Operador aritmético binario: Devuelve otro polinomio que es la resta de un número real y un polinomio.
	\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
	\attention Se sobrecarga el operador "-".
	\warning   Se requiere que ciertos parámetros tengan el modificador const.
	\param     x: objeto de tipo real pasado como referencia constante.
	\param     p: objeto de tipo polinomio pasado como referencia constante.
*/
ed::Polinomio & operator-(double const x,  ed::Polinomio const &p);

////////////////////////////////////////////////////////////////////////////////

		//! \name Operadores binarios de la multiplicación

////////////////////////////////////////////////////////////////////////////////

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la multiplicación de dos polinomios: p1 * p2.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "*".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p1: objeto de tipo polinomio pasado como referencia constante.
		\param     p2: objeto de tipo polinomio pasado como referencia constante.
	*/
	ed::Polinomio & operator*(ed::Polinomio const &p1, ed::Polinomio const &p2);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la multiplicación de un polinomio y un monomio.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "*".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
	*/
	ed::Polinomio & operator*(ed::Polinomio const &p, ed::Monomio const &m);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la multiplicación de un monomio y un polinomio.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "*".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
	*/
	ed::Polinomio & operator*(ed::Monomio const &m, ed::Polinomio const &p);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la multiplicación de un polinomio y un número real.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "*".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     x: objeto de tipo real pasado como referencia constante.
	*/
	ed::Polinomio & operator*(ed::Polinomio const &p, double const x);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la multiplicación de un número real y un polinomio.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "*".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
	*/
	ed::Polinomio & operator*(double const x, ed::Polinomio const &p);

////////////////////////////////////////////////////////////////////////////////

		//! \name Operadores binarios de la división

////////////////////////////////////////////////////////////////////////////////

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la división de dos polinomios: p1 / p2.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "/".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p1: objeto de tipo polinomio pasado como referencia constante.
		\param     p2: objeto de tipo polinomio pasado como referencia constante.
		\pre 			 El grado de p2 es menor o igual que el grado de p1.
	*/
	ed::Polinomio & operator/(ed::Polinomio const &p1, ed::Polinomio const &p2);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la división de un polinomio y un monomio.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "/".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\pre 			 El grado del monomio es menor o igual que el grado del polinomio.
	*/
	ed::Polinomio & operator/(ed::Polinomio const &p, ed::Monomio const &m);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la división de un monomio y un polinomio.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "/".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\pre 			 El grado del polinomio es menor o igual que el grado del monomio.
	*/
	ed::Polinomio & operator/(ed::Monomio const &m, ed::Polinomio const &p);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la división de un polinomio y un número real.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "/".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\param     x: objeto de tipo real pasado como referencia constante.
		\pre 			 El número “x” no es 0.0.
	*/
	ed::Polinomio & operator/(ed::Polinomio const &p, double const x);

	/*!
		\brief     Operador aritmético binario: Devuelve otro polinomio que es la división de un número real y un polinomio.
		\note 		 Se debe utilizar la cota de error para controlar la precisión de números reales.
		\attention Se sobrecarga el operador "/".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
		\pre 			 El polinomio tiene grado 0 y su coeficiente no es 0.0.
	*/
	ed::Polinomio & operator/(double const x, ed::Polinomio const &p);

////////////////////////////////////////////////////////////////////////////////

   //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.

////////////////////////////////////////////////////////////////////////////////

	/*!
		\brief     Operador de flujo de entrada: Lee desde el flujo de entrada un polinomio.
		\attention Se sobrecarga el operador "<<".
		\warning   Se requiere que ciertos parámetros tengan el modificador const.
		\param     stream: objeto de tipo ostream pasado como referencia.
		\param     p: objeto de tipo polinomio pasado como referencia constante.
	*/
	ostream &operator<<(ostream &stream, ed::Polinomio const &p);

	/*!
		\brief     Operador de flujo de salida: Escribe en el flujo de el polinomio.
		\attention Se sobrecarga el operador ">>".
		\param     stream: objeto de tipo istream pasado como referencia.
		\param     p: objeto de tipo polinomio pasado como referencia.
	*/
	istream &operator>>(istream &stream, ed::Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
