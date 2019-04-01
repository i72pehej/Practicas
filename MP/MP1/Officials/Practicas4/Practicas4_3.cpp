#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

float media(int n){
			float sum=0, x, i;
			for(x=n; x>0; x=x-1){
						cout<<"Introduce un valor."<<endl;
						cin>>i;
						sum=sum+i;
			}
			float res=sum/n;
			return res;
}

int main(){
			int valores;
			cout<<"De cuantos valores es la media?"<<endl;
			cin>>valores;
			cout<<"La media de los valores es: "<<media(valores)<<endl;

cin.ignore();
cin.get();
}