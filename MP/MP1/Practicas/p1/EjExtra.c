//Equivalente al Ej6.c con PUNTEROS A FUNCIONES.

#include <stdio.h>
#include <stdlib.h>

int minimo_V1(int num1, int num2){
	printf("Ejecutando 'minimo_V1'...\n");

	if (num1 < num2)
	{
		return num1;
	}
	else return num2;
}

int minimo_V2(int num1, int num2){
	printf("Ejecutando 'minimo_V2'...\n");
	int resultado;

	if (num1 < num2)
	{
		resultado = num1;
	}
	else resultado = num2;

	return resultado;
}

int main(int argc, char const *argv[])
{
	int num1, num2, sel;
	int (*seleccion)(int, int);

	printf("Introduzca el valor del primer número.\n");
	scanf("%d", &num1);
	printf("Introduzca el valor del segundo número.\n");
	scanf("%d", &num2);
	printf("\n");

	printf("Seleccione la versión para encontrar el mínimo:\n");
	printf("Pulse <1> para V1.\n");
	printf("Pulse <2> para V2.\n");
	scanf("%d", &sel);
	printf("\n");

	if (sel == 1)
	{
		seleccion = &minimo_V1;
	}
	else seleccion = &minimo_V2;

	printf("El menor valor introducido es: %d\n", (*seleccion)(num1, num2));

	return 0;
}