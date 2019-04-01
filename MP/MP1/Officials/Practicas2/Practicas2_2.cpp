#include <cmath>
#include <iostream>
using namespace std;
int main(){

			int n, i, k;
			cout<<"Introduzca un valor positivo."<<endl;
			cin>>n;
			i = n;
			k = n;
			while (n > 0){
						i = i - 1;			// Cálculo de los elementos de n.
						k = k + i;			// La operación de suma de todos los elementos de n.
						n = n - 1;			// La condicion para que se termine el bucle.
			}

			cout<<"La suma de todos sus elementos es: "<<k<<endl;

cin.ignore();
cin.get();
}