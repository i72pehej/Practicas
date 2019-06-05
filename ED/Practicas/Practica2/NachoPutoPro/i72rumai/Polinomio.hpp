/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>
#include <algorithm>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:

  std::vector <Monomio> monomios_;

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

  Polinomio()
  {
    this->monomios_.clear();
    Monomio m;
    this->monomios_.push_back(m);
  }

  Polinomio (Polinomio const &p)
  {
    this->monomios_.clear();

    for(int i=0; i < p.size(); i++)
    {
      this->setMonomios(p.monomios_[i]);
    }
  }

  //! \name Observadores: funciones de consulta de la clase Polinomio

	std::vector <Monomio> getMonomios()const{
    return this->monomios_;
  }

  int size() const {

      return (int)this->monomios_.size();

  }

  int getGrado()const{
    return this->monomios_[0].getGrado();
  }


	//! \name Funciones de modificación de la clase Polinomio

	void setMonomios(Monomio const &m)
  {
    for(int i=0; i < this->size(); i++)
    {
      if( this->monomios_[i].getGrado() == m.getGrado() )
      {
        this->monomios_[i].setCoeficiente( this->monomios_[i].getCoeficiente() + m.getCoeficiente() );
        return ;
      }
    }

    this->monomios_.push_back(m);

    sort(this->monomios_.begin(), this->monomios_.end(), ordenaDescendente);

  }

  static bool ordenaDescendente(Monomio a, Monomio b)
  {
    return a.getGrado() > b.getGrado();
  }

  void leerPolinomio();

  void escribirPolinomio()const;

  bool esNulo()const;

  int getGrado();

  int getNumeroMonomios();

  bool existeMonomio(int grado);

  Monomio getMonomio(int grado)const;

  void limpiarVector();
 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);

  Polinomio & operator+=(Monomio const &m);

  Polinomio & operator+=(double const &x);

  Polinomio & operator-=(Polinomio const &p);

  Polinomio & operator-=(Monomio const &m);

  Polinomio & operator-=(double const &x);

  Polinomio & operator*=(Polinomio const &p);

  Polinomio & operator*=(Monomio const &m);

  Polinomio & operator*=(double const &x);

  Polinomio & operator/=(Polinomio const &p);

  Polinomio & operator/=(Monomio const &m);

  Polinomio & operator/=(double const &x);

	// COMPLETAR EL RESTO DE OPERADORES


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio
  void eliminaCeros();

	double calcularValor(double x);


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
