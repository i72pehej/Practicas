#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"
#include "funciones.hpp"

using namespace std;
using namespace ed;

int main() {
	// Grafo grafoAux para que "g" no apunte a un ligar aleatorio.
	Grafo<string,int> grafoAux = Grafo<string, int>();
	Grafo<string, int> *g = &grafoAux;
	int opcion;
	bool grafoIntroducido = false;

	do {
		opcion = menu();
		switch (opcion) {
			case 1: // Cargar grafo desde fichero
				if (grafoIntroducido) {
					// Si hay un grafo introducido se borra.
					g -> borrarGrafo();
				}

				// Comprobación de la carga del grafo.
				grafoIntroducido = cargarGrafo(g);
				if (grafoIntroducido) {
					std::cout << "\n\nGrafo cargado correctamente.\n";
					g -> mostrarVector();
					g -> mostrarMatriz();
					// Prueba de la asignación y del destructor.
					{
						Grafo<string, int> g1 = *g;
					}
				}
				else {std::cout << "\nERROR. Grafo no cargado.\n";}

				getchar();
				getchar();
			break;

			case 2: // Algoritmo de Floyd
				if (grafoIntroducido) {algoritmoFloyd(*g);}
				else {std::cout << "\nPrimero tiene que introducir un grafo\n";}

				getchar();
				getchar();
			break;
		}
	} while (opcion != 0);

	return 0;
}
