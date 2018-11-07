#include <stdio.h>
#include <stdlib.h>

struct fraccion{
	int numerador;
	int denominador;

};
struct nodo{
	struct fraccion f;
	struct nodo *sig;
};

struct nodo *nuevo_elemento(){
	struct nodo *aux=NULL;
	aux=(struct nodo*)malloc(sizeof(struct nodo));
	scanf("%d",&aux->f.numerador);
	scanf("%d",&aux->f.denominador);
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

void imprime_recursivo(struct nodo *cabeza){
	
	if(cabeza!=NULL){
		imprime_recursivo(cabeza->sig);
		printf("%d/%d\n",cabeza->f.numerador, cabeza->f.denominador);
	}
}
void imprime(struct nodo *cabeza){
	while(cabeza!=NULL){
		printf("%d/%d\n",cabeza->f.numerador, cabeza->f.denominador);
		cabeza=cabeza->sig;
	}
}
void borrar_ultimo(struct nodo **cabeza){
	struct nodo *aux=NULL;
	struct nodo *ant=NULL;
	aux=*cabeza;
	while(aux->sig!=NULL){
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
int main(){
	int tam;
	struct nodo *cabeza=NULL;
	scanf("%d",&tam);
	for (int i = 0; i < tam; ++i)
	{
		insertar_detras(&cabeza);
	}
	//imprime(cabeza);
	imprime_recursivo(cabeza);
	borrar_ultimo(&cabeza);
	imprime_recursivo(cabeza);
	return 0;
}