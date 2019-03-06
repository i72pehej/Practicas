/*!
	\file 	operadoresExternosMonomios.hpp
	\brief	Ficheros con los prototipos de los operadores externos de la clase Monomio.
	\author Julen Pérez Hernández
	\date   26/02/2019
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida.
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>.
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed.
namespace ed {


////////////////////////////////////////////////////////////////////////////////


	// Operadores externos que no pertenecen a la clase Monomio.

	//! \name Operadores de igualdad.

	/*!
		\fn				 bool operator == (ed::Monomio const &m1, ed::Monomio const &m2).
		\brief     Operador de igualdad: operador que comprueba si dos monomios son iguales.
		\attention Se sobrecarga el operador de igualdad "==".
		\warning   Se requiere que los parámetros m1 y m2 tengan el modificador const.
		\param     m1: objeto de tipo monomio pasado como referencia constante.
		\param     m2: objeto de tipo monomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si los dos monomios tienen el mismo grado y el mismo coeficiente.
		\post	     El valor devuelto es falso en caso contrario.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        bool operator == (ed::Monomio const &m, double const &x), bool operator == (double const &x, ed::Monomio const &m).
	*/
	bool operator == (ed::Monomio const &m1, ed::Monomio const &m2);


	/*!
		\fn				 bool operator == (ed::Monomio const &m, double const &x).
		\brief     Operador de igualdad: operador que comprueba si un monomio es igual a un número real.
		\attention Se sobrecarga el operador de igualdad "==".
		\warning   Se requiere que los parámetros m y x tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\param     x: objeto de tipo real pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al número "x".
		\post	     El valor devuelto es falso en caso contrario.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        bool operator == (ed::Monomio const &m1, ed::Monomio const &m2), bool operator == (double const &x, ed::Monomio const &m).
	*/
	bool operator == (ed::Monomio const &m, double const &x);


	/*!
		\fn				 bool operator == (double const &x, ed::Monomio const &m).
		\brief     Operador de igualdad: operador que comprueba si un número real es igual a un monomio.
		\attention Se sobrecarga el operador de igualdad "==".
		\warning   Se requiere que los parámetros x y m tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al número "x".
		\post	     El valor devuelto es falso en caso contrario.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        bool operator == (ed::Monomio const &m1, ed::Monomio const &m2), bool operator == (ed::Monomio const &m, double const &x).
	*/
	bool operator == (double const &x, ed::Monomio const &m);


////////////////////////////////////////////////////////////////////////////////


	//! \name Operadores de desigualdad.

	/*!
		\fn				 bool operator != (ed::Monomio const &m1, ed::Monomio const &m2).
		\brief     Operador de desigualdad: operador que comprueba si dos monomios NO son iguales.
		\attention Se sobrecarga el operador de desigualdad "!=".
		\warning   Se requiere que los parámetros m1 y m2 tengan el modificador const.
		\param     m1: objeto de tipo monomio pasado como referencia constante.
		\param     m2: objeto de tipo monomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si los dos monomios NO tienen el mismo grado o NO tienen el mismo coeficiente.
		\post	     El valor devuelto es falso en caso contrario.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        bool operator != (double const &x, ed::Monomio const &m), bool operator != (ed::Monomio const &m, double const &x).
	*/
	bool operator != (ed::Monomio const &m1, ed::Monomio const &m2);


	/*!
		\fn				 bool operator != (double const &x, ed::Monomio const &m).
		\brief     Operador de desigualdad: operador que comprueba si un número real NO es igual a un monomio.
		\attention Se sobrecarga el operador de desigualdad "!=".
		\warning   Se requiere que los parámetros m y x tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el monomio NO tiene grado 0 o su coeficiente NO es igual al número "x".
		\post	     El valor devuelto es falso en caso contrario.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        bool operator != (ed::Monomio const &m1, ed::Monomio const &m2), bool operator != (ed::Monomio const &m, double const &x).
	*/
	bool operator != (double const &x, ed::Monomio const &m);


	/*!
		\fn				 bool operator != (ed::Monomio const &m, double const &x).
		\brief     Operador de desigualdad: operador que comprueba si un monomio es igual a un número real.
		\attention Se sobrecarga el operador de desdeigualdad "!=".
		\warning   Se requiere que los parámetros x y m tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\param     x: objeto de tipo real pasado como referencia constante.
		\post	     El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al número "x".
		\post	     El valor devuelto es falso en caso contrario.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        bool operator != (ed::Monomio const &m1, ed::Monomio const &m2), bool operator != (double const &x, ed::Monomio const &m).
	*/
	bool operator != (ed::Monomio const &m, double const &x);


////////////////////////////////////////////////////////////////////////////////


	//! \name Operadores unarios prefijos.

	/*!
		\fn				 ed::Monomio &operator + (ed::Monomio const &m).
		\brief     Operador de suma: operador que devuelve una copia del monomio.
		\attention Se sobrecarga el operador de suma: "+".
		\warning   Se requiere que el parámetro m tenga el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\post	     El monomio devuelto es igual al monomio "m", es decir, tiene el mismo grado y el mismo coeficiente.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        ed::Monomio &operator - (ed::Monomio const &m).
	*/
	ed::Monomio &operator + (ed::Monomio const &m);


	/*!
		\fn				 ed::Monomio &operator - (ed::Monomio const &m).
		\brief     Operador de resta: operador que devuelve el opuesto del monomio.
		\attention Se sobrecarga el operador de resta: "-".
		\warning   Se requiere que el parámetro m tenga el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\post	     El monomio devuelto tiene el mismo grado que el monomio "m" pero su coeficiente es el opuesto.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        ed::Monomio &operator + (ed::Monomio const &m).
	*/
	ed::Monomio &operator - (ed::Monomio const &m);


////////////////////////////////////////////////////////////////////////////////


	//! \name Operador binario de la suma.

	/*!
		\fn				 ed::Monomio &operator + (ed::Monomio const &m1, ed::Monomio const &m2).
		\brief     Operador de suma: operador que devuelve otro monomio con la suma de dos monomios.
		\attention Se sobrecarga el operador de suma: "+".
		\warning   Se requiere que los parámetros m1 y m2 tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\pre 			 Los monomios m1 y m2 tienen el mismo grado.
		\post 		 El monomio devuelto tiene el mismo grado que los monomios m1 y m2.
		\post	     El monomio devuelto tiene coeficiente igual a la suma de los coeficientes de los monomios.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        ed::Monomio &operator - (ed::Monomio const &m).
	*/
	 ed::Monomio &operator + (ed::Monomio const &m1, ed::Monomio const &m2);


////////////////////////////////////////////////////////////////////////////////


	//! \name Operador binario de la resta.

	/*!
		\fn				 ed::Monomio &operator - (ed::Monomio const &m1, ed::Monomio const &m2).
		\brief     Operador de suma: operador que devuelve otro monomio con la resta de dos monomios.
		\attention Se sobrecarga el operador de resta: "-".
		\warning   Se requiere que los parámetros m1 y m2 tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\pre 			 Los monomios m1 y m2 tienen el mismo grado.
		\post 		 El monomio devuelto tiene el mismo grado que los monomios m1 y m2.
		\post	     El monomio devuelto tiene coeficiente igual a la resta de los coeficientes de los monomios.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        ed::Monomio &operator + (ed::Monomio const &m).
	*/
	ed::Monomio &operator - (ed::Monomio const &m1, ed::Monomio const &m2);


////////////////////////////////////////////////////////////////////////////////


	//! \name Operadores binarios de la multiplicación.

	/*!
		\fn				 ed::Monomio &operator * (ed::Monomio const &m1, ed::Monomio const &m2).
		\brief     Operador de producto: operador que devuelve otro monomio resultado del producto de dos monomios.
		\attention Se sobrecarga el operador de producto: "*".
		\warning   Se requiere que los parámetros m1 y m2 tengan el modificador const.
		\param     m1: objeto de tipo monomio pasado como referencia constante.
		\param     m2: objeto de tipo monomio pasado como referencia constante.
		\post 		 El monomio devuelto tiene un grado que es la suma de los grados de los monomios m1 y m2.
		\post	     El monomio devuelto tiene coeficiente igual al producto de los coeficientes de los monomios m1 y m2.
		\sa        ed::Monomio &operator * (ed::Monomio const &m, double const &x), ed::Monomio &operator * (double const &x, ed::Monomio const &m).
	*/
	ed::Monomio &operator * (ed::Monomio const &m1, ed::Monomio const &m2);


	/*!
		\fn				 ed::Monomio &operator * (ed::Monomio const &m, double const &x).
		\brief     Operador de producto: operador que devuelve otro monomio resultado del producto de un monomio por un número real.
		\attention Se sobrecarga el operador de producto: "*".
		\warning   Se requiere que los parámetros m y x tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\param     x: objeto de tipo real pasado como referencia constante.
		\post 		 El monomio devuelto tiene el mismo grado que el monomio “m”.
		\post	     El monomio devuelto tiene como coeficiente el producto del coeficiente del monomio “m” por el número “x”.
		\sa        ed::Monomio &operator * (ed::Monomio const &m1, ed::Monomio const &m2), ed::Monomio &operator * (double const &x, ed::Monomio const &m).
	*/
	ed::Monomio &operator * (ed::Monomio const &m, double const &x);


	/*!
		\fn				 ed::Monomio &operator * (double const &x, ed::Monomio const &m).
		\brief     Operador de producto: operador que devuelve otro monomio que es el producto de un número real por un monomio.
		\attention Se sobrecarga el operador de producto: "*".
		\warning   Se requiere que los parámetros x y m tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\post 		 El monomio devuelto tiene el mismo grado que el monomio “m”.
		\post	     El monomio devuelto tiene como coeficiente el producto del coeficiente del monomio “m” por el número “x”.
		\sa        ed::Monomio &operator * (ed::Monomio const &m, double const &x), ed::Monomio &operator * (ed::Monomio const &m1, ed::Monomio const &m2).
	*/
	ed::Monomio &operator * (double const &x, ed::Monomio const &m);

////////////////////////////////////////////////////////////////////////////////


	//! \name Operadores binarios de la división.

	/*!
		\fn				 ed::Monomio &operator / (ed::Monomio const &m1, ed::Monomio const &m2).
		\brief     Operador de división: operador que devuelve otro monomio cuyo valor es la división de dos monomios.
		\attention Se sobrecarga el operador de división: "/".
		\warning   Se requiere que los parámetros m1 y m2 tengan el modificador const.
		\param     m1: objeto de tipo monomio pasado como referencia constante.
		\param     m2: objeto de tipo monomio pasado como referencia constante.
		\pre 			 El grado del monomio m2 es menor o igual que el grado del monomio m1.
		\pre			 El coeficiente del monomio m2 no es 0.0.
		\post 		 El monomio devuelto tiene un grado que es la resta de los grados de los monomios m1 y m2.
		\post	     El monomio devuelto tiene como coeficiente la división de los coeficientes de los monomios m1 y m2.
		\sa        ed::Monomio const &m2), ed::Monomio &operator / (ed::Monomio const &m, double const &x), ed::Monomio &operator / (double const &x, ed::Monomio const &m).
	*/
	ed::Monomio &operator / (ed::Monomio const &m1, ed::Monomio const &m2);


	/*!
	\fn				 ed::Monomio &operator / (ed::Monomio const &m, double const &x).
	\brief     Operador de división: operador que devuelve otro monomio cuyo valor es la división del monomio “m” por el número real “x”.
	\attention Se sobrecarga el operador de división: "/".
	\warning   Se requiere que los parámetros m y x tengan el modificador const.
	\param     m: objeto de tipo monomio pasado como referencia constante.
	\param     x: objeto de tipo real pasado como referencia constante.
	\pre 			 El número “x” no es 0.0.
	\post 		 El monomio devuelto tiene el mismo grado que el monomio “m”.
	\post	     El monomio devuelto tiene como coeficiente la división del coeficiente del monomio “m” por el número “x”.
	\sa        ed::Monomio &operator / (ed::Monomio const &m1, ed::Monomio &operator / (double const &x, ed::Monomio const &m).
	*/
	ed::Monomio &operator / (ed::Monomio const &m, double const &x);


	/*!
		\fn				 ed::Monomio &operator / (double const &x, ed::Monomio const &m).
		\brief     Operador de producto: operador que devuelve otro monomio que es la división del número “x” por el monomio “m”.
		\attention Se sobrecarga el operador de división: "/".
		\warning   Se requiere que los parámetros x y m tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\pre 			 El grado del monomio es 0 y su coeficiente es distinto de 0.0.
		\post 		 El monomio devuelto tiene grado igual a 0.
		\post	     El monomio devuelto tiene como coeficiente la división del número “x” por el coeficiente del monomio “m”.
		\sa        ed::Monomio &operator / (ed::Monomio const &m1, ed::Monomio const &m2), ed::Monomio &operator / (ed::Monomio const &m).
	*/
	ed::Monomio &operator / (double const &x, ed::Monomio const &m);


////////////////////////////////////////////////////////////////////////////////


	//! \name Sobrecarga de los operadores de entrada y salida.

	/*!
		\fn			 	 istream &operator >> (istream &stream, ed::Monomio &m).
		\brief     Operador de flujo de entrada: operador que lee desde el flujo de entrada los atributos de un monomio separados por espacios.
		\attention Se sobrecarga el operador de flujo de entrada: ">>".
		\param     stream: objeto de tipo istream pasado como referencia.
		\param     m: objeto de tipo monomio pasado como referencia.
		\sa        ostream &operator << (ostream &stream, ed::Monomio const &m).
	*/
	 istream &operator >> (istream &stream, ed::Monomio &m);


	 /*!
 		\fn			 	 ostream &operator << (ostream &stream, ed::Monomio const &m).
 		\brief     Operador de flujo de salida: operador que escribe en el flujo de salida los atributos del monomio separados por espacios.
 		\attention Se sobrecarga el operador de flujo de salida: "<<".
 		\param     stream: objeto de tipo ostream pasado como referencia.
 		\param     m: objeto de tipo monomio pasado como referencia.
 		\sa        istream &operator >> (istream &stream, ed::Monomio &m).
 	*/
	 ostream &operator << (ostream &stream, ed::Monomio const &m);


////////////////////////////////////////////////////////////////////////////////


}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
