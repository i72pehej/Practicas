#include <iostream>
using namespace std;
int main(){

			int var;
			cout<<"Introduce el numero de mes deseado."<<endl;
			cin>> var;

			if ((var >= 1) && (var <= 12)){

						if (var == 2){
									cout<<"Este mes tiene 28 dias, excepto si es bisiesto, que tiene 29."<<endl;
						}
						if (var == 4){
									cout<<"El mes seleccionado tiene 30 dias."<<endl;
						}
						if (var == 6){
									cout<<"El mes seleccionado tiene 30 dias."<<endl;
						}
						if (var == 9){
									cout<<"El mes seleccionado tiene 30 dias."<<endl;
						}
						if (var == 11){
									cout<<"El mes seleccionado tiene 30 dias."<<endl;
						}

						if (var == 1){
									cout<<"El mes seleccionado tiene 31 dias."<<endl;
						}
						if (var == 3){
									cout<<"El mes seleccionado tiene 31 dias."<<endl;
						}
						if (var == 5){
									cout<<"El mes seleccionado tiene 31 dias."<<endl;
						}
						if (var == 7){
									cout<<"El mes seleccionado tiene 31 dias."<<endl;
						}
						if (var == 8){
									cout<<"El mes seleccionado tiene 31 dias."<<endl;
						}
						if (var == 10){
									cout<<"El mes seleccionado tiene 31 dias."<<endl;
						}
						if (var == 12){
									cout<<"El mes seleccionado tiene 31 dias."<<endl;
						}

			}

cin.ignore();
cin.get();

}