#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

struct Point{
		float x, y;
};

Point suma(Point a, Point b){
		Point s;
		s.x=a.x+b.x;
		s.y=a.y+b.y;
return s;
}

/*
//Para el caso de tres variables en vez de un vector.

void imprime(Point p, Point p2, Point p3){
		cout<<"El punto p: ("<<p.x<<" , "<<p.y<<")."<<endl;
		cout<<"El punto p2: ("<<p2.x<<" , "<<p2.y<<")."<<endl;
		cout<<"El punto p3: ("<<p3.x<<" , "<<p3.y<<")."<<endl;
}
*/

void imprime(Point p){
		cout<<"El punto p: ("<<p.x<<" , "<<p.y<<")."<<endl;
}

int main(){

		Point vp[3];
		
		vp[0].x=0;
		vp[0].y=3;
		vp[1].x=4;
		vp[1].y=5;

		vp[2]=suma(vp[0], vp[1]);

		for(int i=0;i<3;i++){imprime(vp[i]);}

system("pause");
}