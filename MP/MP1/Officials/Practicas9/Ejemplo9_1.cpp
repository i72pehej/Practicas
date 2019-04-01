#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){

if(argc!=3){
			cout<<"Numero de argumentos incorrecto."<<endl;
			return EXIT_FAILURE;
}

float fe1=stof(argv[1]);			//char[]
float fe2=stof(argv[2]);			//String to float.
float res=fe1+fe2;
cout<<res<<endl;
return EXIT_SUCCESS;

system("pause");
}