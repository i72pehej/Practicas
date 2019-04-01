#include <stdio.h>
#include <stdlib.h>

struct lista{
	int n;
	struct lista *sig;
};

struct lista *nuevo(){
	struct lista *aux=NULL;
	aux=(struct lista*)malloc(sizeof(struct lista));
	printf("valor del entero\n");
	scanf("%d",&aux->n);
	return aux;
}
void insertar_delante(struct lista **cabeza){
	struct lista *aux=NULL;
	aux=nuevo();
	aux->sig=*cabeza;
	*cabeza=aux;

}
void imprimir_lista(struct lista *cabeza){
	struct lista *aux=NULL;
	aux=cabeza;
	while(aux!=NULL){
		printf("%d\n",aux->n);
	aux=aux->sig;
	}	

}
int menor(struct lista *cabeza){
	struct lista *aux=NULL;
	int menor;
	menor=cabeza->n;
	aux=cabeza;
	while(aux!=NULL){
		if(aux->n < menor){
			menor=aux->n;
		}
		aux=aux->sig;
	}
	return menor;
}
int mayor(struct lista *cabeza){
	struct lista *aux=NULL;
	int mayor;
	mayor=cabeza->n;
	aux=cabeza;
	while(aux!=NULL){
		if(aux->n > mayor){
			mayor=aux->n;
		}
		aux=aux->sig;
	}
	return mayor;
}
int cuenta_p(struct lista *cabeza){
	struct lista *aux=NULL;
	int contador=0;
	aux=cabeza;
	while(aux!=NULL){
		if(aux->n > 0){
			contador++;
		}
		aux=aux->sig;
	}
	return contador;
}
int cuenta_n(struct lista *cabeza){
	struct lista *aux=NULL;
	int contador=0;
	aux=cabeza;
	while(aux!=NULL){
		if(aux->n < 0){
			contador++;
		}
		aux=aux->sig;
	}
	return contador;
}

int main(){
	struct lista *cabeza=NULL;
	int tam;
	printf("cual es el tamaño de la lista\n");
	scanf("%d",&tam);
	for (int i = 0; i < tam; ++i)
	{
		insertar_delante(&cabeza);
	}
	imprimir_lista(cabeza);
	printf("el menor elemento de la lista:%d\n",menor(cabeza));
	printf("el mayor elemento de la lista;%d\n",mayor(cabeza));
	printf("hay %d elementos positivos \n",cuenta_p(cabeza));
	printf("hay %d elementos negativos \n",cuenta_n(cabeza));
	return 0;
}