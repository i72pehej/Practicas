#include <cmath>
#include <iostream>
using namespace std;

bool esprimo(int v){
			bool res;
			int i, a=0;
			for(i=1; i<=v; i++){
						if(v%i==0){
									a++;
						}
			}
			if(a==2){
						res=true;			// es primo
			}
			else{
						res=false;			// no es primo
			}
return res;
}

int main(){
			int n;
			cout<<"Introduzca un valor."<<endl;
			cin>>n;
			if(esprimo(n)==true){
						cout<<"El valor introducido es primo."<<endl;
			}
			else{
						cout<<"El valor introducido no es primo"<<endl;
			}
cin.ignore();
cin.get();
}