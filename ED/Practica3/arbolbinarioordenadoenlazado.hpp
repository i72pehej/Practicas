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
namespace ed {
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>

	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G> {

	private:

////////////////////////////////////////////////////////////////////////////////

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario {

		private:
			G _info;  //Valor informativo almacenado en el nodo.
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo.
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho.

		public:

////////////////////////////////////////////////////////////////////////////////

			// Constructor con la información.
			NodoArbolBinario (const G &info) {
				setInfo(info);

				#ifndef NDEBUG
					assert(esHoja());
				#endif
			}

			// Constructor con otro nodo.
			NodoArbolBinario (const NodoArbolBinario &n) {
				NodoArbolBinario nuevoNodo = new NodoArbolBinario;
				nuevoNodo = n;

				#ifndef NDEBUG
					assert(nuevoNodo.getInfo() == n.getInfo());
					assert(nuevoNodo.getIzquierdo() == n.getIzquierdo());
					assert(nuevoNodo.getDerecho() == n.getDerecho());
				#endif
			}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Observadores.*/

////////////////////////////////////////////////////////////////////////////////

			// Devuelve la información contenida en el nodo.
			const G &getInfo() const {
				return this._info;
			}

			// Devuelve el puntero al hijo izquierdo.
			NodoArbolBinario *getIzquierdo() const {
				return this -> _izquierdo;
			}

			// Devuelve el puntero al hijo derecho.
			NodoArbolBinario *getDerecho() const {
				return this -> _derecho;
			}

			// Comprueba que el nodo no tenga hijos.
			bool esHoja() const {
				if (this -> getIzquierdo()) {return true;}
				if (this -> getDerecho()) {return true;}

				return false;
			}

			// Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en preorden.
			void recorridoPreOrden (OperadorNodo<G> &operador) const {





				// operador.aplico(?¿?¿getInfo)
				// if(tengo izq)
				// 	getizq()
				// 	preorden(operador)
				// if(tengo dere)
				// 	getDerecho()
				// 	preorden(opera)





			}

			// Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en inorden.
			void recorridoPostOrden (OperadorNodo<G> &operador) const {
				// TODO
			}

			// Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en postorden.
			void recorridoInOrden (OperadorNodo<G> &operador) const {
				// TODO
			}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Modificadores. */

////////////////////////////////////////////////////////////////////////////////

			// Establece el valor informativo del nodo actual.
			void setInfo(const G &info) {
				getInfo() = info;
			}

			// Establece el puntero al hijo izquierdo del nodo actual.
			void setIzquierdo(NodoArbolBinario *n) {
				this -> getIzquierdo() = n -> getIzquierdo();
			}

			// Establece el puntero al hijo derecho del nodo actual.
			void setDerecho(NodoArbolBinario *n) {
				this -> getDerecho() = n -> getDerecho();
			}

			// Operador de asignación. Operador que copia el nodo "n" en el nodo actual.
			NodoArbolBinario & operator=(const NodoArbolBinario &n) {
				// Precondición: El nodo “n” debe ser diferente del nodo actual.
				#ifndef NDEBUG
					assert(this.getInfo() != n.getInfo());
					assert(this -> getIzquierdo() != n -> getIzquierdo());
					assert(this -> getDerecho() != n -> getDerecho());
				#endif

				this.getInfo() = n.getInfo();
				this -> getIzquierdo() = n -> getIzquierdo();
				this -> getDerecho() = n -> getDerecho();

				// Postcondición: El nodo actual debe ser igual al nodo “n”.
				#ifndef NDEBUG
					assert(this.getInfo() == n.getInfo());
					assert(this -> getIzquierdo() == n -> getIzquierdo());
					assert(this -> getDerecho() == n -> getDerecho());
				#endif
			}

		}; //Fin clase NodoArbolBinario

////////////////////////////////////////////////////////////////////////////////

		// Implementación del árbol binario ordenado enlazado.

////////////////////////////////////////////////////////////////////////////////

		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

////////////////////////////////////////////////////////////////////////////////

	public:


		ArbolBinarioOrdenadoEnlazado () {
			// TODO
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a) {
			// TODO
		}

		~ArbolBinarioOrdenadoEnlazado () {
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado &a) {
			// TODO
		}

		bool insertar(const G &x) {
			// TODO

			return false;
		}

		void borrarArbol() {
			// TODO
		}

		bool borrar() {
			// TODO

			return false;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const {
			// TODO
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const {
			// TODO
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const {
			// TODO
		}

		bool buscar(const G &x) const {
			// TODO

			return false;
		}

		bool estaVacio() const {
			// TODO

			return false;
		}

		G raiz() const {
			// TODO
		}

		bool existeActual() const {
			// TODO

			return false;
		}

		G actual() const {
			// TODO
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
