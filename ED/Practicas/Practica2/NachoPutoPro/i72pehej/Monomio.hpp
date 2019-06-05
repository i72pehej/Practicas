/*!
	\file Monomio.hpp
	\brief Definición de la clase Monomio
	\author Ignacio Antonio Ruiz Martin - Romo
	\date 19-02-1999
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

	// COMPLETAR
	double coeficiente_;
	int grado_;


	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio
	/*!
		\brief     Constructor parametrizado que crea un nuevo monomio usando los argumentos(coeficiente y grado)
		\warning   Los parámetros tienen valores por defecto
		\param     coeficiente: valor del coeficiente del monomio por defecto 0.0
		\param     grado: valor del grado del monomio por defecto 0
		\pre       No hay
		\post	     El coeficiente del monomio es igual al valor del parámetro “coeficiente”
		\post	     El grado del monomio es igual al valor del parámetro “grado”
		\note	     Se utiliza COTA_ERROR para el control de la precisión de los números reales
	*/
	// COMPLETAR
	inline Monomio(double coeficiente=0.0,int grado=0)
	{
		#ifndef NDEBUG
			assert(grado	>=	0);
		#endif //NDEBUG

		setCoeficiente(coeficiente);
		setGrado(grado);

		#ifndef NDEBUG
			assert(std::abs(getCoeficiente()	-	coeficiente)	<	COTA_ERROR);
			assert(getGrado()==grado);
		#endif//NDEBUG
	}
	/*!
	\brief     Constructor de "copia" que crea un Monomio a partir de otro Monomio
	\param     m: Monomio utilizado para igualar los valores iniciales del Monomio
	\pre       Ninguna
	\post	   El coeficiente del monomio creado es igual al coeficiente del monomio “m”
	\post	   El grado del monomio creado es igual al grado del monomio “m”.
	\note	   Se debe utilizar COTA_ERROR para el control de la precisión de los números reales
*/
	inline Monomio(Monomio const& m)
	{
		setCoeficiente(m.coeficiente_);
		setGrado(m.grado_);

		#ifndef NDEBUG
			assert(std::abs(getCoeficiente()==m.coeficiente_)	> COTA_ERROR);
			assert(getGrado()==m.grado_);
		#endif
	}


	//! \name Observadores: funciones de consulta de la clase Monomio
	//! \name Funciones de modificación de la clase Monomio

	// COMPLETAR
	/*!
			\brief se le asigna un valor "x" al valor coeficiente de un Monomio
			\param x: nuevo valor del coeficiente de un Monomio(tipo double)
			\pre   Ninguna
			\post  El coeficiente del monomio es igual al número real “x”
			\note  Se utiliza la COTA_ERROR para el control de la precisión de los números reales
		*/
	void setCoeficiente(double x)
	{
		coeficiente_=x;
	}
	/*!
			\brief   Función que retorna el coeficiente de un Monomio
			\return  Coeficiente del Monomio
			\pre     Ninguna
			\post    Ninguna
		*/
	double getCoeficiente()const
	{
		return coeficiente_;
	}
	/*!
			\brief Función que asigna un valor "n" al valor grado de un Monomio
			\param grado: nuevo valor del grado de un Monomio
			\pre   El número entero “grado” es mayor o igual que 0
			\post  El grado del monomio es igual al número entero “grado”
			\note  Se utiliza COTA_ERROR para el control de la precisión de los números reales
		*/
	void setGrado(int n)
	{
		#ifndef NDEBUG
			assert(n >= 0);
		#endif
			grado_=n;

	}
	/*!
			\brief   Función que devuelve el grado de un Monomio
			\return  Grado del Monomio
			\pre     Ninguna
			\post    Ninguna
		*/

	int getGrado()const
	{
		return grado_;
	}



	// COMPLETAR



	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		/*!
		\brief     Operador de asignación: Devuelve el monomio actual que ha sido modificado con los atributos del monomio “m”.
		\attention Se sobrecarga el operador de asignación "="
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const
		\param  m: Objeto de tipo Monomio pasado como referencia constante
		\pre       Ninguna
		\post	 		 El coeficiente del monomio es igual al coeficiente del monomio “m”
		\post	   	 El grado del monomio es igual al grado del monomio “m”
		\note	   Se utiliza COTA_ERROR para el control de la precisión de los números reales
	*/

		Monomio & operator=(Monomio const &m);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		/*!
		\brief     Operador de asignación: Devuelve el monomio actual que ha sido modificado para que su grado sea 0
							 y su coeficiente sea el número real “x”
		\attention Se sobrecarga el operador de asignación "="
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const
		\param  x: Elemento de tipo double pasado como referencia constante
		\pre       Ninguna
		\post	 		 El grado del monomio es igual 0
		\post	   	 El coeficiente del monomio es igual al número real “x”
		\note	     Se utiliza COTA_ERROR para el control de la precisión de los números reales
	*/
		Monomio & operator=(double const &x);



	// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		// Operadores aritméticos y asignación

		/*!
		\brief     Operador aritmético y de asignación: Modifica el monomio sumándole otro monomio de igual grado
		\attention Se sobrecarga el operador de asignación "+="
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const
		\param  m: Objeto de tipo monomio pasado como referencia constante
		\pre       El monomio “m” tiene el mismo grado que el monomio actual
		\post	 		 El coeficiente del monomio actual se ha incrementado con el coeficiente del monomio “m”
		\post	   	 El grado del monomio actual no ha sido modificado
		\note	     Se utiliza la COTA_ERROR para el control de la precisión de los números reales
	*/
		Monomio & operator+=(Monomio const &m);

		// COMPLETAR EL RESTO DE OPERADORES
		/*!
		\brief     Operador aritmético y de asignación: Modifica el monomio restándole otro monomio de igual grado
		\attention Se sobrecarga el operador de asignación "-="
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const
		\param  m: Objeto de tipo monomio pasado como referencia constante
		\pre       El monomio “m” tiene el mismo grado que el monomio actual
		\post	 		 El coeficiente del monomio actual se ha decrementado con el coeficiente del monomio “m”
		\post	   	 El grado del monomio actual no ha sido modificado
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
			*/
		Monomio & operator-=(Monomio const &m);
		/*!
		\brief     Operador aritmético y de asignación: Modifica el monomio multiplicado por otro monomio
		\attention Se sobrecarga el operador de asignación "*="
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const
		\param  m: Objeto de tipo monomio pasado como referencia constante
		\pre       Ninguna
		\post	 		 El coeficiente del monomio actual se ha multiplicado por el coeficiente del monomio “m”
		\post	   	 El grado del monomio actual se ha incrementado con el grado del monomio “m”
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
	*/
		Monomio & operator*=(Monomio const &m);
		/*!
		\brief     Operador aritmético y de asignación: Modifica el monomio dividiéndolo por otro monomio
		\attention Se sobrecarga el operador de asignación "/="
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const
		\param  m: Objeto de tipo monomio pasado como referencia constante
		\pre       El grado del monomio “m” es igual o inferior al grado del monomio actual
		\pre       El coeficiente del monomios “m” no es 0.0
		\post	 		 El coeficiente del monomio actual se ha dividido por el coeficiente del monomio “m”
		\post	   	 El grado del monomio actual se ha decrementado con el grado del monomio “m”
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
	*/
		Monomio & operator/=(Monomio const &m);
		/*!
		\brief     Operador aritmético y de asignación: Modifica el monomio multiplicándolo por un número real
		\attention Se sobrecarga el operador de asignación "*="
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const (preguntar profesor)
		\param  x: Elemento de tipo double pasado como referencia constante
		\pre       Ninguna
		\post	 		 El coeficiente del monomio actual se ha multiplicado por un número real “x”
		\post	   	 El grado del monomio actual no ha sido modificado
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
	*/
		Monomio & operator*=(double const &x);
		/*!
		\brief     Operador aritmético y de asignación: Modifica el monomio dividiéndolo por un número real
		\attention Se sobrecarga el operador de asignación "/="
		\warning   Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const
		\param  x: Elemento de tipo double pasado como referencia constante
		\pre       El número real “x” no es 0.0
		\post	 		 El coeficiente del monomio actual se ha dividido por un número real “x”
		\post	   	 El grado del monomio actual no ha sido modificado
		\note	     Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
	*/
		Monomio & operator/=(double const &x);


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	// COMPLETAR
	/*!
		\brief   Asigna a un Monomio un coeficiente y un grado, leí­dos desde el teclado
		\pre     Ninguna
		\post    El grado del monomio es mayor o igual que 0
	*/
		void leerMonomio();
		/*!
			\brief Escribe por pantalla los atributos del monomio con el formato: (coeficienteX^grado)
			\pre   Ninguna
			\post  Ninguna
			\note  Si el coeficiente es 1 entonces se escribirá X^grado
			\note  Si el coeficiente es -1 entonces se escribirá -X^grado
			\note  Si el grado es 0 entonces se escribirá solo el coeficiente
			\note  Si el grado es 1 entonces se escribirá X pero sin grado
		*/
		void escribirMonomio();

	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio
	/*!
		\brief Calcula el valor del Monomio para un número real “x”: coeficiente*x^grado
		\param x: Elemento de tipo double
		\pre   Ninguna
		\post  Ninguna
	*/
		double calcularValor(double x);
			// COMPLETAR



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
