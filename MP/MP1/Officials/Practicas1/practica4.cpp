#include <iostream>
using namespace std;
int main( ) {

		int var;
		cout<< "Introduzca un numero" <<endl;
		cin>>var;
					if ( (var <= 7) && (var >= 1) ) {

								if ( (var >=1) && (var <=5) ) {
										cout<< "Se encuentra en un dia laborable" <<endl;
								}
								else {
										cout<< "Es fin de semana!!" <<endl;
								}
					}
					if ( (var <= 0) && (var > 7) ) {
						cout<<"ERROR!"<<endl;
					}

cin.ignore();
cin.get();
}