#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void fijaValorAleatorio(int v[ ], int n, int max){
			for(int i=0; i<n; i++){
						v[i]=rand()%(max+1);			//Asigna a cada valor del vector un numero aleatorio.
			}
}

int main(){
			srand(time(0));
			for(int i=0; i<10; i++){			//Fija el numero de valores aleatorios que queremos.
						int n=rand()%100;			//Indica el rango de valores posibles (en este caso de 0 a 99).
						cout<<"Los numeros aleatorios son: "<<n<<endl;
			}
system("pause");
}