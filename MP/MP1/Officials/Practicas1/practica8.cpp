#include <iostream>
#include <cmath>
using namespace std;
int main(){

			float x0, x1, y0, y1, x, y, h;
			cout<<"Introduzca la coordenada 'x' del primer punto."<<endl;
			cin>>x0;
			cout<<"Introduzca la coordenada 'y' del primer punto."<<endl;
			cin>>y0;
			cout<<"Introduzca la coordenada 'x' del segundo punto."<<endl;
			cin>>x1;
			cout<<"Introduzca la coordenada 'y' del segundo punto."<<endl;
			cin>>y1;

			x = ( x0 - x1 );
			y = ( y0 - y1 );
			h = sqrt(pow(x,2) + pow(y,2));
			
			cout<<"La distancia entre los dos puntos es: "<<h<<" unidades"<<endl;

cin.ignore();
cin.get();

}

