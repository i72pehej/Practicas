#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){

if(stof(argv[1])<0){				//Si el valor es menor que 0...
			cout<<"El valor introducido es negativo."<<endl;
return EXIT_FAILURE;
}

if(argc!=2){				//Si no existe el segundo argumento, que es el valor a introducir...
			cout<<"Numero de valores incorrecto."<<endl;
return EXIT_FAILURE;
}

float val1=stof(argv[1]);				//String to float el valor introducido para operar.
float res=sqrt(val1);				//Raiz del valor.
cout<<"La raiz es: "<<res<<endl;

return EXIT_SUCCESS;
system("pause");
}