#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){

float suma=0;

for(int i=1; i<argc; i++){
			suma=suma+stof(argv[i]);				//Suma de los valores, transformados string to float.
}

float media=suma/(argc-1);
cout<<"La media de los valores es: "<<media<<endl;

return EXIT_SUCCESS;

system("pause");
}