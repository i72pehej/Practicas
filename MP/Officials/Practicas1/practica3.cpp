#include <iostream>
#include <cmath>
using namespace std;
int main(){

			float x;
			cout<<"Introduzca un numero para calcular su raiz."<<endl;
			cin>> x;
			
			if (x >= 0){
						x = sqrt (x);    //el programa calcula la raiz del numero
						cout<<"la raiz cuadrada es: "<<x<<endl;
			}
			else {
						cout<<"No se puede calcular la raiz de un numero negativo"<<endl;
			}

cin.ignore();      //borra los datos del buffer de entrada
cin.get();      // espera al usuario para continuar

}