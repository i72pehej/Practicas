#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(){

			int menor = 999999, mayor = -999999, i, aux, sum;
						for(i = 1; i <= 5; i++){
									cout<<"Itroduzca un numero:"<<endl;
									cin>>aux;
									if(aux > 0){
												if(aux < menor){			// Si se cumple la condición la variable toma el valor introducido.
															menor = aux;
												}
												if(aux > mayor){			// Si se cumple la condición la variable toma el valor introducido.
															mayor = aux;
												}
									}
						}
			sum = menor + mayor;
			cout<<"La suma del mayor y menor numero introducido es: "<<sum<<endl;

cin.ignore();
cin.get();
}