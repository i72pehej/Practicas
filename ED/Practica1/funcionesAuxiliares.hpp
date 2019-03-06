/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
	\author Julen Pérez Hernández
  \date   26/02/2019
*/


#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

namespace ed {
	/*!
		\brief   Muestra el menú del programa principal.
		\return  Devuelve el número de opción elegido.
	*/

	int menu();

	/*!
		\brief		Función para comprobar el correcto funcionamiento de la clase Monomio.
		\sa				operadoresExternosMonomios().
	*/
	void testMonomio();


	/*!
		\brief		Función para comprobar el correcto funcionamiento de los operadores externos de la clase Monomio.
		\sa				testMonomio().
	*/
	void operadoresExternosMonomios();

} // Fin del espacio de nombre de la asignatura: ed.

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
