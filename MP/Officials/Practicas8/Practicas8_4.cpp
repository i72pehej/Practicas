#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

//Funciones dentro de estructuras.

struct Point2d{
			float x=0, y=0;
			void set(float vx, float vy){
						x=vx;
						y=vy;
			}
			float dist(){
						return sqrt(x*x+y*y);
			}
};

int main(){

			Point2d p1, p2;
			p1.set(1,2);
			p2.set(3,4);
			cout<<p1.dist()<<endl;
			cout<<p2.dist()<<endl;

system("pause");
}