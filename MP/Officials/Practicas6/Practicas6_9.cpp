#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std; 

//cree aqui su funcion

void stats(float m[4][4], float res[2]){
			float sum=0, dt=0;
			for(int i=0; i<4; i++){
						for(int j=0; j<4; j++){
									sum=sum+m[i][j];
						}
			}
			res[0]=sum/16;			//Calculamos la media.

			for(int x=0; x<4; x++){
						for(int y=0; y<4; y++){
									dt=dt+((m[x][y]-res[0])*(m[x][y]-res[0]));
						}
			}
			dt=dt/16;
			res[1]=sqrt(dt);			//Calculamos la desviacion tipica: Dt=Raiz(Varianza-Media^2).
}

//// 
int test();//indica que la funcion test esta mas abajo
int main(){ 
		test();
		cout<<"Correcto"<<endl;
		system("pause");
		return 0;
}
//funcion de test
 
int test(){
	
	float m[4][4]={ {1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
	float st[2];
	stats(m,st);
	assert( fabs( st[0]-2.5)<1e-3  && fabs(st[1]-1.11803)<1e-3);
	return 0;
}