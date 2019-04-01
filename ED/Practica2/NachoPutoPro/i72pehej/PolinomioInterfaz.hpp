/*!
   \file    PolinomioInterfaz.hpp
   \brief   Definición de la interfaz de la clase Polinomio
   \author  Julen Pérez Hernández
   \date    31/03/2019
 */

#ifndef _POLINOMIOINTERFAZ_HPP_
#define _POLINOMIOINTERFAZ_HPP_

#include "Monomio.hpp"

// Se incluye la clase PolinomioInterfaz dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase PolinomioInterfaz
class PolinomioInterfaz
{

   //! \name Funciones o métodos públicos de la clase
   public:

	//! \name Observadores: funciones de consulta


  /*!
 		\brief     Asignación para esNulo() de función virtual para valor inicial constante.
		\note 		 Se ha creado una función virtual.
 		\sa        virtual bool esNulo() const = 0, virtual int getGrado()const = 0, virtual int getNumeroMonomios()const = 0, virtual bool existeMonomio(int n)const = 0, virtual ed::Monomio & getMonomio(int n) = 0.
 	*/
  //Descomentar
	virtual bool esNulo() const = 0;


  /*!
 		\brief     Asignación para getGrado() de función virtual para valor inicial constante.
		\note 		 Se ha creado una función virtual.
 		\sa        virtual bool esNulo() const = 0, virtual int getGrado()const = 0, virtual int getNumeroMonomios()const = 0, virtual bool existeMonomio(int n)const = 0, virtual ed::Monomio & getMonomio(int n) = 0.
 	*/
  //Descomentar
	virtual int getGrado()const = 0;


  /*!
 		\brief     Asignación para getNumeroMonomios() de función virtual para valor inicial constante.
		\note 		 Se ha creado una función virtual.
 		\sa        virtual bool esNulo() const = 0, virtual int getGrado()const = 0, virtual int getNumeroMonomios()const = 0, virtual bool existeMonomio(int n)const = 0, virtual ed::Monomio & getMonomio(int n) = 0.
 	*/
  //Descomentar
	virtual int getNumeroMonomios()const = 0;


  /*!
 		\brief     Asignación para existeMonomio() de función virtual para valor inicial constante.
		\note 		 Se ha creado una función virtual.
 		\sa        virtual bool esNulo() const = 0, virtual int getGrado()const = 0, virtual int getNumeroMonomios()const = 0, virtual bool existeMonomio(int n)const = 0, virtual ed::Monomio & getMonomio(int n) = 0.
 	*/
  //Descomentar
	virtual bool existeMonomio(int n)const = 0;


  /*!
 		\brief     Asignación para getMonomio() de valor inicial constante.
		\note 		 Se ha creado una función virtual.
    \param     n: Tipo entero. Grado del monomio que se busca.
 		\sa        virtual bool esNulo() const = 0, virtual int getGrado()const = 0, virtual int getNumeroMonomios()const = 0, virtual bool existeMonomio(int n)const = 0, virtual ed::Monomio & getMonomio(int n) = 0.
 	*/
  //Descomentar
	virtual ed::Monomio & getMonomio(int n) = 0;


}; // Fin de la definición de la clase PolinomioInterfaz

} // \brief Fin de namespace ed.

//  _POLINOMIOINTERFAZ_HPP_
#endif
