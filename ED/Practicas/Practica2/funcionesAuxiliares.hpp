/*!
  \file    funcionesAuxiliares.hpp
  \brief   Funciones auxiliares para el programa principal de la práctica 2
	\author  Julen Pérez Hernández
	\date    31/03/2019
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_


namespace ed
{
	/*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*!
 		\brief     Test sobre la clase Polinomio para comprobación de su correcto funcionamiento.
 		\attention Pueden surgir errores no previstos.
 		\warning   Se requiere que los errores sean corregidos para la correcta comprobación.
 		\sa        void testPolinomio(), void operadoresExternosPolinomios().
 	*/
	void testPolinomio();

	/*!
 		\brief     Test sobre los operadores externos a la clase Polinomio para comprobación de su correcto funcionamiento.
 		\attention Pueden surgir errores no previstos.
 		\warning   Se requiere que los errores sean corregidos para la correcta comprobación.
 		\sa        void testPolinomio(), void operadoresExternosPolinomios().
 	*/
	void operadoresExternosPolinomios();

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
