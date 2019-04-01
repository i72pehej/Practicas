#include <cmath>
#include <iostream>
using namespace std;
int main(){

			int x = 1, n;
			cout<<"Introduzca un numero para calcular sus divisores."<<endl;
			cin>>n;
			while(x <= n){
						if(n % x == 0){
									cout<<"El numero "<<x<<" es un divisor de "<<n<<"."<<endl;
						}
			x++;
			}

cin.ignore();
cin.get();

}