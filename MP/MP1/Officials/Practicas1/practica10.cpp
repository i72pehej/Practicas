#include <iostream>
using namespace std;
int main(){

 			int a, b, c;
			cout<<"Introduce un numero."<<endl;
			cin>>a;
			cout<<"Introduce un numero."<<endl;
			cin>>b;
			cout<<"Introduce un numero."<<endl;
			cin>>c;

			if ((a > b) && (a > c)){
						cout<<"El numero "<<a<<" es mayor que los otros dos numeros."<<endl;
			}
			if ((b > a) && (b > c)){
						cout<<"El numero "<<b<<" es mayor que los otros dos numeros."<<endl;
			}
			if ((c > a) && (c > b)){
						cout<<"El numero "<<c<<" es mayor que los otros dos numeros."<<endl;
			}

cin.ignore();
cin.get();

}