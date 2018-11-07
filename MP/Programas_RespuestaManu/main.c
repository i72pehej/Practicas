#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char *argv[]){
	struct libro *libreria;
	int tam;
	tam=contar_registros(argv[1]);
	printf("%d\n",tam);
	libreria=reserva(tam);
	load(argv[1], libreria, tam);
	for (int i = 0; i < tam; ++i)
	{
		printf("%s\n",libreria[i].titulo);
	}
	escribir(libreria, tam);
	free(libreria);

	
	return 0;
}