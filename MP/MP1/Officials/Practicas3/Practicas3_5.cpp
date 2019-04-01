#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(){

			int n, i;
			cout<<"Introduzca un numero para calcular sus divisores."<<endl;
			cin>>n;
			for(i = 1; i <= n; i++){
						if(n % i == 0){
						cout<<"El "<<i<<" es divisor de "<<n<<"."<<endl;
						}
			}

cin.ignore();
cin.get();
}