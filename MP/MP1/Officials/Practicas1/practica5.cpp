#include <iostream>
using namespace std;
int main(){

			int var;
			cout<<"Introduzca un numero"<<endl;
			cin>> var;
			if ( var > 0 ) {
						cout<<"Tu numero ("<<var<<") es mayor que 0."<<endl;
			}
			if ( var == 0 ) {
						cout<<"Tu numero ("<<var<<") es igual a 0."<<endl;
			}
			if (var < 0 ) {
						cout<<"Tu numero ("<<var<<") es menor que 0."<<endl;
			}

cin.ignore();
cin.get();
}