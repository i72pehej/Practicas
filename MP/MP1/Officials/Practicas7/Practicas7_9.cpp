#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int find(string a, string b){
			int tam_a=a.size()-1, tam_b=b.size()-1;
			int i=0, j=0;
			while(i<tam_a && j<tam_b){			//Condición para recorrer las dos cadenas simultaneamente, en funcion del tamaño de 'b'.
						if(a[i]!=b[j]){i++, j=0;}			//Si los elementos son distintos, se avanza en 'a' y 'b' vuelve a la posicion inical.
						else{i++, j++;}			//Si son iguales, continua comparando.
			}
			int pos=i-j+1;			//Calcula la posicion inicial.
			if(j==tam_b){return pos;}			//Si 'j' ha recorrido todo 'b', significa que ha encontrado el elemento y devuelve la posición. 
			else{return -1;}			//No se ha encontrado el elemento.
}

int main(){
			string a, b;
			cout<<"Introduzca la frase en la que quiere buscar."<<endl;
			getline(cin, a);
			cout<<"Introduzca el elemento que quiera buscar."<<endl;
			getline(cin, b);
			int x=find(a, b);
			cout<<x<<endl;

    system("pause");
}