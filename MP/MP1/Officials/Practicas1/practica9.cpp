#include <iostream>
using namespace std;
int main(){

			int a, b, c;
			cout<<"Introduce el primer numero entero"<<endl;
			cin>> a;
			cout<<"Introduce el segundo numero entero"<<endl;
			cin >> b;
			cout<<"Introduce el tercer numero entero"<<endl;
			cin>> c;

			if ( (a < b) && (c > a) ){
						cout<<"El numero "<<c<<" se encuentra entre el "<<a<<" y el "<<b<<"."<<endl;
			}

			cout<<"FIN"<<endl;

cin.ignore();
cin.get();
}