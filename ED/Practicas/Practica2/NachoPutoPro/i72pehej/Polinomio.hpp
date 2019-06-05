/*!
   \file    Polinomio.hpp
   \brief   Definición de la clase Polinomio.
   \author  Julen Pérez Hernández
   \date    31/03/2019
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

////////////////////////////////////////////////////////////////////////////////

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz.
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio.
   private:

  std::vector <Monomio> monomios_;

   //! \name Funciones o métodos públicos de la clase Polinomio.
   public:

////////////////////////////////////////////////////////////////////////////////

	//! \name Constructores de la clase Polinomio.

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Constructor: Crea un nuevo monomio usando coeficiente 0.0 y grado 0.
    \post	     El polinomio creado es nulo.
    \sa        Polinomio (Polinomio const &p).
  */
  Polinomio()
  {
    this->monomios_.clear();
    Monomio m;
    this->monomios_.push_back(m);
  }

  /*!
    \brief     Constructor de copia: Crea un nuevo polinomio a partir de otro polinomio.
    \post	     El polinomio creado es igual al polinomio "p".
    \sa        Polinomio().
  */
  Polinomio(Polinomio const &p)
  {
    this->monomios_.clear();

    for(int i=0; i < p.size(); i++)
    {
      this->setMonomios(p.monomios_[i]);
    }
  }

////////////////////////////////////////////////////////////////////////////////

  //! \name Observadores: funciones de consulta de la clase Polinomio.

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Comprueba si el Polinomio es igual al monomio de coeficiente 0.0 y grado 0.
    \sa        bool esNulo()const, int getGrado()const, int getNumeroMonomios()const, bool existeMonomio(int grado)const,
               Monomio getMonomio(int grado)const, std::vector <Monomio> getMonomios()const, int size()const.
  */
  bool esNulo()const;

  /*!
  \brief     Obtiene el grado del polinomio.
  \pre       Los monomios están ordenados de mayor a menor grado.
  \sa        bool esNulo()const, int getGrado()const, int getNumeroMonomios()const, bool existeMonomio(int grado)const,
             Monomio getMonomio(int grado)const, std::vector <Monomio> getMonomios()const, int size()const.
  */
  int getGrado()const;

  /*!
  \brief     Obtiene el número de monomios del polinomio.
  \sa        bool esNulo()const, int getGrado()const, int getNumeroMonomios()const, bool existeMonomio(int grado)const,
             Monomio getMonomio(int grado)const, std::vector <Monomio> getMonomios()const, int size()const.
  */
  int getNumeroMonomios()const;

  /*!
  \brief     Comprueba si existe el monomio de grado indicado.
  \pre       El polinomio debe existir.
  \sa        bool esNulo()const, int getGrado()const, int getNumeroMonomios()const, bool existeMonomio(int grado)const,
             Monomio getMonomio(int grado)const, std::vector <Monomio> getMonomios()const, int size()const.
  */
  bool existeMonomio(int grado)const;

  /*!
  \brief     Obtiene el monomio de grado indicado.
  \pre       El polinomio debe existir.
  \sa        bool esNulo()const, int getGrado()const, int getNumeroMonomios()const, bool existeMonomio(int grado)const,
             Monomio getMonomio(int grado)const, std::vector <Monomio> getMonomios()const, int size()const.
  */
  Monomio getMonomio(int grado)const;

  /*!
  \brief     Obtiene los monomios del polinomio.
  \sa        bool esNulo()const, int getGrado()const, int getNumeroMonomios()const, bool existeMonomio(int grado)const,
             Monomio getMonomio(int grado)const, std::vector <Monomio> getMonomios()const, int size()const.
  */
	std::vector <Monomio> getMonomios()const {
    return this->monomios_;
  }

  /*!
  \brief     Obtiene el tamaño de cada monomio.
  \sa        bool esNulo()const, int getGrado()const, int getNumeroMonomios()const, bool existeMonomio(int grado)const,
             Monomio getMonomio(int grado)const, std::vector <Monomio> getMonomios()const, int size()const.
  */
  int size()const {
    return (int)this->monomios_.size();
  }

////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones de modificación de la clase Polinomio.

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Introduce un nuevo monomio en el polinomio.
    \sa        void setMonomios(Monomio const &m), static bool ordenaDescendente(Monomio a, Monomio b).
  */
	void setMonomios(Monomio const &m) {
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

  /*!
    \brief     Función de complementación a la inserción de monomios ordenada.
    \sa        void setMonomios(Monomio const &m), static bool ordenaDescendente(Monomio a, Monomio b).
  */
  static bool ordenaDescendente(Monomio a, Monomio b) {
    return a.getGrado() > b.getGrado();
  }

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Función que inicializa el vector a valores nulos.
    \sa        void setMonomios(Monomio const &m), static bool ordenaDescendente(Monomio a, Monomio b).
  */
  void limpiarVector();

////////////////////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

////////////////////////////////////////////////////////////////////////////////

   // Operadores aritméticos y asignación.

////////////////////////////////////////////////////////////////////////////////

 	/*!
 		\brief     Operador de asignación: Operador que copia un polinomio en el polinomo actual.
 		\attention Se sobrecarga el operador "=".
 		\warning   Se requiere que los parámetros tengan el modificador const.
 		\param     p: objeto de tipo polinomio pasado como referencia constante.
 		\pre	     El polinomo "p" debe ser diferente al polinomo actual.
 		\post	     El polinomo actual debe ser igual al polinomo "p".
 		\sa        Polinomio & operator=(Polinomio const &p), Polinomio & operator=(Monomio const &m), Polinomio & operator=(double const &x).
 	*/
	Polinomio & operator=(Polinomio const &p);

  /*!
 		\brief     Operador de asignación: Operador que copia un monomio en el polinomio actual.
 		\attention Se sobrecarga el operador "=".
 		\warning   Se requiere que los parámetros tengan el modificador const.
 		\param     m: objeto de tipo monomio pasado como referencia constante.
 		\post	     El polinomio actual debe tener un único monomio que será igual al monomio "m".
    \sa        Polinomio & operator=(Polinomio const &p), Polinomio & operator=(double const &x).
 	*/
	Polinomio & operator=(Monomio const &m);

  /*!
 		\brief     Operador de asignación: Operador que copia un número en el polinomio actual.
 		\attention Se sobrecarga el operador "=".
 		\warning   Se requiere que los parámetros tengan el modificador const.
 		\param     x: objeto de tipo real pasado como referencia constante.
 		\post	     El polinomo actual debe ser igual al número "x".
    \sa        Polinomio & operator=(Polinomio const &p), Polinomio & operator=(Monomio const &m).
 	*/
	Polinomio & operator=(double const &x);

////////////////////////////////////////////////////////////////////////////////

  // Operadores aritméticos y asignación

////////////////////////////////////////////////////////////////////////////////

  /*!
 		\brief     Operador aritmético y de asignación: Operador de incremento y asignación con otro polinomio.
 		\attention Se sobrecarga el operador "+=".
 		\warning   Se requiere que los parámetros tengan el modificador const.
 		\param     p: objeto de tipo polinomio pasado como referencia constante.
 		\sa        Polinomio & operator+=(Monomio const &m), Polinomio & operator+=(double const &x).
 	*/
	Polinomio & operator+=(Polinomio const &p);

  /*!
 		\brief     Operador aritmético y de asignación: Operador de incremento y asignación con un monomio.
 		\attention Se sobrecarga el operador "+=".
 		\warning   Se requiere que los parámetros tengan el modificador const.
 		\param     m: objeto de tipo monomio pasado como referencia constante.
 		\sa        Polinomio & operator+=(Polinomio const &p), Polinomio & operator+=(double const &x).
 	*/
  Polinomio & operator+=(Monomio const &m);

  /*!
 		\brief     Operador aritmético y de asignación: Operador de incremento y asignación con un número real.
 		\attention Se sobrecarga el operador "+=".
 		\warning   Se requiere que los parámetros tengan el modificador const.
 		\param     x: objeto de tipo real pasado como referencia constante.
 		\sa        Polinomio & operator+=(Polinomio const &p), Polinomio & operator+=(Monomio const &m).
 	*/
  Polinomio & operator+=(double const &x);

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Operador aritmético y de asignación: Operador de decremento y asignación con otro polinomio.
    \attention Se sobrecarga el operador "-=".
    \warning   Se requiere que los parámetros tengan el modificador const.
    \param     p: objeto de tipo polinomio pasado como referencia constante.
    \sa        Polinomio & operator-=(Monomio const &m), Polinomio & operator-=(double const &x).
  */
  Polinomio & operator-=(Polinomio const &p);

  /*!
 		\brief     Operador aritmético y de asignación: Operador de decremento y asignación con un monomio.
 		\attention Se sobrecarga el operador "-=".
 		\warning   Se requiere que los parámetros tengan el modificador const.
 		\param     m: objeto de tipo monomio pasado como referencia constante.
    \sa        Polinomio & operator-=(Polinomio const &p), Polinomio & operator-=(double const &x).
 	*/
  Polinomio & operator-=(Monomio const &m);

  /*!
 		\brief     Operador aritmético y de asignación: Operador de decremento y asignación con un número real.
 		\attention Se sobrecarga el operador "-=".
 		\warning   Se requiere que los parámetros tengan el modificador const.
 		\param     x: objeto de tipo real pasado como referencia constante.
    \sa        Polinomio & operator-=(Polinomio const &p), Polinomio & operator-=(Monomio const &m).
 	*/
  Polinomio & operator-=(double const &x);

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Operador aritmético y de asignación: Operador de multiplicación y asignación por otro polinomio.
    \attention Se sobrecarga el operador "*=".
    \warning   Se requiere que los parámetros tengan el modificador const.
    \param     p: objeto de tipo polinomio pasado como referencia constante.
    \sa        Polinomio & operator*=(Monomio const &m), Polinomio & operator*=(double const &x).
  */
  Polinomio & operator*=(Polinomio const &p);

  /*!
    \brief     Operador aritmético y de asignación: Operador de multiplicación y asignación por un monomio.
    \attention Se sobrecarga el operador "*=".
    \warning   Se requiere que los parámetros tengan el modificador const.
    \param     m: objeto de tipo monomio pasado como referencia constante.
    \sa        Polinomio & operator*=(Polinomio const &p), Polinomio & operator*=(double const &x).
  */
  Polinomio & operator*=(Monomio const &m);

  /*!
    \brief     Operador aritmético y de asignación: Operador de multiplicación y asignación por un número real.
    \attention Se sobrecarga el operador "*=".
    \warning   Se requiere que los parámetros tengan el modificador const.
    \param     x: objeto de tipo real pasado como referencia constante.
    \sa        Polinomio & operator*=(Polinomio const &p), Polinomio & operator*=(Monomio const &m).
  */
  Polinomio & operator*=(double const &x);

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Operador aritmético y de asignación: Operador de división y asignación por otro polinomio.
    \attention Se sobrecarga el operador "/=".
    \warning   Se requiere que los parámetros tengan el modificador const.
    \param     p: objeto de tipo polinomio pasado como referencia constante.
    \pre       El grado de polinomio actual es mayor o igual que el grado del polinomio "p".
    \pre       El polinomio "p" no es nulo.
    \sa        Polinomio & operator/=(Monomio const &m), Polinomio & operator/=(double const &x).
  */
  Polinomio & operator/=(Polinomio const &p);

  /*!
    \brief     Operador aritmético y de asignación: Operador de división y asignación por un monomio.
    \attention Se sobrecarga el operador "/=".
    \warning   Se requiere que los parámetros tengan el modificador const.
    \param     m: objeto de tipo monomio pasado como referencia constante.
    \pre       El grado del monomio debe ser menor o igual que el grado del polinomio actual.
    \pre       El polinomio actual no es nulo.
    \sa        Polinomio & operator/=(Polinomio const &p), Polinomio & operator/=(double const &x).
  */
  Polinomio & operator/=(Monomio const &m);

  /*!
    \brief     Operador aritmético y de asignación: Operador de división y asignación por un número real.
    \attention Se sobrecarga el operador "/=".
    \warning   Se requiere que los parámetros tengan el modificador const.
    \param     x: objeto de tipo real pasado como referencia constante.
    \sa        Polinomio & operator/=(Polinomio const &p), Polinomio & operator/=(Monomio const &m).
  */
  Polinomio & operator/=(double const &x);

////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Lee desde el teclado un polinomio.
    \sa        void escribirPolinomio().
  */
  void leerPolinomio();

  /*!
    \brief     Escribe por pantalla el polinomio donde cada monomio tiene el formato: coeficiente X ^ grado.
    \note      Si el coeficiente es 1 entonces se escribirá X^grado.
    \note      Si el coeficiente es -1 entonces se escribirá -X^grado
    \note      Si el grado es 0 entonces se escribirá solo el coeficiente.
    \note      Si el grado es 1 entonces se escribirá X pero sin grado
    \sa        Polinomio & operator/=(Polinomio const &p), Polinomio & operator/=(Monomio const &m).
  */
  void escribirPolinomio();

////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

////////////////////////////////////////////////////////////////////////////////

  /*!
    \brief     Calcula el valor del polinomio para un número real "x".
  */
  double calcularValor(double x);

////////////////////////////////////////////////////////////////////////////////

}; // Fin de la definición de la clase Polinomio

} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
