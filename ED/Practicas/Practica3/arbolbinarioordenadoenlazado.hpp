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

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

			// Devuelve el puntero al hijo izquierdo.
			NodoArbolBinario *getIzquierdo() const {
				return this -> _izquierdo;
			}

////////////////////////////////////////////////////////////////////////////////

			// Devuelve el puntero al hijo derecho.
			NodoArbolBinario *getDerecho() const {
				return this -> _derecho;
			}

////////////////////////////////////////////////////////////////////////////////

			// Comprueba que el nodo no tenga hijos.
			bool esHoja() const {
				if ((this -> getIzquierdo() == NULL) && (this -> getDerecho() == NULL)) {return true;}
				else {return false;}
			}

////////////////////////////////////////////////////////////////////////////////

			// Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en preorden.
			void recorridoPreOrden (OperadorNodo<G> &operador) const {
				operador.aplicar(getInfo());
				if(getIzquierdo() != NULL) {getIzquierdo() -> recorridoPreOrden(operador);}
				if(getDerecho() != NULL) {getDerecho() -> recorridoPreOrden(operador);}
			}

////////////////////////////////////////////////////////////////////////////////

			// Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en inorden.
			void recorridoPostOrden (OperadorNodo<G> &operador) const {
				if(getIzquierdo() != NULL) {getIzquierdo() -> recorridoPostOrden(operador);}
				if(getDerecho() != NULL) {getDerecho() -> recorridoPostOrden(operador);}
				operador.aplicar(getInfo());
			}

////////////////////////////////////////////////////////////////////////////////

			// Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en postorden.
			void recorridoInOrden (OperadorNodo<G> &operador) const {
				if(getIzquierdo() != NULL) {getIzquierdo() -> recorridoInOrden(operador);}
				operador.aplicar(getInfo());
				if(getDerecho() != NULL) {getDerecho() -> recorridoInOrden(operador);}
			}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Modificadores. */

////////////////////////////////////////////////////////////////////////////////

			// Establece el valor informativo del nodo actual.
			void setInfo(const G &info) {
				this -> _info = info;
			}

////////////////////////////////////////////////////////////////////////////////

			// Establece el puntero al hijo izquierdo del nodo actual.
			void setIzquierdo(NodoArbolBinario *n) {
				this -> _izquierdo = n;
			}

////////////////////////////////////////////////////////////////////////////////

			// Establece el puntero al hijo derecho del nodo actual.
			void setDerecho(NodoArbolBinario *n) {
				this -> _derecho = n;
			}

////////////////////////////////////////////////////////////////////////////////

			// Operador de asignación. Operador que copia el nodo "n" en el nodo actual.
			NodoArbolBinario & operator=(const NodoArbolBinario &n) {
				// Precondición: El nodo “n” debe ser diferente del nodo actual.
				#ifndef NDEBUG
					assert(this -> getInfo()			!= n.getInfo());
					assert(this -> getIzquierdo() != n.getIzquierdo());
					assert(this -> getDerecho()		!= n.getDerecho());
				#endif

				setInfo(n.getInfo());
				setIzquierdo(n.getIzquierdo());
				setDerecho(n.getDerecho());

				// Postcondición: El nodo actual debe ser igual al nodo “n”.
				#ifndef NDEBUG
					assert(this -> getInfo()			== n.getInfo());
					assert(this -> getIzquierdo() == n.getIzquierdo());
					assert(this -> getDerecho()		== n.getDerecho());
				#endif
			}

		}; //Fin clase NodoArbolBinario

////////////////////////////////////////////////////////////////////////////////

		// Implementación del árbol binario ordenado enlazado.

////////////////////////////////////////////////////////////////////////////////

		NodoArbolBinario *_raiz; /*!<La raiz del árbol*/
		NodoArbolBinario *_actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario *_padre; /*!<Cursor al nodo padre*/

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

////////////////////////////////////////////////////////////////////////////////

		// Crea un nuevo árbol a partir de otro.
		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G> &a) {
			ArbolBinarioOrdenadoEnlazado nuevoArbol = new ArbolBinarioOrdenadoEnlazado;
			nuevoArbol = a;

			// El árbol creado es igual al árbol "a".
			#ifndef NDEBUG
				assert(this -> _raiz		== a._raiz);
				assert(this -> _actual	== a._actual);
				assert(this -> padre		== a._padre);
			#endif
		}

////////////////////////////////////////////////////////////////////////////////

		// Destructor.
		~ArbolBinarioOrdenadoEnlazado () {
			if (not (this -> estaVacio()))
			this -> borrarArbol();
			cout << "\tDestructor Usado.\n\n";
		}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Operadores.*/

////////////////////////////////////////////////////////////////////////////////

		// Operador de asignación.
		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado &a) {
			// Precondición: El árbol “a” debe ser diferente del árbol actual.
			#ifndef NDEBUG
				assert(this -> _raiz		!= a._raiz);
				assert(this -> _actual	!= a._actual);
				assert(this -> _padre		!= a._padre);
			#endif

			this -> _raiz		= a._raiz;
			this -> _actual	= a._actual;
			this -> _padre	= a._padre;

			// Postcondición: El árbol actual debe ser igual al árbol “a”.
			#ifndef NDEBUG
				assert(this -> _raiz		== a._raiz);
				assert(this -> _actual	== a._actual);
				assert(this -> _padre		== a._padre);
			#endif
		}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Modificadores.*/

////////////////////////////////////////////////////////////////////////////////

		// Inserta un elemento en el árbol, el cual deberá mantener el orden.
		bool insertar(const G &x) {
			bool insertado = false;

			// Si el árbol se encuentra vacío, creamos un nodo raíz con el elemento.
			if (this -> estaVacio() == true) {this -> _raiz = new NodoArbolBinario(x);}
			else {
				// Se comienza desde la raíz.
				this -> _padre = NULL;
				this -> _actual = this -> _raiz;

				while (not (insertado)) {
					// Si el valor a insertar es mayor al valor del nodo actual...
					if (x > this -> actual()) {
						// Y si el nodo actual tiene hijo derecho, se baja al hijo.
						if (this -> _actual -> getDerecho()) {
							this -> _padre = this -> _actual;
							this -> _actual = this -> _actual -> getDerecho();
						}

						// En caso de no tener hijo derecho, se inserta un nuevo nodo con el elemento.
						else {
							_actual -> setDerecho(new NodoArbolBinario(x));
							insertado = true;
						}
					}

					// En caso contrario, el valor a insertar es menor al valor del nodo actual...
					else {
						// Y si el nodo actual tiene hijo izquierdo, se baja al hijo.
						if (this -> _actual -> getIzquierdo()) {
							this -> _padre = this -> _actual;
							this -> _actual = this -> _actual -> getIzquierdo();
						}

						// En caso de no tener hijo, se inserta un nuevo nodo.
						else {
							this -> _actual -> setIzquierdo(new NodoArbolBinario(x));
							insertado = true;
						}
					}
				}
			}

			// Postcondición: El elemento debe estar en el árbol. El árbol debe estar ordenado.
			#ifndef NDEBUG
				assert(buscar(x));
			#endif

			return insertado;
		}

////////////////////////////////////////////////////////////////////////////////

		// Elimina el árbol por completo.
		void borrarArbol() {
			// Precondición: El árbol no puede estar vacío.
			#ifndef NDEBUG
				assert(this -> estaVacio() == false);
			#endif

			this -> _raiz 	= NULL;
			this -> _actual = NULL;
			this -> _padre 	= NULL;

			// Postcondición: El árbol debe estar vacío.
			#ifndef NDEBUG
				assert(this -> estaVacio() == true);
			#endif
		}

////////////////////////////////////////////////////////////////////////////////

		// Elimina el nodo apuntado por “_actual”.
		bool borrar() {
			// Precondición: “_actual” debe apuntar a algún nodo.
			#ifndef NDEBUG
				assert(this -> existeActual());
			#endif

			// Caso 0: El nodo a borrar es un nodo hoja.
			if (this -> _actual -> esHoja()) {
				// Si el nodo actual es hijo izquierdo, se borra.
				if (this -> _actual == this -> _padre -> getIzquierdo()) {
					this -> _padre -> setIzquierdo(NULL);
					return true;
				}

				// Si el nodo actual es hijo derecho, se borra.
				else {
					this -> _padre -> setDerecho(NULL);
					return true;
				}
			}

			// Caso 1: El nodo a borrar sólo tiene hijo derecho, se sustituye por el hijo.
			else if ((this -> _actual -> getIzquierdo() == NULL) && (this -> _actual -> getDerecho() != NULL)) {
				// Si el nodo actual es hijo izquierdo del nodo padre, lo sustituimos por el hijo del nodo actual.
				if (this -> _actual == this -> _padre -> getIzquierdo()) {
					this -> _padre -> setIzquierdo(this -> _actual -> getDerecho());
					return true;
				}

				// Si el nodo actual es hijo derecho del nodo padre, lo sustituimos por el hijo del nodo actual.
				else {
					this -> _padre -> setDerecho(this -> _actual -> getDerecho());
					return true;
				}
			}

			// Caso 2: El nodo a borrar sólo tiene hijo izquierdo, se sustituye por el hijo.
			else if ((this -> _actual -> getDerecho() == NULL) && (this -> _actual -> getIzquierdo() != NULL)) {
				// Si el nodo actual es hijo izquierdo del nodo padre, lo sustituimos por el hijo del nodo actual.
				if (this -> _actual == this -> _padre -> getIzquierdo()) {
					this -> _padre -> setIzquierdo(this -> _actual -> getIzquierdo());
					return true;
				}

				// Si el nodo actual es hijo derecho del nodo padre, lo sustituimos por el hijo del nodo actual.
				else {
					this -> _padre -> setDerecho(this -> _actual -> getIzquierdo());
					return true;
				}
			}

			// Caso 3: Tiene ambos hijos, por lo que se realiza un intercambio por el sucesor inmediato.
			else {
				// Creamos un nodo auxiliar igual al nodo que se desea borrar para el intercambio.
				NodoArbolBinario *aux = this -> _actual;

				// Movemos el cursor hasta el nodo sucesor inmediato (un movimiento a la derecha y el resto hacia la izquierda).
				this -> _padre = this -> _actual;
				this -> _actual = this -> _actual -> getDerecho();

				while (this -> _actual -> getIzquierdo() != NULL) {
					this -> _padre = this -> _actual;
					this -> _actual = this -> _actual -> getIzquierdo();
				}

				// Intercambio de la información de los nodos.
				G tmpInfo = aux -> getInfo();
				aux -> setInfo(this -> _actual -> getInfo());
				this -> _actual -> setInfo(tmpInfo);

				// Una vez realizado el intercambio, se borra el nodo actual, que ahora es un nodo hoja.
				borrar();
			}

			// Para terminar, se dejan los cursores inalterados.
			this -> _padre = NULL;
			this -> _actual = this -> _raiz;

			// Postcondición: El elemento borrado no debe existir.
			#ifndef NDEBUG
			assert(buscar(this -> _actual -> getInfo()));
			#endif

			return true;
		}

////////////////////////////////////////////////////////////////////////////////

		// Realiza el recorrido preorden del árbol aplicando el operador “op”.
		void recorridoPreOrden (OperadorNodo<G> &operador) const {
			this -> _raiz -> recorridoPreOrden(operador);
		}

////////////////////////////////////////////////////////////////////////////////

		// Realiza el recorrido postorden del árbol aplicando el operador “op”.
		void recorridoPostOrden (OperadorNodo<G> &operador) const {
			this -> _raiz -> recorridoPostOrden(operador);
		}

////////////////////////////////////////////////////////////////////////////////

		// Realiza el recorrido inorden del árbol aplicando el operador “op”.
		void recorridoInOrden (OperadorNodo<G> &operador) const {
			this -> _raiz -> recorridoInOrden(operador);
		}

////////////////////////////////////////////////////////////////////////////////

			/*!\brief Observadores.*/

////////////////////////////////////////////////////////////////////////////////

		// Busca un elemento en el árbol y actualiza el cursor de “_actual” y “_padre” si lo encuentra.
		bool buscar(const G &x) {
			// Si el árbol está vacío, no se puede buscar.
			if (this -> estaVacio() == true) {return false;}
			else {
				// Se comienza la búsqueda desde la raíz.
				this -> _padre = NULL;
				this -> _actual = this -> _raiz;

				// Mientras se encuentren elementos y no se encuentre el elemento buscado...
				while (this -> _actual != NULL) {
					// Si el elemento buscado es menor que el del nodo actual, se busca por la izquierda.
					if (x < this -> actual()) {
						this -> _padre = this -> _actual;
						// Si tiene hijo izquierdo, se baja por el hijo.
						if (this -> _actual -> getIzquierdo() != NULL) {this -> _actual = this -> _actual -> getIzquierdo();}
						// De lo contrario se vuelve a la raíz.
						else {this -> _actual = this -> _raiz;}
					}

					// Si el elemento buscado es mayor que el del nodo actual, se busca por la derecha.
					else if (x > this -> actual()) {
						this -> _padre = this -> _actual;
						// Si tiene hijo derecho, se baja por el hijo.
						if (this -> _actual -> getDerecho() != NULL) {this -> _actual = this -> _actual -> getDerecho();}
						// De lo contrario se vuelve a la raíz.
						else {this -> _actual = this -> _raiz;}
					}

					// En caso de no ser ni menor ni mayor, es igual, es decir, se ha encontrado.
					else {
						// Postcondición: “_actual” debe apuntar al nodo encontrado, si lo encuentra.
						#ifndef NDEBUG
						assert(this -> actual() == x);
						#endif

						return true;
					}
				}

				// Si no se encuentra el elemento, se vuelve al comienzo.
				this -> _padre = NULL;
				this -> _actual = this -> _raiz;

				return false;
			}
		}

////////////////////////////////////////////////////////////////////////////////

		// Comprueba si el árbol está vacío.
		bool estaVacio() const {
			if (this -> _raiz == NULL) {return true;}
			else {return false;}
		}

////////////////////////////////////////////////////////////////////////////////

		// Obtiene el dato almacenado en la raíz.
		G raiz() const {
			// Precondición: El árbol no puede estar vacío.
			#ifndef NDEBUG
				assert(this -> estaVacio() == false);
			#endif

			this -> _raiz -> getInfo();
		}

////////////////////////////////////////////////////////////////////////////////

		// Comprueba si “_actual” está apuntando a algún nodo.
		bool existeActual() const {
			// Precondición: El árbol no puede estar vacío.
			#ifndef NDEBUG
				assert(this -> estaVacio() == false);
			#endif

			if (this -> _actual != NULL) {return true;}
			else {return false;}
		}

////////////////////////////////////////////////////////////////////////////////

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
