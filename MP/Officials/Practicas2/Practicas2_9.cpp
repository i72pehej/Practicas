#include <cmath>
#include <iostream>
using namespace std;
int main(){

			int n, i=0;
			cout<<"Introduzca un valor para n."<<endl;
			cin>>n;
			while(n != 0){
						if((n % 2 == 0)||(n % 3 == 0)){			// Condicion para que 2 y 3 sean divisores de los valores de n.
									i = i + n; 
						}
			n = n - 1;
			}
			cout<<"La suma de los numeros cuyos divisores son 2 y 3 hasta n es: "<<i<<endl;

cin.ignore();
cin.get();
}