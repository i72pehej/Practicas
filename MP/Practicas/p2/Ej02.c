//Ejercicio 2 de MEMORIA DINÁMICA.

#include <stdio.h>
#include <stdlib.h>

int separaVector(int limite, int tam, int* v){
	int menores = 0, mayores = 0;
	int *v_menores, *v_mayores;

	for (int i = 0; i < tam; ++i)
	{
		if (*(v + i) <= limite)
		{
			menores++;
		}
		else mayores++;
	}
	printf("Hay <%d> valores menores y <%d> mayores al límite introducido.\n", menores, mayores);
	
	if ((v_menores = (int*) malloc(menores * sizeof(int))) == NULL)
	{
		printf("ERROR. No se pudo reservar memoria.\n");
		return (-1);
	}
	if ((v_mayores = (int*) malloc(mayores * sizeof(int))) == NULL)
	{
		printf("ERROR. No se pudo reservar memoria.\n");
		return (-1);
	}

	int y = 0, z = 0;
	for (int x = 0; x < tam; ++x)
	{
		if (*(v + x) <= limite)
		{
			*(v_menores + y) = *(v + x);
			y++;
		}
		else
		{
			*(v_mayores + z) = *(v + x);
			z++;
		}
	}
	for (int k = 0; k < menores; ++k)
	{
		printf("El vector de los números menores es: <%d>.\n", *(v_menores + k));
	}
	for (int j = 0; j < mayores; ++j)
	{
		printf("El vector de los números mayores es: <%d>.\n", *(v_mayores + j));
	}

	free(v_menores);
	free(v_mayores);
	return 0;
}

int main(int argc, char const *argv[])
{
	int longitud, num;
	int *vector;

	printf("Escriba la longitud del vector.\n");
	scanf("%d", &longitud);
	if ((vector = (int*) malloc(longitud * sizeof(int))) == NULL)
	{
		printf("ERROR. No se pudo reservar memoria.\n");
		return (-1);
	}
	printf("Escriba el límite de separación de los datos del vector.\n");
	scanf("%d", &num);
	printf("\n");

	for (int i = 0; i < longitud; ++i)
	{
		printf("Introduzca un número.\n");
		scanf("%d", vector + i);
	}

	printf("\n");
	separaVector(num, longitud, vector);

	free(vector);
	return 0;
}