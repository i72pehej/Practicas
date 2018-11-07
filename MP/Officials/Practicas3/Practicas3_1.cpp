#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(){

			int menor = 999999, i = 1, aux;
			while(i <= 5){
						cout<<"Itroduzca un numero:"<<endl;
						cin>>aux;
						if(aux < menor){
									menor = aux;
						}
						i++;
			}
			cout<<"El menor de los numeros introducidos es: "<<menor<<endl;


cin.ignore();
cin.get();
}