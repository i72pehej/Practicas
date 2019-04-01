#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(int argc, char *argv[]){

		if(argc==1){
				cout<<"Faltan argumentos."<<endl;
				return -1;
		}

		string suma="-sum";
		string prod="-mult";
		string divis="-div";
		string raiz="-sqrt";
		float p_valor=stof(argv[1]);
		int op_pos=2;
		
		while(op_pos<argc){
				if(argv[op_pos]==suma){
						p_valor+=stof(argv[op_pos+1]);
						op_pos+=2;
				}
				if(argv[op_pos]==prod){
						p_valor*=stof(argv[op_pos+1]);
						op_pos+=2;
				}
				if(argv[op_pos]==divis){
						p_valor/=stof(argv[op_pos+1]);
						op_pos+=2;
				}
				if(argv[op_pos]==raiz){
						p_valor=sqrt(p_valor);
						op_pos++;
				}
		}

		cout<<"El resultado es: "<<p_valor<<endl;

system("pause");
}