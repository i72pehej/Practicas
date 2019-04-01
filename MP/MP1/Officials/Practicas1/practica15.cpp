#include <iostream>
using namespace std;
int main(){

			int i;
			cout<<"Introduzca un valor del 1 al 7."<<endl;
			cin>> i;
			
			switch (i){

						case 1 :{
						cout<<"Es LUNES"<<endl;
						}break;

						case 2 :{
						cout<<"Es MARTES"<<endl;
						}break;

						case 3 :{
						cout<<"Es MIERCOLES"<<endl;
						}break;

						case 4 :{
						cout<<"Es JUEVES"<<endl;
						}break;

						case 5 :{
						cout<<"Es VIERNES"<<endl;
						}break;

						case 6 :{
						cout<<"Es SABADO"<<endl;
						}break;

						case 7 :{
						cout<<"Es DOMINGO"<<endl;
						}break;

			default :{
						cout<<"Una semana tiene 7 dias :)"<<endl;
						}

			}

cin.ignore();
cin.get();
}