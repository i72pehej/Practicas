#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int vocales(string cad){
			int n=cad.size(), res=0;
			for(int i=0; i<n; i++){
						if(isalpha(cad[i]) && (cad[i]=='a'||cad[i]=='e'||cad[i]=='i'||cad[i]=='o'||cad[i]=='u')){res++;}			//Si es un caracter alfabético y además es una vocal, aumenta el valor de 'res'.
			}
return res;
}

int main(){
			int x;
			string cad;
			getline(cin, cad);
			x=vocales(cad);
			cout<<"La cadena contiene "<<x<<" vocales."<<endl;

    system("pause");
}