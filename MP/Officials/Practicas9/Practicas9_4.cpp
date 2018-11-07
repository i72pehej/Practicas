#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){

float res=stof(argv[1]);				//Inicializamos RES con el valor inicial introducido.

string suma="-sum";
string producto="-mult";
string division="-div";
string raiz="-sqrt";

for(int i=2; i<argc; i++){

			if(argv[i]==suma){				//SUMA del valor acumulado más el siguiente valor.
						res=res+stof(argv[i+1]);
						cout<<"La suma es igual a: "<<res<<endl;
			}

			if(argv[i]==producto){				//MULTIPLICACIÓN del valor acumulado por el siguiente valor.
						res=res*stof(argv[i+1]);
						cout<<"El producto es igual a: "<<res<<endl;
			}

			if(argv[i]==division){				//DIVISIÓN del valor acumulado entre el siguiente valor.
						res=res/stof(argv[i+1]);
						cout<<"La division es igual a: "<<res<<endl;
			}

			if(argv[i]==raiz){				//RAÍZ del valor acumulado.
						res=sqrt(res);
						cout<<"La raiz es igual a: "<<res<<endl;
			}
}

cout<<"El resultado final de todas las operaciones es: "<<res<<endl;

system("pause");
}