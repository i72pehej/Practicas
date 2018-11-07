#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(){

			int mayor = -999999, aux = 1;
			for(aux = 1; aux > 0;){
						cout<<"Itroduzca un numero:"<<endl;
						cin>>aux;
						if((aux > mayor)&&(aux > 0)){			// Si se cumple la condición la variable toma el valor introducido.
									mayor = aux;
						}
			}
			cout<<"El mayor de los numeros introducidos es: "<<mayor<<endl;

cin.ignore();
cin.get();
}