#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;

		G_Nodo *_nodos;

		int tam_;

	public:

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//constructores
		Grafo()
		{
			cout<<"constructor1"<<endl;
			_lados = NULL;
			_nodos = NULL;
			tam_ = 0;
		}

		Grafo(int nNodos)
		{
			cout<<"constructor2"<<endl;
			//RESERVAR MEMORIA CON FOR
			_lados= new G_Lado*[nNodos];
			for(int i=0;	i<nNodos;	i++)
			{
				_lados[i] = new G_Lado[nNodos];
			}
				G_Nodo _nodos = new G_Nodo[nNodos];
				tam_=nNodos;
		}

		Grafo(const Grafo<G_Nodo,G_Lado> &g)
		{
			cout<<"contructor3"<<endl;
			_lados = g._lados;
			_nodos = g._nodos;
			tam_ = g.tam_;
		}

		// destructor
		~Grafo()
		{
			cout<<"Usando destructor"<<endl;
			borrarGrafo();
			cout<<endl;
			cout<<"Grafo destruido con exito"<<endl;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// funciones
		// Observadores

		int gettam()
		{
			return tam_;
		}

		G_Nodo *getNodo()
		{
			return _nodos;
		}

		G_Lado **getLado()
		{
			return _lados;
		}

		// Modificadores
		void settam(int tam)
		{
			tam_=tam;
		}

		void setLado(G_Lado** lado)
		{
			_lados= lado;
		}

		void setNodo(G_Nodo* nodo)
		{
			_nodos = nodo;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		Grafo & operator=( Grafo & g)
		{
			_lados = g._lados;
			_nodos = g._nodos;
			tam_ = g.tam_;
			//Retorno el grafo modificado
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// Borrar grafo
		void borrarGrafo()
		{	// cabecera indicada para que compile
			_nodos=NULL;

			for(int i=0;	i<tam_;	i++)
			{
				_lados[i]=NULL;
			}
			_lados=NULL;
		}
	};
}

#endif
