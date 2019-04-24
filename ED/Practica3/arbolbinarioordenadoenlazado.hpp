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

			/*!\brief Constructores.*/

////////////////////////////////////////////////////////////////////////////////

			// Constructor con la información.
			NodoArbolBinario (const G &info) {
				this -> setInfo(info);
				this -> setIzquierdo(NULL);
				this -> setDerecho(NULL);

				// Postcondición: El nodo creado no tiene hijos.
				#ifndef NDEBUG
					assert(this -> esHoja());
				#endif
			}

			// Constructor con otro nodo.
			NodoArbolBinario (const NodoArbolBinario &n) {
				NodoArbolBinario nuevoNodo = new NodoArbolBinario;
				nuevoNodo = n;

				// Postcondición: El nodo creado es igual al nodo "n".
				#ifndef NDEBUG
					assert(nuevoNodo.getInfo()			== n.getInfo());
					assert(nuevoNodo.getIzquierdo() == n.getIzquierdo());
					assert(nuevoNodo.getDerecho()		== n.getDerecho());
				#endif
			}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Observadores.*/

////////////////////////////////////////////////////////////////////////////////

			// Devuelve la información contenida en el nodo.
			const G &getInfo() const {
				return this -> _info;
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
				operador.aplicar(getInfo());
				if(getIzquierdo()) {getIzquierdo() -> recorridoPreOrden(operador);}
				if(getDerecho()) {getDerecho() -> recorridoPreOrden(operador);}
			}

			// Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en inorden.
			void recorridoPostOrden (OperadorNodo<G> &operador) const {
				if(getIzquierdo()) {getIzquierdo() -> recorridoPostOrden(operador);}
				if(getDerecho()) {getDerecho() -> recorridoPostOrden(operador);}
				operador.aplicar(getInfo());
			}

			// Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en postorden.
			void recorridoInOrden (OperadorNodo<G> &operador) const {
				if(getIzquierdo()) {getIzquierdo() -> recorridoInOrden(operador);}
				operador.aplicar(getInfo());
				if(getDerecho()) {getDerecho() -> recorridoInOrden(operador);}
			}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Modificadores. */

////////////////////////////////////////////////////////////////////////////////

			// Establece el valor informativo del nodo actual.
			void setInfo(const G &info) {
				this -> getInfo() = info;
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
					assert(this -> getInfo()			!= n.getInfo());
					assert(this -> getIzquierdo() != n -> getIzquierdo());
					assert(this -> getDerecho()		!= n -> getDerecho());
				#endif

				this.getInfo() = n.getInfo();
				this -> getIzquierdo() = n -> getIzquierdo();
				this -> getDerecho() = n -> getDerecho();

				// Postcondición: El nodo actual debe ser igual al nodo “n”.
				#ifndef NDEBUG
					assert(this -> getInfo()			== n.getInfo());
					assert(this -> getIzquierdo() == n -> getIzquierdo());
					assert(this -> getDerecho()		== n -> getDerecho());
				#endif
			}

		}; //Fin clase NodoArbolBinario

////////////////////////////////////////////////////////////////////////////////

		// Implementación del árbol binario ordenado enlazado.

////////////////////////////////////////////////////////////////////////////////

		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo padre*/

////////////////////////////////////////////////////////////////////////////////

	public:

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Constructores.*/

////////////////////////////////////////////////////////////////////////////////

		// Crea un nuevo árbol vacío.
		ArbolBinarioOrdenadoEnlazado () {
			this -> _raiz 	= NULL;
			this -> _actual = NULL;
			this -> _padre 	= NULL;

			// Postcondición: El árbol creado está vacío.
			#ifndef NDEBUG
				assert(this -> estaVacio());
			#endif
		}

		// Crea un nuevo árbol a partir de otro.
		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G> &a) {
			ArbolBinarioOrdenadoEnlazado nuevoArbol = new ArbolBinarioOrdenadoEnlazado;
			nuevoArbol = a;

			// El árbol creado es igual al árbol "a".
			#ifndef NDEBUG
				assert(this -> _raiz		== a -> _raiz);
				assert(this -> _actual	== a -> _actual);
				assert(this -> padre		== a -> _padre);
			#endif
		}

		// Destructor.
		~ArbolBinarioOrdenadoEnlazado () {
			if (not this -> estaVacio())
			this -> borrarArbol();
			cout << "Destructor Usado \n";
		}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Operadores.*/

////////////////////////////////////////////////////////////////////////////////

		// Operador de asignación.
		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado &a) {
			// Precondición: El árbol “a” debe ser diferente del árbol actual.
			#ifndef NDEBUG
				assert(this -> _raiz		!= a -> _raiz);
				assert(this -> _actual	!= a -> _actual);
				assert(this -> _padre		!= a -> _padre);
			#endif

			this -> _raiz		= a -> _raiz;
			this -> _actual	= a -> _actual;
			this -> _padre	= a -> _padre;

			// Postcondición: El árbol actual debe ser igual al árbol “a”.
			#ifndef NDEBUG
				assert(this -> _raiz		== a -> _raiz);
				assert(this -> _actual	== a -> _actual);
				assert(this -> _padre		== a -> _padre);
			#endif
		}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Modificadores.*/

////////////////////////////////////////////////////////////////////////////////

		// Inserta un elemento en el árbol, el cual deberá mantener el orden.
		bool insertar(const G &x) {
			// Si el árbol se encuentra vacío, creamos un nodo raíz con el elemento.
			if (this -> estaVacio()) {this -> _raiz = NodoArbolBinario(x);}
			else {
				bool insertado = false;

				while (/* condition */) {
					if (/* condition */) {
						if (/* condition */) {
							/* code */
						}

						else {
							/* code */
						}
					}

					else {
						if (/* condition */) {
							/* code */
						}

						else {
							/* code */
						}
					}
				}
			}

			// Postcondición: El elemento debe estar en el árbol. El árbol debe estar ordenado.

			return false;
		}

		// Elimina el árbol por completo.
		void borrarArbol() {
			// Precondición: El árbol no puede estar vacío.
			#ifndef NDEBUG
				assert(not this -> estaVacio());
			#endif

			this -> _raiz 	= NULL;
			this -> _actual = NULL;
			this -> _padre 	= NULL;

			// Postcondición: El árbol debe estar vacío.
			#ifndef NDEBUG
				assert(this -> estaVacio());
			#endif
		}

		// Elimina el nodo apuntado por “_actual”.
		bool borrar() {
			// Precondición: “_actual” debe apuntar a algún nodo.

			// TODO

			// Postcondición: El elemento borrado no debe existir.

			return false;
		}

		// Realiza el recorrido preorden del árbol aplicando el operador “op”.
		void recorridoPreOrden (OperadorNodo<G> &operador) const {
			this -> _raiz -> recorridoPreOrden(operador);
		}

		// Realiza el recorrido postorden del árbol aplicando el operador “op”.
		void recorridoPostOrden (OperadorNodo<G> &operador) const {
			this -> _raiz -> recorridoPostOrden(operador);
		}

		// Realiza el recorrido inorden del árbol aplicando el operador “op”.
		void recorridoInOrden (OperadorNodo<G> &operador) const {
			this -> _raiz -> recorridoInOrden(operador);
		}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Observadores.*/

////////////////////////////////////////////////////////////////////////////////

		// Busca un elemento en el árbol y actualiza el cursor de “_actual” y “_padre” si lo encuentra.
		bool buscar(const G &x) {
			this -> _actual = this -> _raiz;
			this -> _padre = NULL;
			bool encontrado = false;

			// Mientras se encuentren elementos y no se encuentre el elemento buscado...
			while (/*(this -> _actual != NULL)*/ (existeActual()) && (not encontrado)) {
				// Si el elemento buscado es menor que el del nodo actual, se busca por la izquierda.
				if (x < actual()) {
					this -> _padre = this -> _actual;
					if (this -> _actual -> getIzquierdo()) {this -> _actual = this -> _actual -> getIzquierdo();}
					else {this -> _actual = this -> _raiz;}
				}

				// Si el elemento buscado es mayor que el del nodo actual, se busca por la derecha.
				else if (x > actual()) {
					this -> _padre = this -> _actual;
					if (this -> _actual -> getDerecho()) {this -> _actual = this -> _actual -> getDerecho();}
					else {this -> _actual = this -> _raiz;}
				}

				// En caso de no ser ni menor ni mayor, es igual, es decir, se ha encontrado.
				else {encontrado = true;}
			}

			// Postcondición: “_actual” debe apuntar al nodo encontrado, si lo encuentra.
			#ifndef NDEBUG
				if (encontrado) {assert(actual() == x);}
			#endif

			return encontrado;
		}

		// Comprueba si el árbol está vacío.
		bool estaVacio() const {
			if ((this -> _raiz == NULL) && (this -> _actual == NULL) && (this -> _padre == NULL)) {return true;}

			return false;
		}

		// Obtiene el dato almacenado en la raíz.
		G raiz() const {
			// Precondición: El árbol no puede estar vacío.
			#ifndef NDEBUG
				assert(not this -> estaVacio());
			#endif

			this -> _raiz -> getInfo();
		}

		// Comprueba si “_actual” está apuntando a algún nodo.
		bool existeActual() const {
			// Precondición: El árbol no puede estar vacío.
			#ifndef NDEBUG
				assert(not this -> estaVacio());
			#endif

			if (not this -> _actual -> esHoja()) {return true;}

			return false;
		}

		// Devuelve el dato almacenado por el nodo “_actual”.
		G actual() const {
			// Precondición: “_actual” debe de apuntar a algún nodo.
			#ifndef NDEBUG
				assert(this -> existeActual());
			#endif

			return (this -> _actual -> getInfo());
		}

////////////////////////////////////////////////////////////////////////////////

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
