#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(){

			int n = 1, i =0, aux = 0;

						while(n > 0){
									cout<<"Itroduzca un numero:"<<endl;
									cin>>n;
									if(n > 0){			// Condici�n para evitar errores.
												aux = aux + n;			// Suma los valores introducidos.
												i++;			// N�mero de veces que introducimos un n�mero.
									}
						}
			n = aux / i;			// Calcula la media.
			cout<<"La media de los numeros introducidos es: "<<n<<endl;

cin.ignore();
cin.get();
}