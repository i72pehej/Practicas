#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"
#include "funciones.hpp"

using namespace std;
using namespace ed;

int main()
{
	Grafo<string,int> aux = Grafo<string, int>();//Creo aux para igualarlo a *g y que *g apunte a algo
	Grafo<string, int> *g = &aux;// Antes me daba una violacion de segmento porque no apuntaba a nada
	int opcion;
	bool grafoIntroducido = false;

	do {
		opcion = menu();
		switch (opcion) {
			case 1: // Cargar grafo desde fichero
			if ( grafoIntroducido )
			(*g).borrarGrafo(); // Si hay un grafo introducido se borra.


			grafoIntroducido = cargarGrafo(g);


			if (grafoIntroducido) {
				cout << "Grafo cargado correctamente \n";
				//Prueba de la asignación y del destructor
				{
					Grafo<string, int> g1 = *g;
				}
			}
			else
			cout << "Grafo no cargado \n";

			getchar();
			getchar();
			break;

			case 2: //Algoritmo de Floyd
			if ( grafoIntroducido )
				algoritmoFloyd(*g);
			else
				cout << "Primero tiene que introducir un grafo\n";
			getchar();
			getchar();
			break;
		}
	} while (opcion!=0);

	return 0;
}
