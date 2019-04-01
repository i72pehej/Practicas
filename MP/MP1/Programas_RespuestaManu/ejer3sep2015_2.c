#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct fraccion{
	int numerador;
	int denominador;

};

struct fraccion *reserva(int tam){
	struct fraccion *aux;
	aux=(struct fraccion*)malloc(tam*sizeof(struct fraccion));
	return aux;
}
void rellena(struct fraccion *v, int tam){
	for (int i = 0; i < tam; ++i)
	{
		scanf("%d",&v[i].numerador);
		scanf("%d",&v[i].denominador);
	}
}

void imprime(struct fraccion *v, int tam){
	tam--;
	if(tam==0){
		printf("%d/%d\n",v[tam].numerador, v[tam].denominador);
	}
	else{
			printf("%d/%d\n",v[tam].numerador, v[tam].denominador);
			imprime(v,tam);
	}
}
int mayor(float a, float b){
	if(a>b){
		return 1;
	}
	else{
		return 0;
	}
}
int menor(float a, float b){
	if(a<b){
		return 1;
	}
	else{
		return 0;
	}
}
void ordena(struct fraccion *v, int tam, int (*p)(float a, float b)){
	struct fraccion aux;
	double a , b;
	for (int i = 0; i < tam; ++i)
	{
		for (int j = 0; j < tam-1-i; ++j)
		{	
			a=(v[j].numerador/v[j].denominador);
			b=(v[j+1].numerador/v[j+1].denominador);
			printf("%lf\n",a );
			printf("%lf\n",b );
			if(((*p)(a,b))==1){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
}

int main(int argc, char  *argv[])
{	
	struct fraccion *v;
	int orden;
	orden=atoi(argv[1]);
	int tam;
	scanf("%d",&tam);
	v=reserva(tam);
	rellena(v,tam);
	printf("----------------------\n");
	imprime(v,tam);
	if(orden==1){
		ordena(v,tam,&mayor);
	}
	else{
		ordena(v,tam,&menor);
	}
	printf("----------------------\n");
	imprime(v,tam);
	return 0;
}