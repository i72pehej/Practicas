#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int espacios(string cad){
		int n=cad.size(), cont=0;
		for(int i=0;i<n;i++){
				if(cad[i]==' '){cont++;}
		}
return cont;
}

int main(){

		string frase;
		getline(cin, frase);
		
		cout<<"La frase tiene "<<espacios(frase)<<" espacios."<<endl;

system("pause");
}