#include <cmath>
#include <iostream>
using namespace std;
int main(){

			int n, i = 0, f = 0;
			cout<<"Introduzca un valor positivo para calcular su factorial."<<endl;
			cin>>n;
			i = n, f = n;
			while(n > 1){
						i = i - 1;			// Calcula los elementos del número.
						f = f * i;			// Calcula el producto de todos los elementos.
						n = n - 1;
			}
			cout<<"El factorial del numero introducido es: "<<f<<endl;

cin.ignore();
cin.get();
}