//Ejercicios EJEMPLO // TAMAÑO_FICHERO // FICHERO A VECTOR //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX_CLIENTES
#define MAX_CLIENTES 10
#endif

struct clientes
{
	char nombre[15];
	int NIF;
};

void tam_fichero(){
	FILE* f;
	char nombreFichero[30];
	long tam;

	printf("Introduzca el nombre del fichero para saber su tamaño.\n");
	fgets(nombreFichero, 30, stdin);
	if (nombreFichero[strlen(nombreFichero) - 1] == '\n')
	{
		nombreFichero[strlen(nombreFichero) - 1] = '\0';
	}
	printf("El fichero seleccionado es: <%s>.\n", nombreFichero);

	//DEPENDE DEL MODO DE APERTURA "R" o "RB" ABRE UN TIPO U OTRO.
	if ((f = fopen(nombreFichero, "rb")) == NULL)
	{
		printf("El fichero <%s> no se ha podido abrir correctamente.\n", nombreFichero);
		exit(-1);
	}
	if (fseek(f, 0L, SEEK_END) != 0)
	{
		printf("No se pudo realizar la operación deseada en el fichero <%s>.\n", nombreFichero);
		exit(-1);
	}

	tam = ftell(f);
	printf("El fichero <%s> tiene %ld bytes y %.2ld Kbytes.\n", nombreFichero, tam, tam/1024);
//	SI HAY ALGÚN REGISTRO QUE CONTABILIZAR:
//	printf("El fichero <%s> tiene <%d> registros.\n", nombreFichero, tam / sizeof(struct loquesea));

	fclose(f);
}

void ficheroToVector(int tope, char* nombreFichero){
	FILE* f;
	if ((f = fopen(nombreFichero, "rb")) == NULL)
	{
		fprintf(stderr, "El fichero <%s> no se ha podido abrir.\n", nombreFichero);
	}else{
		printf("El fichero <%s> se ha abierto correctamente.\n", nombreFichero);

//		fread y fwrite DEVUELVEN EL NÚMERO DE ELEMENTOS LEÍDOS/ESCRITOS.
		*tope = fread(Clientes, sizeof(struct clientes), MAX_CLIENTES, f);
	}


	fclose(f);	
}

int main(int argc, char const *argv[])
{
	char nombre[30]; 
	int max;
//	struct clientes Clts[4];

	printf("\nIntroduzca el nombre del fichero para pasar a VECTOR.\n");
	fgets(nombre, 30, stdin);
	if (nombre[strlen(nombre) - 1] == '\n')
	{
		nombre[strlen(nombre) - 1] = '\0';
	}

	printf("\nIntroduzca el máximo número de CLIENTES.\n");
	scanf("%d", &max);

	ficheroToVector(&max, nombre);
//	tam_fichero();

	return 0;
}