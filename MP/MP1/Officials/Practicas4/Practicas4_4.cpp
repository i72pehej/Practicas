#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int factorial(int v){
			int i, aux;
			for(i=v, aux=v; v>1; v=v-1){
						i=i-1;
						aux=aux*i;
			}
			int res=aux;
			return res;
}

int main(){
			int n;
			cout<<"Introduce un valor."<<endl;
			cin>>n;
			cout<<"El factorial de "<<n<<" es: "<<factorial(n)<<endl;

cin.ignore();
cin.get();
}