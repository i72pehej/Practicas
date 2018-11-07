#include <stdio.h>
#include <stdlib.h>
struct lista{
	int n;
	struct lista *sig;
};

struct lista *nuevo_elemento(){
	struct lista *aux=NULL;
	aux=(struct lista*)malloc(sizeof(struct lista));
	printf("introduzca el valor del entero\n");
	scanf("%d",&aux->n);
	return aux;
}
/*void insertar_delante(struct lista **cabeza){
	struct lista *aux=NULL;
	aux=nuevo_elemento();
	aux->sig=*cabeza;
	*cabeza=aux;

}*/
void insertar_detras(struct lista **cabeza){
	struct lista *aux=NULL;
	struct lista *nuevo=NULL;
	nuevo=nuevo_elemento();
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
void borrar(struct lista **cabeza){
	struct lista *ant=NULL;
	struct lista *aux=NULL;
	aux=*cabeza;
	while(aux->sig!=NULL){
		ant=aux;
		aux=aux->sig;
	}
	if(*cabeza==aux){
		*cabeza=aux->sig;
		free(aux);
	}
	else{
		ant->sig=aux->sig;
		free(aux);
	}
}
void imprime_recursiva(struct lista  *cabeza){
	if(cabeza!=NULL){

	imprime_recursiva(&(cabeza)->sig));
	printf("%d\n",cabeza->n);
	}
}
int main(){
	int tam;
	struct lista *cabeza=NULL;
	scanf("%d",&tam);
	for (int i = 0; i < tam; ++i)
	{
		insertar_detras(&cabeza);
	}
	imprime_recursiva(&cabeza);
	borrar(&cabeza);
	imprime_recursiva(&cabeza);
	return 0;
}