/*!
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

#include <cmath>  // Para usar la funciones pow y std::abs
#include <cassert>  // Para controlar las pre y post condiciones mediante asertos

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

namespace ed {  // Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed

//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio {
	//! \name Atributos privados de la clase Monomio
	private:
		double coeficiente_;
		int grado_;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:
	//! \name Constructores de la clase Monomio
	inline Monomio(double coeficiente = 0.0, int grado = 0) {
		#ifndef NDEBUG
			assert(grado >= 0);
		#endif

		setCoeficiente(coeficiente);
		setGrado(grado);

		#ifndef NDEBUG
			assert(std::abs(getCoeficiente() - coeficiente) > COTA_ERROR);
			assert(getGrado() == grado);
		#endif
	}

	inline Monomio(Monomio &m) {
		setCoeficiente(m.getCoeficiente());
		setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(std::abs(getCoeficiente() - m.getCoeficiente()) > COTA_ERROR);
			assert(getGrado() == m.getGrado());
		#endif
	}

	//! \name Observadores: funciones de consulta de la clase Monomio
	inline double getCoeficiente() const {return coeficiente_;}
	inline int getGrado() const {return grado_;}

	//! \name Funciones de modificación de la clase Monomio
	inline void setCoeficiente(double coeficiente) {
		coeficiente_ = coeficiente;

		#ifndef NDEBUG
			assert(std::abs(getCoeficiente() == coeficiente) > COTA_ERROR);
		#endif
	}
	inline void setGrado(int grado) {
		#ifndef NDEBUG
			assert(grado >= 0);
		#endif

		grado_ = grado;

		#ifndef NDEBUG
			assert(getGrado() == grado);
		#endif
	}

	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio
	// Operadores de asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator = (Monomio const &m);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator = (double const &x);


	// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator += (Monomio const &m);


		// COMPLETAR EL RESTO DE OPERADORES


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	// COMPLETAR


};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
