#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int n;
	struct nodo *sig;
};

struct nodo *nuevo_elemento(){
	struct nodo *aux;
	aux=(struct nodo*)malloc(sizeof(struct nodo));
	scanf("%d",&aux->n);
	return aux;
}
void insertar_detras(struct nodo **cabeza){
	struct nodo *aux=NULL;
	struct nodo *nuevo=NULL;
	nuevo=nuevo_elemento();
	nuevo->sig=NULL;
	if(*cabeza==NULL){
		*cabeza=nuevo;
	}
	else{
		aux=*cabeza;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
	aux->sig=nuevo;
	}
}
void imprimir_recursivo(struct nodo *cabeza){
	if(cabeza!=NULL){
	printf("%d\n",cabeza->n);
	imprimir_recursivo(cabeza->sig);
	}
}

void borrar(struct nodo **cabeza, int x){
	struct nodo *aux=NULL;
	struct nodo *ant=NULL;
	aux=*cabeza;
	while(aux->n!=x){
		ant=aux;
		aux=aux->sig;
	}
	if(aux==*cabeza){
		*cabeza=aux->sig;
		free(aux);
	}
	else{
		ant->sig=aux->sig;
		free(aux);
	}
}
int *buscarMm(struct nodo *cabeza){
	int *v;
	v=malloc(2*sizeof(int));
	struct nodo *aux=NULL;
	aux=cabeza;
	v[0]=cabeza->n;
	v[1]=cabeza->n;
	while(aux!=NULL){
		if(aux->n<v[0]){
			v[0]=aux->n;
		}
		if(aux->n>v[1]){
			v[1]=aux->n;
		}
	aux=aux->sig;
	}
	return v;
}
int main(){
	struct nodo *cabeza=NULL;
	int *v;
	v=malloc(2*sizeof(int));
	for (int i = 0; i < 5; ++i)
	{
		insertar_detras(&cabeza);
	}
	printf("---------------------------------------------------\n");
	imprimir_recursivo(cabeza);
	//borrar(&cabeza,5);
	printf("---------------------------------------------------\n");
	//imprimir_recursivo(cabeza);
	v=buscarMm(cabeza);
	printf("menor:%d\n",v[0]);
	printf("mayor:%d\n",v[1]);
	free(v);
	return 0;
}