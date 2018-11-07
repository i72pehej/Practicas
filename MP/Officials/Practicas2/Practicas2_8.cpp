#include <cmath>
#include <iostream>
using namespace std;
int main(){

			int n, i = 2, x = 0, v = 1, aux;
			cout<<"¿Cuantos numeros de la sucesion de Fibonacci deseas?"<<endl;
			cin>>n;
			if(n < 2){
						cout<<"La sucesion de Fibonacci es: "<<x<<endl;
			}
			else{
						cout<<"La sucesion de Fibonacci es: "<<x<<endl;
						cout<<"La sucesion de Fibonacci es: "<<v<<endl;
			}
// Los dos primeros valores quedarían definidos con el bloque anterior.

			while(i < n){
						aux = x + v;			// Utilizo una variable auxiliar para ir intercambiando los valores.
						x = v;
						v = aux;
						i++;
						cout<<"La sucesion de Fibonacci es: "<<v<<endl;
			}

cin.ignore();
cin.get();

}