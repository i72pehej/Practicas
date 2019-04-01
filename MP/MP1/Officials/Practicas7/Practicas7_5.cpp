#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void replace(string &cad, char a, char b){
			int n=cad.size();
			for(int i=0; i<n; i++){
						if(cad[i]==a){cad[i]=b;}
			}
}

int main(){
			string cad;
			char a, b;
			cout<<"Introduzca la frase que quiera modificar."<<endl;
			getline(cin, cad);
			cout<<"Que caracter quiere cambiar?"<<endl;
			cin>>a;
			cout<<"Por que caracter quiere cambiarlo?"<<endl;
			cin>>b;
			replace(cad, a, b);
			cout<<cad<<endl;

system("pause");
}