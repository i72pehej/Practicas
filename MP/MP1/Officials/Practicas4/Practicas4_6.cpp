#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool esprimo(int v){
			bool res;
			int i, j;
			for(i=1, j=0; v>=i; i++){
						if(v%i==0){
									j++;
						}
			}
			if(j==2){
						res=true;
			}
			else{
						res=false;
			}
return res;
}

void primos(int n){
			int a, b;
			for(a=0, b=1; a<n; b++){
						if(esprimo(b)==true){
									cout<<"El numero "<<b<<" es primo."<<endl;
									a++;
						}
			}
}

int main(){
			int x;
			cout<<"Introduzca el numero de primos que desea."<<endl;
			cin>>x;
			primos(x);

cin.ignore();
cin.get();
}