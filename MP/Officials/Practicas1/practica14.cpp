#include <iostream>
using namespace std;
int main(){

			int a, b, c;
			cout<<"Introduzca el valor de 'a'."<<endl;
			cin>> a;
			cout<<"Introduzca el valor de 'b'."<<endl;
			cin>> b;

			c = b;
			a = c;
			b = a;

			cout<<"El valor de a: "<<a<<" y el valor de b: "<<b<<endl;

cin.ignore();
cin.get();
}