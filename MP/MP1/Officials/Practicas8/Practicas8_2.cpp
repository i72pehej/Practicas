#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

//Retorno de estructuras.

struct Point2d{
			float x=0, y=0;
};

Point2d suma(Point2d a, Point2d b){
			Point2d res;
			res.x=a.x+b.x;
			res.y=a.y+b.y;
			return res;
}

void set(Point2d &p, float x, float y){
			p.x=x;
			p.y=y;
}

int main(){

			Point2d p1, p2, p3;
			set(p1, 1, 2);
			set(p2, 5, 6);
			p3=suma(p1, p2);

system("pause");
}