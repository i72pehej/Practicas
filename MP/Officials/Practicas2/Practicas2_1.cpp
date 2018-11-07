#include <iostream>
#include <cmath>
using namespace std;
int main(){

			float i = 0, j = 0, k = 0, x;
			cout<<"De cuantos numeros sera la media?"<<endl;
			cin>>i;
			x = i;			// Se asigna a una variable el número de valores que se introduciran para más tarde utilizarlo como divisor.
			while (i > 0) {
						cout<<"Introduzca un valor."<<endl;
						cin>>j;			// Se introducen los diversos valores.
						k = k + j;			// Se suman los todos los valores introducidos.
						i = i - 1;
			}

			k = k / x;			// Se calcula la media.
			cout<<"La media de los valores introducidos es: "<<k<<endl;

cin.ignore();
cin.get();

}