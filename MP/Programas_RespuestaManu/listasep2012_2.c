#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int n;
	struct nodo *sig;
};

struct nodo *nuevo_elemento(){
	struct nodo *aux;
	aux=(struct nodo*)malloc(sizeof(struct nodo));
	printf("introduzca el valor de entero\n");
	scanf("%d",&aux->n);
	return aux;
}
 void insertar_delante(struct nodo **cabeza){
 	struct nodo *aux=NULL;
 	aux=nuevo_elemento();
 	aux->sig=*cabeza;
 	*cabeza=aux;
 }
void imprimir(struct nodo *cabeza){
	struct nodo *aux=NULL;
	aux=cabeza;
	while(aux!=NULL){
		printf("%d\n",aux->n);
		aux=aux->sig;
	}
}
int mayor(int a, int b){
	if(a>b){
		return 1;
	}
	else{
		return 0;
	}
}
int menor(int a, int b){
	if(a<b){
		return 1;
	}
	else{
		return 0;
	}

}
int max_min(struct nodo *cabeza, int (*p)(int a, int b)){
	struct nodo *aux=NULL;
	aux=cabeza;
	int Mm=cabeza->n;
	while(aux!=NULL){
		if(((*p)(aux->n,Mm))==1){
			Mm=aux->n;
		}
		aux=aux->sig;
	}
	return Mm;
}
void pn(struct nodo *cabeza){
	int v[2];
	v[0]=0;
	v[1]=0;
	struct nodo *aux=NULL;
	aux=cabeza;
	while(aux!=NULL){
		if(aux->n<0){
			v[0]++;
		}
		if(aux->n>0){
			v[1]++;
		}
		aux=aux->sig;
	}
 	printf("%d\n",v[0]);
 	printf("%d\n",v[1]);
}
 int main(){
 	struct nodo *cabeza=NULL;
 	int tam;
 	int orden;
 	scanf("%d",&orden);
 	scanf("%d",&tam);
 	for (int i = 0; i < tam; ++i)
 	{
 		insertar_delante(&cabeza);
 	}
 	//imprimir(cabeza);
 	if(orden==0){
 		printf("%d\n",max_min(cabeza,menor));
 	}
 	if(orden==1){
 		printf("%d\n",max_min(cabeza,mayor));
 	}
 	pn(cabeza);

 	return 0;
 }