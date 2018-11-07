#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

void divisores(int v){
			int i;
			for(i=1; i<=v; i++){
						if(v%i==0){
									cout<<"El numero "<<i<<" es divisor de "<<v<<"."<<endl;
						}
			}	
}

int main(){
			int n;
			cout<<"Introduzca un valor."<<endl;
			cin>>n;
			divisores(n);

cin.ignore();
cin.get();
}