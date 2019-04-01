#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int stoi(const string &cad){
			int v;
			sscanf(cad.c_str(),"%i",&v);
return v;
}

int main(){
			string cad;
			cout<<"Introduzca su D.N.I."<<endl;
			getline(cin, cad);
			int n=cad.size();
			if(n==9){			//Si el tamaño de cad es 9, es correcto.
						char vector_letras[]="TRWAGMYFPDXBNJZSQVHLCKE";			//Se introduce el vector de letras permitidas.
						char letra=vector_letras[std::stoi(cad)%23];			//El caracter char debe ser una de las letras permitidas.
						if(cad[8]==letra){cout<<"Su D.N.I. es correcto."<<endl;}			//Si lo es, el DNI es correcto.
						else{
									cout<<"ERROR. La letra ("<<cad[8]<<") de su D.N.I. no esta permitida."<<endl;			//Si la letra no está permitida.
									cad[8]=letra;			//El programa sustituye la letra incorrecta por la correspondiente al DNI.
									cout<<"Su D.N.I. corregido es: "<<cad<<"."<<endl;									
						}
			}
			else{cout<<"La longitud del D.N.I. introducido no es correcta."<<endl;}

system("pause");
}