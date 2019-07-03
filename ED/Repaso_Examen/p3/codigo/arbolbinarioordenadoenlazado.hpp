#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			NodoArbolBinario (const G &info)
			{
				// TODO
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				// TODO
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
				// TODO
			}

			NodoArbolBinario *getIzquierdo() const
			{
				// TODO
			}

			NodoArbolBinario *getDerecho() const
			{
				// TODO
			}

			bool esHoja() const
			{
				// TODO
				return false;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				// TODO
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				// TODO
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				// TODO
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				// TODO
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				// TODO
			}

			void setDerecho(NodoArbolBinario *n)
			{
				// TODO
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				// TODO
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

	public:

		ArbolBinarioOrdenadoEnlazado ()
		{
			// TODO
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			// TODO
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			// TODO
		}

		bool insertar(const G &x)
		{
			bool insertado = false;

			// Caso 1: Árbol vacío.
			if (this->estaVacio()) {this->_raiz = new NodoArbolBinario(x);}
			// Caso 2: Árbol no vacío.
			else {
				// Comienzo desde la raíz.
				this->_padre 	= NULL;
				this->_actual = this->_raiz;

				// Mientras que insertado = false.
				while (!insertado) {
					// Si x es mayor, tiene que ir a la derecha.
					if (x > this->actual()) {
						// Comprobamos que tenga hijo derecho y bajamos, de lo contrario se inserta.
						if (this->_actual->getDerecho()) {
							this->_padre 	= this->_actual;
							this->_actual = this->_actual->getDerecho();
						}
						else {
							this->_actual->setDerecho(new NodoArbolBinario(x));
							// Insertado = true para salir del bucle.
							insertado = true;
						}
					}

					// Si x es menor, tiene que ir a la izquierda.
					if (x < this->actual()) {
						// Comprobamos que tenga hijo izquierdo y bajamos, de lo contrario se inserta.
						if (this->_actual->getIzquierdo()) {
							this->_padre 	= this->_actual;
							this->_actual = this->_actual->getIzquierdo();
						}
						else {
							this->_actual->setIzquierdo(new NodoArbolBinario(x));
							// Insertado = true para salir del bucle.
							insertado = true;
						}
					}
				}
			}

			return (insertado);
		}

		void borrarArbol()
		{
			// TODO
		}

		bool borrar()
		{
			









			return false;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		bool buscar(const G& x) const
		{
			// Si el árbol está vacío
			if (this->estaVacio()) {return false;}
			// De lo contrario, realizamos la búsqueda desde el inicio.
			this->_padre = NULL;
			this->_actual = this->_raiz;

			// Mientras no se llegue al final del árbol, buscamos.
			while (this->_actual != NULL) {
				// Si el elemento buscado es menor, bajamos por la izquierda (si hay).
				if (x < this->actual()) {
					this->_padre = this->_actual;
					this->_actual = this->_actual->getIzquierdo();
				}

				// Si el elemento buscado es mayor, bajamos por la derecha (si hay).
				else if (x > this->actual()) {
					this->_padre = this->_actual;
					this->_actual = this->_actual->getDerecho();
				}

				// Si el elemento buscado no es ni menor ni mayor, es el que buscamos.
				else {
					return true;
				}
			}

			// Dejamos los punteros inalterados.
			this->_padre = NULL;
			this->_actual = this->_raiz;

			return false;
		}

		bool estaVacio() const
		{
			// TODO
			return false;
		}

		G raiz() const
		{
			// TODO
		}

		bool existeActual() const
		{
			// TODO
			return false;
		}

		G actual() const
		{
			// TODO
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
