#include <iostream>
#include <cmath>
using namespace std;
int main(){

			float pra, par, fin, x;
			cout<<"Introduzca la nota de las practicas."<<endl;
			cin>>pra;
			cout<<"Introduzca la nota del examen parcial."<<endl;
			cin>>par;
			cout<<"Introduzca la nota del examen final."<<endl;
			cin>>fin;
			
			x = ( pra*0.25 + par*0.25 + fin*0.5 );
			cout<<"Su nota media es: "<<x<<endl;

cin.ignore();
cin.get();

}

