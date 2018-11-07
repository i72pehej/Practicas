//Ejercicio 6 - Versión1 - minimo.

#include <stdio.h>
#include <stdlib.h>

int minimo(int num1, int num2){
	if (num1 < num2)
	{
		return num1;
	}
	else return num2;
}

void minimo_referencia(int num1, int num2, int* resultado){
	if (num1 < num2)
	{
		*resultado = num1;
	}
	else *resultado = num2;
}

int main(int argc, char const *argv[])
{
	int num1, num2;
	int *resultado;

	printf("Introduzca el valor del primer número.\n");
	scanf("%d", &num1);
	printf("Introduzca el valor del segundo número.\n");
	scanf("%d", &num2);
	printf("\n");

	printf("1º El menor valor introducido es: %d\n", minimo(num1, num2));

	minimo_referencia(num1, num2, resultado);
	printf("2º El menor valor introducido es: %d\n", *resultado);

	return 0;
}