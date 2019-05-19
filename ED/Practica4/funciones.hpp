#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu()
{
  int opcion;

  system("clear");
  std::cout << "  0. Salir ................................\n";
  std::cout << "  1. Cargar grafo desde fichero ...........\n";
  std::cout << "  2. Algoritmo de Floyd (GD y GND) ......\n";

  std::cout << "Introduzca opcion ...: ";
  cin >> opcion;

  return opcion;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Carga un grafo desde fichero
template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g) {
  string ficheroMatriz, ficheroEtiquetas;

  G_Nodo nodoAux, *nodosAux;
  G_Lado ladoAux, **ladosAux;

  int sizeAux = 0, iAux = 0;

  // Intreducir los ficheros con los que operar.
  std::cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;
  // ficheroMatriz = "matrizAndalucia.txt";
  std::cout << "Fichero de las etiquetas: ";
  cin >> ficheroEtiquetas;
  // ficheroEtiquetas = "Andalucia.txt";

  // Abrimos los ficheros.
  ifstream fMatriz(ficheroMatriz.c_str());
  ifstream fEtiquetas(ficheroEtiquetas.c_str());

  // Control de errores.
  if (!fMatriz.is_open()) {
    std::cout << "\nError al abrir fichero de la matriz." << '\n';

    return false;
  }
  if (!fEtiquetas.is_open()) {
    std::cout << "\nError al abrir fichero de las etiquetas." << '\n';

    return false;
  }

  // Cuenta los nodos leídos desde el fichero para conocer el tamaño asignado al vector de nodos y matriz.
  while (!fEtiquetas.eof() && fEtiquetas >> nodoAux) {
    sizeAux++;
  }

  // Reserva de memoria una vez conocido el tamaño.
  nodosAux = new G_Nodo[sizeAux];
  ladosAux = new G_Lado*[sizeAux];
  for (int i = 0; i < sizeAux; i++) {
    ladosAux[i] = new G_Lado[sizeAux];
  }

  // Reiniciamos el fichero.
  fEtiquetas.close();
  fEtiquetas.open(ficheroEtiquetas.c_str());

  // Introducir los nodos.
  while (!fEtiquetas.eof() && fEtiquetas >> nodoAux) {
    nodosAux[iAux] = nodoAux;
    iAux++;
  }

  // Introducir los lados.
  for (int i = 0; i < sizeAux; i++) {
    for (int j = 0; j < sizeAux; j++) {
      if (!fMatriz.eof() && fMatriz >> ladoAux) {
        ladosAux[i][j] = ladoAux;
      }
    }
  }

  // Cargamos completamente el grafo.
  g -> setLados(ladosAux);
  g -> setNodos(nodosAux);
  g -> setSize(sizeAux);

  // Cerramos los ficheros.
  fEtiquetas.close();
  fMatriz.close();

  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Algoritmo de Floyd.
template <class G_Nodo, class G_Lado>
void algoritmoFloyd(Grafo<G_Nodo, G_Lado> &g) {
  int origen, destino;
  AlgoritmosGrafos<string, int> aux;

  g.matrizRecorridos();
  aux.calcularDistancias(g);

  std::cout << "\nSeleccione la ciudad de ORIGEN:" << '\n';
  std::cout << "\n0.Almeria\n" << "1.Cadiz\n" << "2.Cordoba\n" << "3.Granada\n" << "4.Huelva\n" << "5.Jaen\n" << "6.Malaga\n" << "7.Sevilla\n" << '\n';
  std::cin >> origen;
  std::cout << "Seleccione la ciudad de DESTINO:" << '\n';
  std::cout << "\n0.Almeria\n" << "1.Cadiz\n" << "2.Cordoba\n" << "3.Granada\n" << "4.Huelva\n" << "5.Jaen\n" << "6.Malaga\n" << "7.Sevilla\n" << '\n';
  std::cin >> destino;

  aux.caminoMinimo(origen, destino, g);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
