#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void lee(float v[ ],int n){			//Introduce los valores del vector.
			float x;
			cout<<"Introduce los valores del vector."<<endl;
			for(int cont=0; cont<n; cont++){
						cin>>x;
						v[cont]=x;
			}
}

void imprime(float v[ ], int n){			//Imprime los valores del vector.
			for(int cont=0; cont<n; cont++){
						cout<<"Los valores del vector son: "<<v[cont]<<endl;
			}
}

int main(){
			int n;
			float v[n];
			cout<<"¿Cuantos valores tendra el vector?"<<endl;
			cin>>n;
			lee(v, n);			//Llama a la función lee.
			imprime(v, n);			//Llama a la función imprime.

cin.ignore();
cin.get();
}