#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 21

void leeVector(double *cad){
	printf("Escribe una serie de números.\n");
	scanf("%lf", cad);
}

void escribeVector(double *cad){
	printf("La cadena introducida es: '%.0f'.\n", *cad);
}

void sumaPositivos(double *cad){
	double suma_par = 0;

	for (int i = 0; i < MAX; ++i)
	{
		if (*(cad + i) % 2 == 0)	//SIGUE SIN FUNCIONAR 
		{
			suma_par += *(cad + i);
		}
	}
	printf("La suma de los pares introducidos es: <%f>.\n", suma_par);
}

int main(int argc, char const *argv[])
{
	double cadena[MAX];

	leeVector(cadena);
	printf("\n");
	escribeVector(cadena);
	printf("\n");
	sumaPositivos(cadena);
	printf("\n");

	return 0;
}