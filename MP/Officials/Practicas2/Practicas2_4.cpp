#include <cmath>
#include <iostream>
using namespace std;
int main(){

//Un numero es impar si n/2 es 1.

			int n, x=0;
			cout<<"Introduzca un numero."<<endl;
			cin>>n;
			while(n >= 0){
						if(n % 2 == 1){
									x = x + n;
						}
						n = n-1;
			}
			cout<<"La suma de los numeros impares que forman el numero es: "<<x<<endl;

cin.ignore();
cin.get();

}