#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

string concatena(string a, string b){
			string completo=a+b;			//Une las cadenas de caracteres sin espacio.
return completo;
}

int main(){
			string cad1, cad2;
			cout<<"Introduzca la primera frase que quiera unir."<<endl;
			getline(cin, cad1);
			cout<<"Introduzca la segunda frase que quiera unir."<<endl;
			getline(cin, cad2);
			string x=concatena(cad1, cad2);
			cout<<x<<endl;

system("pause");
}