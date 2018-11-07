#include <cmath>
#include <iostream>
using namespace std;
int main(){

			int x, n;
			cout<<"Introduzca un numero para calcular sus divisores."<<endl;
			cin>>n;
			while(x > 0){
						if(n % x == 0){
									cout<<"El numero "<<x<<" es un divisor de "<<n<<"."<<endl;
						}
			x = x-1;
			}

cin.ignore();
cin.get();

}