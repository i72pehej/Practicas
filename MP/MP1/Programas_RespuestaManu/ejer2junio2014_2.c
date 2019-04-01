#include <stdio.h>
#include <stdlib.h>

int *reserva(int tam){
	int *aux;
	aux=(int*)malloc(tam*sizeof(int));
	if(aux==NULL){
		printf("error en la reserva de memoria \n");
		exit(-1);
	}
	else{
		return aux;
	}
}
void rellena(int *v, int tam){
	for (int i = 0; i < tam; ++i)
	{
		scanf("%d",&v[i]);
	}
}
void imprime_recur(int *v,int tam){
	tam--;
	if(tam==0){
		printf("%d\n",v[0] );
	}
	else{
		imprime_recur(v,tam);
		printf("%d\n",v[tam]);
	}

}
int main(){
	int tam;
	int *v;
	scanf("%d",&tam);
	v=reserva(tam);
	rellena(v,tam);
	imprime_recur(v,tam);
	free(v);
	return 0;

}