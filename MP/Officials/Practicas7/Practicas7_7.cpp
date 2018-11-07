#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool palindromo(string cad){
			int x=cad.size()-1, z=cad.size();
			for(int i=0; i<z/2; i++){				//Recorre la mitad del string.
						if(cad[i]!=cad[x]){return false;}
			x--;			//Recorre el string de manera inversa.
			}
return true;
}

int main(){
			string a;
			cout<<"Introduza la frase para comprobar si es un palindromo."<<endl;
			getline(cin, a);
			int x=palindromo(a);
			if(x==1){cout<<"Es palindromo."<<endl;}
			else{cout<<"No es palindromo."<<endl;}

system("pause");
}