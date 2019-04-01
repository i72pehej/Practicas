#include <cmath>
#include <iostream>
using namespace std;
int main(){

//un numero es primo si solo tiene dos divisores (él mismo, y 1).

			int i = 1, n, ndiv = 0;
			cout<<"Introduzca un numero para saber si es o no primo."<<endl;
			cin>>n;
			while(i <= n){
						if(n % i == 0 ){
									ndiv++;
						}		
			i++;
			}
			if(ndiv > 2){
						cout<<"No es primo"<<endl;
			}
			else{
						cout<<"Es primo"<<endl;
			}

cin.ignore();
cin.get();

}