#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(){

			int menor = 999999, i, aux;
			for(i = 1; i <= 5; i++){
						cout<<"Itroduzca un numero:"<<endl;
						cin>>aux;
						if(aux < menor){			// Si se cumple la condición la variable toma el valor introducido.
									menor = aux;
						}
			}
			cout<<"El menor de los numeros introducidos es: "<<menor<<endl;

cin.ignore();
cin.get();
}