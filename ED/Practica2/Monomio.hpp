/*!
	\file Monomio.hpp
	\brief Definición de la clase Monomio.
	\author	Julen Pérez Hernández
	\date		26/02/2019
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

#include <cmath>  // Para usar la funciones pow y std::abs.
#include <cassert>  // Para controlar las pre y post condiciones mediante asertos.
#include <stdlib.h>  // Para las funciones exit.
#include <stdio.h>	//Para el printf.

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales.

namespace ed {  // Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed.


////////////////////////////////////////////////////////////////////////////////


//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$

class Monomio {
	//! \name Atributos privados de la clase Monomio.
	private:
		double coeficiente_;
		int grado_;

	//! \name Funciones o métodos públicos de la clase Monomio.
	public:
		//! \name Constructores de la clase Monomio.

		/*!
			\brief     Constructor de la clase monomio, introduciendo  coeficiente y grado.
			\warning   Se requiere el uso de asertos para comprobar las pre y post condiciones.
			\param     coeficiente: objeto de tipo real pasado con valor inicial 0.0.
			\param     grado: objeto de tipo entero pasado con valor inicial 0.
			\pre			 El grado debe ser mayor o igual que 0.
			\post	     El coeficiente del nuevo monomio debe ser igual al valor introducido.
			\post	     El grado del nuevo monomio debe ser igual al valor introducido.
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        inline Monomio(Monomio &m).
		*/
		inline Monomio(double coeficiente = 0.0, int grado = 0) {
			#ifndef NDEBUG
				assert(grado >= 0);
			#endif

				setCoeficiente(coeficiente);
				setGrado(grado);

			#ifndef NDEBUG
				assert(std::abs(getCoeficiente() - coeficiente) < COTA_ERROR);
				assert(getGrado() == grado);
			#endif
		}


		/*!
			\brief     Constructor de la clase monomio a partir de otro monomio.
			\warning   Se requiere el uso de asertos para comprobar las pre y post condiciones.
			\param     m: objeto de tipo monomio pasado como referencia.
			\post	     El coeficiente del nuevo monomio debe ser igual al valor introducido.
			\post	     El grado del nuevo monomio debe ser igual al valor introducido.
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        inline Monomio(double coeficiente = 0.0, int grado = 0).
		*/
		inline Monomio(Monomio &m) {
			setCoeficiente(m.getCoeficiente());
			setGrado(m.getGrado());

			#ifndef NDEBUG
				assert(std::abs(getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
				assert(getGrado() == m.getGrado());
			#endif
		}


////////////////////////////////////////////////////////////////////////////////


		//! \name Observadores: funciones de consulta de la clase Monomio.

		/*!
			\brief     Observador del coeficiente de la clase monomio.
			\sa        inline int getGrado().
		*/
		inline double getCoeficiente() const {return coeficiente_;}


		/*!
			\brief     Observador del grado de la clase monomio.
			\sa        inline int getCoeficiente().
		*/
		inline int getGrado() const {return grado_;}


////////////////////////////////////////////////////////////////////////////////


		//! \name Funciones de modificación de la clase Monomio.

		/*!
			\brief     Modificador del coeficiente de la clase monomio.
			\warning   Se requiere el uso de asertos para comprobar las pre y post condiciones.
			\param     coeficiente: objeto de tipo real.
			\post	     El coeficiente del nuevo monomio debe ser igual al valor introducido.
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        inline void setGrado(int grado).
		*/
		inline void setCoeficiente(double coeficiente) {
			coeficiente_ = coeficiente;

			#ifndef NDEBUG
				assert(std::abs(getCoeficiente() - coeficiente) < COTA_ERROR);
			#endif
		}


		/*!
			\brief     Modificador del grado de la clase monomio.
			\warning   Se requiere el uso de asertos para comprobar las pre y post condiciones.
			\param     grado: objeto de tipo entero.
			\pre			 El grado debe ser mayor o igual que 0.
			\post	     El grado del nuevo monomio debe ser igual al valor introducido.
			\sa        inline void setCoeficiente(double coeficiente).
		*/
		inline void setGrado(int grado) {
			#ifndef NDEBUG
				assert(grado >= 0);
			#endif

			grado_ = grado;

			#ifndef NDEBUG
				assert(getGrado() == grado);
			#endif
		}


////////////////////////////////////////////////////////////////////////////////


	//! \name Operadores de la clase Monomio.

	// Operadores de asignación.

	/*!
		\brief     Operador de asignación: operador que "copia" un monomio en otro.
		\attention Se sobrecarga el operador de asignación "=".
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\post	     El coeficiente del monomio es igual al coeficiente del monomio "m".
		\post	     El grado del monomio es igual al grado del monomio "m".
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
	*/
		Monomio & operator = (Monomio const &m);


		/*!
			\brief     Operador de asignación: operador que modifica el grado a 0 y el coeficiente a "coeficiente".
			\attention Se sobrecarga el operador de asignación "=".
			\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
			\param     coeficiente: objeto de tipo real pasado como referencia constante.
			\post	     El coeficiente del monomio es igual al coeficiente del monomio "m".
			\post	     El grado del monomio es igual al grado del monomio "m".
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
		*/
		Monomio & operator = (double const &coeficiente);


////////////////////////////////////////////////////////////////////////////////


	// Operadores aritméticos y asignación.
	/*!
		\brief     Operador de asignación y aritmético: operador que le suma al monomio actual otro de igual grado.
		\attention Se sobrecarga el operador "+=".
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
		\param     m: objeto de tipo monomio pasado como referencia constante.
		\pre	     El monomio "m" tiene el mismo grado que el monomio actual.
		\post	     El coeficiente del monomio actual se ha incrementado con el coeficiente del monomio "m".
		\post	     El grado del monomio actual no ha sido modificado.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
	*/
		Monomio & operator += (Monomio const &m);


		/*!
			\brief     Operador de asignación y aritmético: operador que resta al monomio actual otro de igual grado.
			\attention Se sobrecarga el operador "-=".
			\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
			\param     m: objeto de tipo monomio pasado como referencia constante.
			\pre	     El monomio "m" tiene el mismo grado que el monomio actual.
			\post	     El coeficiente del monomio actual se ha decrementado con el coeficiente del monomio "m".
			\post	     El grado del monomio actual no ha sido modificado.
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
		*/
		Monomio & operator -= (Monomio const &m);


		/*!
			\brief     Operador de asignación: operador que multiplica el monomio actual con otro.
			\attention Se sobrecarga el operador "*=".
			\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
			\param     m: objeto de tipo monomio pasado como referencia constante.
			\post	     El coeficiente del monomio actual se ha multiplicado por el coeficiente del monomio "m".
			\post	     El grado del monomio actual se ha incrementado con el grado del monomio "m".
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
		*/
		Monomio & operator *= (Monomio const &m);


		/*!
			\brief     Operador de asignación: operador que divide el monomio actual con otro.
			\attention Se sobrecarga el operador "/=".
			\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
			\param     m: objeto de tipo monomio pasado como referencia constante.
			\pre	     El grado del monomio "m" es igual o inferior al grado del monomio actual.
			\pre	     El coeficiente del monomio "m" no es 0.0.
			\post	     El coeficiente del monomio actual se ha dividido por el coeficiente del monomio "m".
			\post	     El grado del monomio actual se ha decrementado con el grado del monomio "m".
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
		*/
		Monomio & operator /= (Monomio const &m);


		/*!
			\brief     Operador de asignación: operador que multiplica el monomio actual por un número real.
			\attention Se sobrecarga el operador "*=".
			\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
			\param     x: objeto de tipo real pasado como referencia constante.
			\post	     El coeficiente del monomio actual se ha multiplicado por el número real "x".
			\post	     El grado del monomio actual no ha sido modificado.
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
		*/
		Monomio & operator *= (double const &x);


		/*!
			\brief     Operador de asignación: operador que "copia" un monomio en otro.
			\attention Se sobrecarga el operador "/=".
			\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
			\param     x: objeto de tipo real pasado como referencia constante.
			\pre	     El número real "x" no es 0.0.
			\post	     El coeficiente del monomio actual se ha dividido por el número real "x".
			\post      El grado del monomio actual no ha sido modificado.
			\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
		*/
		Monomio & operator /= (double const &x);


////////////////////////////////////////////////////////////////////////////////


	//! \name Funciones lectura y escritura de la clase Monomio.

	/*!
		\brief     Función que lee desde el teclado los atributos del monomio.
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
		\post      El grado del monomio actual es mayor o igual que 0.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
	*/
	void leerMonomio();


	/*!
		\brief     Función que escribe por pantalla los atributos del monomio con el formato: "coeficiente X ^ grado".
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
		\note      Si el grado es 0, entonces se escribirá solo el coeficiente.
		\note      Si el grado es 1, entonces se escribirá X pero sin grado.
		\note	     Si el coeficiente es 1, entonces se escribirá X ^ grado.
		\note      Si el coeficiente es -1, entonces se escribirá -X ^ grado.
		\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
	*/
	void escribirMonomio();


////////////////////////////////////////////////////////////////////////////////


	//! \name Funciones auxiliares de la clase Monomio.

	/*!
		\brief     Función que calcula el valor del monomio para un número real "x".
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const.
		\param     x: objeto de tipo real pasado como referencia constante.
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales.
		\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado().
	*/
	double calcularValor(double const &x);


////////////////////////////////////////////////////////////////////////////////


};  // Fin de la definición de la clase Monomio.
}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
