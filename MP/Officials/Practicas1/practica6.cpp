#include <iostream>
#include <cmath>
using namespace std;
int main(){

			int a, b, c, d, var;
			cout <<"Introduzca el primer numero."<<endl;
			cin>>a;
			cout <<"Introduzca el segundo numero."<<endl;
			cin>>b;
			cout <<"Introduzca el tercer numero."<<endl;
			cin>>c;
			cout <<"Introduzca el cuarto numero."<<endl;
			cin>>d;

			var = ( ( a + b + c + d ) / 4 );
			cout<<"La media de los numeros introducidos es: "<<var<<endl;

cin.ignore();
cin.get();
}