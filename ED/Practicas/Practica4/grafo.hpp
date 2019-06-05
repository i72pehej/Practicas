#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed {

	template <class G_Nodo, class G_Lado>

	class Grafo {

////////////////////////////////////////////////////////////////////////////////

		private:
			// Una variable para guardar el tamaño de los elementos que se necesitan reservar para una matriz cuadrada.
			int _size;

			// Un vector de un tipo parametrizado que representa los nodos del grafo (_nodos).
			G_Nodo *_nodos;

			// Una matriz de un tipo parametrizado que representa los lados del grafo (_lados).
			G_Lado **_lados;

			// Una matriz que representa los recorrridos necesarios para llegar de un nodo a otro.
			G_Lado **_recorridos;

////////////////////////////////////////////////////////////////////////////////

		public:

////////////////////////////////////////////////////////////////////////////////
			// Constructores.
////////////////////////////////////////////////////////////////////////////////

			// Crea un nuevo grafo vacío.
			Grafo () {
				this -> setSize(0);
				this -> setNodos(NULL);
				this -> setLados(NULL);
			}

			// Crea un nuevo grafo inicializando las estructuras para almacenar n nodos.
			Grafo (const int &nNodos) {
				this -> setSize(nNodos);
				this -> getNodos() = new G_Nodo [nNodos];

				// Reserva para las columnas.
				this -> getLados() = new G_Lado *[nNodos];
				// Reserva para las filas.
				for (int i = 0; i < nNodos; i++) {
					this -> getLados()[i] = new G_Lado[nNodos];
				}
			}

			// Crea un nuevo grafo a partir de otro grafo.
			Grafo (const Grafo<G_Nodo, G_Lado> &g) {
				this -> setSize(g.getSize());
				this -> setNodos(g.getNodos());
				this -> setLados(g.getLados());
			}

////////////////////////////////////////////////////////////////////////////////
			// Destructor.
////////////////////////////////////////////////////////////////////////////////

			// Elimina el grafo.
			~ Grafo() {
				this -> borrarGrafo();
				std::cout << "Destructor utilizado." << '\n';
			}

////////////////////////////////////////////////////////////////////////////////
			// Funciones.
////////////////////////////////////////////////////////////////////////////////

			// Borra el grafo liberando la memoria.
			void borrarGrafo() {
				delete [] this -> getNodos();
				for (int i = 0; i < this -> getSize(); i++) {
					delete []this -> getLados()[i];
				}
				delete []this -> getLados();
				this -> setSize(0);
			}

			// Operador de asignación. Operador que copia el grafo “g” en el grafo actual.
			Grafo &operator=(const Grafo<G_Nodo, G_Lado> &g) {
				this -> setSize(g.getSize());
				this -> setNodos(g.getNodos());
				this -> setLados(g.getLados());

				// Se devuelve el grafo completo tras ser modificado.
				return *this;
			}

			// Función para mostrar el vector de nodos.
			void mostrarVector() const{
				std::cout << "\nVector de Nodos:\n"<< '\n';

				for (int i = 0; i < this -> getSize(); i++) {
					std::cout << this -> getNodos()[i] << '\t';
				}
				std::cout << '\n';
			}

			// Función para mostrar la matriz de lados.
			void mostrarMatriz() const{
				std::cout << "\nMatriz de Distancias:\n"<< '\n';

				for(int i = 0; i < this -> getSize(); i++) {
					for(int j = 0; j < this -> getSize(); j++) {
						std::cout << getLados()[j][i] << '\t';
					}
					std::cout << '\n';
				}
				std::cout << '\n';
			}

			// Cración de la matriz de recorridos.
			void matrizRecorridos() {
				this -> _recorridos = new G_Lado *[this -> getSize()];
				for (int i = 0; i < this -> getSize(); i++) {
					getRecorridos()[i] = new G_Lado [getSize()];
				}

				for(int i = 0; i < this -> getSize(); i++){
					//_recorrido[0][i]=_nodos[i];
					for(int j = 0; j < this -> getSize(); j++){
						//cout<<elemN(i)<<endl;
						this -> getRecorridos()[j][i] = i;
					}
					// Quedarse en el mismo lugar.
					this -> getRecorridos()[i][i] = -1;
				}
			}

			// Función para mostrar la matriz de recorridos.
			void mostrarRecorridos() const{
				std::cout << "Matriz de Recorridos:\n" << '\n';

				for(int i = 0; i < this -> getSize(); i++) {
					for(int j = 0; j < this -> getSize(); j++) {
						std::cout << this -> getRecorridos()[j][i] << '\t';
					}
					std::cout << '\n';
				}
				std::cout << '\n';
			}

////////////////////////////////////////////////////////////////////////////////
			// Observadores.
////////////////////////////////////////////////////////////////////////////////

			// Devuelve el tamaño del vector de nodos = filas = columnas.
			int getSize() const {
				return this -> _size;
			}

			// Devuelve el vector de nodos.
			G_Nodo *getNodos() const {
				return this -> _nodos;
			}

			// Devuelve la matriz de lados.
			G_Lado **getLados() const {
				return this -> _lados;
			}

			// Devuelve la matriz de recorridos.
			G_Lado **getRecorridos() const {
				return this -> _recorridos;
			}

////////////////////////////////////////////////////////////////////////////////
			// Modificadores.
////////////////////////////////////////////////////////////////////////////////

			// Asigna el tamaño del vector de nodos.
			void setSize(int x) {
				this -> _size = x;
			}

			// Asigna los nodos al vector de nodos.
			void setNodos(G_Nodo *n) {
				this -> _nodos = n;
			}

			// Asigna los lados a la matriz de lados.
			void setLados(G_Lado **l) {
				this -> _lados = l;
			}

////////////////////////////////////////////////////////////////////////////////

	};
}

#endif
