#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

//Vector de estructuras.

struct Point2d{
			float x=0, y=0;
};

int main(){

			Point2d v[10];
			for(int i=0;i<10;i++){
						v[i].x=i;
						v[i].y=(i+1)*2;
			}

system("pause");
}