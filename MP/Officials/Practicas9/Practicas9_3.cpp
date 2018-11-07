#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){

//Suponemos que la fecha se introduce separando cada elemento con espacios: dd mm aaaa.

if(argc!=4){
			cout<<"El formato de fecha es incorrecto. Introduzcalo correctamente: dd mm aaaa."<<endl;
return EXIT_FAILURE;
}

int aaaa=stof(argv[3]);				//Como el año es un número entero, da igual que se considere INT o FLOAT.
float resto_bien=aaaa%4;
float resto_mal=aaaa%100;

//Es bisiesto siempre que sea divisible entre 4 excepto si es divisible entre 100.

if(resto_mal==0){
			cout<<"La fecha de nacimiento introducida no es bisiesta."<<endl;
return EXIT_FAILURE;
}

if(resto_bien!=0){
			cout<<"La fecha de nacimiento introducida no es bisiesta."<<endl;
return EXIT_FAILURE;
}

if(resto_bien==0){
			cout<<"La fecha de nacimiento introducida es bisiesta."<<endl;
return EXIT_SUCCESS;
}

system("pause");
}