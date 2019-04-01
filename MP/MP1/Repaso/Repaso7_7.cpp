#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool palindromo(string cad){
		int n=cad.size();
		for(int i=0; i<n/2; i++){
				if(cad[i]!=cad[(n-1)-i]){return false;}
		}
		return true;
}

int main(){

		string palabra;
		cin>>palabra;
		if(palindromo(palabra)==1){cout<<"SI."<<endl;}
		else{cout<<"NO."<<endl;}

system("pause");
}