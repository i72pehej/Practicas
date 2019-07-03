/*!
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  /*!< Cota de error para la comparación números reales*/

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
/*!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$*/
class Monomio
{
	/*! \name Atributos privados de la clase Monomio*/
	private:
		double coeficiente_;
		int grado_;

	/*! \name Funciones o métodos públicos de la clase Monomio*/
	public:

////////////////////////////////////////////////////////////////////////////////

		/*! \name Constructores de la clase Monomio*/

		Monomio(double coeficiente = 0.0, int grado = 0);

		Monomio(Monomio const &m);

////////////////////////////////////////////////////////////////////////////////

		/*! \name Observadores: funciones de consulta de la clase Monomio*/

		inline double getCoeficiente() {return coeficiente_;}

		inline int getGrado() {return grado_;}

////////////////////////////////////////////////////////////////////////////////

	/*! \name Funciones de modificación de la clase Monomio*/

	inline void setCoeficiente(double nuevoCoeficiente) {this->getCoeficiente() = nuevoCoeficiente;}

	inline void setGrado(int nuevoGrado) {(nuevoGrado >= 0) ? (this->getGrado() = nuevoGrado) : (this->getGrado() = this->getGrado());}

////////////////////////////////////////////////////////////////////////////////

	/*! \name Operadores de la clase Monomio*/

	// Operadores de asignación

		Monomio & operator=(Monomio const &m);

		Monomio & operator=(double const &x);

////////////////////////////////////////////////////////////////////////////////

	// Operadores aritméticos y asignación

		Monomio & operator+=(Monomio const &m);

		Monomio & operator-=(Monomio const &m);

		Monomio & operator*=(Monomio const &m);

		Monomio & operator/=(Monomio const &m);

		Monomio & operator*=(double const &x);

		Monomio & operator/=(double const &x);

////////////////////////////////////////////////////////////////////////////////

	/*! \name Funciones lectura y escritura de la clase Monomio*/

		void leerMonomio();

		void escribirMonomio();

////////////////////////////////////////////////////////////////////////////////

	/*! \name Funciones auxiliares de la clase Monomio*/

		double calculaValor(double numeroReal);

////////////////////////////////////////////////////////////////////////////////

};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
