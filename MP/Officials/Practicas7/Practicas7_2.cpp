#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int digitos(string cad){
			int res=0, a=cad.size();
			for(int i=0; i<a; i++){
						if(isdigit(cad[i])){res++;}			//isdigit() : analiza si lo que hay entre parentesis es un digito decimal.
			}
return res;
}

int main(){
			int x;
			string cad;
			getline(cin, cad);
			x=digitos(cad);
			cout<<"La cadena contiene "<<x<<" numeros."<<endl;

system("pause");
}