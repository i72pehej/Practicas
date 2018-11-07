#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void convierte_a_mayusculas(string &cad){
			int n=cad.size();
			for(int i=0; i<n; i++){
						cad[i]=toupper(cad[i]);			//Toupper() : Convierte a mayusculas.
			}
}

int main(){
			string cad;
			getline(cin, cad);
			convierte_a_mayusculas(cad);
			cout<<cad<<endl;

system("pause");
}