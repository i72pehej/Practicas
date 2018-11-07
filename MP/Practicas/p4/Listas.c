//Ejercicios powerpoint -> NUEVO_ELEMENTO // INSERTAR DELANTE/DETRAS // IMPRIMIR // BORRAR ELEMENTO/LISTA

#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int n;
	struct lista* sig;
};

struct lista* nuevoElemento(){
	return((struct lista*)malloc(1 * sizeof(struct lista)));
}

void insertarDelante(struct lista** cabeza, int n){
	struct lista* nuevo = NULL;

	nuevo = nuevoElemento();

	nuevo->n = n;
	nuevo->sig = *cabeza;
	*cabeza = nuevo;
}

void imprimirLista(struct lista* cabeza){
	struct lista* aux = NULL;

	aux = cabeza;
	while(aux != NULL){
		printf("%d\n", aux->n);
		aux = aux->sig;
	}
}

void insertarDestras(struct lista** cabeza, int n){
	struct lista* nuevo = NULL;
	struct lista* aux = NULL;

	nuevo = nuevoElemento();
	nuevo->n = n;
	nuevo->sig = NULL;

	if (*cabeza == NULL)
	{
		*cabeza = nuevo;
	}else{
		aux = *cabeza;

		while(aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void borrarElemento(struct lista** cabeza, int n){
	struct lista* ant = NULL;
	struct lista* aux = NULL;

	aux = *cabeza;
	while(aux->n != n){
		ant = aux;
		aux = aux->sig;
	}

	if (aux == *cabeza)
	{
		*cabeza = aux->sig;
		free(aux);
	}else{
		ant->sig = aux->sig;
		free(aux);
	}
}

void borrarLista(struct lista** cabeza){
	struct lista *aux, *sig;

	aux = *cabeza;
	while(aux != NULL){
		sig = aux->sig;
		free(aux);
		aux = sig;
	}
	*cabeza = NULL;
}

int main(int argc, char const *argv[])
{
	int n;
	struct lista* cabeza = NULL;

	printf("Introduzca elelemento a insertar DELANTE.\n");
	fscanf(stdin, "%d", &n);

	insertarDelante(&cabeza, n);
	printf("El elemento <%d> se ha insertado delante.\n", n);

	return 0;
}