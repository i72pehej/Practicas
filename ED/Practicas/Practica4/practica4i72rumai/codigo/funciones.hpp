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

int menu()
{
  int opcion;

  system("clear");
  cout << "  0. Salir................................\n";
  cout << "  1. Cargar grafo desde fichero...........\n";
  cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

  cout << "Introduzca opcion...:";
  cin >> opcion;

  return opcion;
}

template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
{
  G_Nodo * nodos;
  G_Lado ** lados;
  G_Nodo nodo;
  G_Lado lado;
  int cont=0;
  int iter=0;

  string ficheroMatriz, ficheroEtiquetas;

  cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;

  cout << "Fichero de las etiquetas: ";
  cin >> ficheroEtiquetas;

  ifstream fm(ficheroMatriz.c_str());
  ifstream fe(ficheroEtiquetas.c_str());
  if(!fm.is_open())
  {
    return false;
  }
  if(!fe.is_open())
  {
    return false;
  }

  while(!fe.eof() && fe>>nodo)
  {
    cont++;
  }
    nodos = new G_Nodo[cont];
    lados = new G_Lado*[cont];

  for(int i=0;  i<cont;i++)
    {
      lados[i]=new G_Lado[cont];
    }
  fe.close();

  fe.open(ficheroEtiquetas.c_str());
  while(!fe.eof() && fe>>nodo)
  {
    nodos[iter] = nodo;
    iter++;
  }
  for(int i=0;  i<cont; i++)
  {
    for(int j=0;  j<cont; j++)
    {
      if(!fm.eof() && fm>>lado)
      {
        lados[i][j] = lado;
      }
    }
  }
  g->setLado(lados);
  g->setNodo(nodos);
  g->settam(cont);

  fm.close();
  fe.close();
  return true;
}

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
  
}

#endif
