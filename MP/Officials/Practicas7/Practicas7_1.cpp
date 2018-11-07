#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int espacios(string cad){
			int x=0, a=0;
			a=cad.size();
			for(int i=0; i<a; i++){
						if(cad[i]==' '){x++;}			//Si el elemento es un espacio, aumenta el valor de 'x'.
			}
return x;
}

int main(){
			int x;
			string cad;
			getline(cin, cad);
			x=espacios(cad);
			cout<<"El numero de espacios es: "<<x<<endl;
			
system("pause");
}