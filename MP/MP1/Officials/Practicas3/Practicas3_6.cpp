#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(){

			int n, i, aux = 0;
			cout<<"Introduzca un numero para saber si es primo."<<endl;
			cin>>n;	
			for(i = 1; i <= n; i++){
						if(n % i == 0){
									aux++;
						}
			}
			if(aux == 2){
						cout<<"El numero es primo."<<endl;
			}
			else{
						cout<<"El numero no es primo."<<endl;
			}

cin.ignore();
cin.get();
}