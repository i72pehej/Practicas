#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){

#ifndef A			//Si no est� definida ...
			#define A 12			//Se define...
#endif			//Fin del IF.

#ifdef WIN32			//Si est� definida... 
			cout<<"Hola Windows."<<endl;
#else
			cout<<"Bye."<<endl;
#endif



float r=A*2;
cout<<r<<endl;

system("pause");
}