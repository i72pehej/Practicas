#ifndef __ALGORITMOSGRAFOS_H__
#define __ALGORITMOSGRAFOS_H__
#include <iostream>

#include "grafo.hpp"
using namespace ed;
using namespace std;

template <class G_Nodo, class G_Lado>
class AlgoritmosGrafos {
  public:
////////////////////////////////////////////////////////////////////////////////

    void calcularDistancias(Grafo<G_Nodo, G_Lado> &g) {
    	int aux;

      // Calcula la distancia.
    	for (int k = 0; k < g.getSize(); k++) {
        g.getLados()[k][k] = 0;
    		for (int i = 0; i < g.getSize(); i++) {
    			for (int j = 0; j < g.getSize(); j++) {
            if (g.getLados()[i][k] + g.getLados()[k][j] < g.getLados()[i][j]) {
              aux = g.getLados()[i][k] + g.getLados()[k][j];
              g.getLados()[i][j] = aux;
              g.getRecorridos()[i][j] = k;
            }
          }
        }
      }

      // En caso de ser el mismo se coloca un -1.
      for(int i = 0; i < g.getSize(); i++) {
        for(int j = 0; j < g.getSize(); j++) {
          if(g.getRecorridos()[i][j] == j) {
            g.getRecorridos()[i][j] = -1;
          }
        }
      }

      // Muestra resultados.
      g.mostrarRecorridos();
      g.mostrarMatriz();
    }

////////////////////////////////////////////////////////////////////////////////

    void caminoMinimo(int i , int j, Grafo<G_Nodo, G_Lado> &g) {
      std::cout << "Distancia del viaje: " << g.getLados()[i][j] << '\n';
      std::cout << "Recorrido:" << '\n';
      std::cout << i << " > ";

      while(g.getRecorridos()[i][j] != -1) {
        i = g.getRecorridos()[i][j];
        std::cout << i << " > ";
      }
      std::cout << j << '\n';
    }

////////////////////////////////////////////////////////////////////////////////

};

#endif
