#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leeVector(int Tam, int *v){
	for (int i = 0; i < Tam; ++i)
	{
		printf("Introduzca un valor.\n");
		scanf("%d", (v + i));
	}
}

void estadisticasVector(int Tam, int *v, float *Med, float *Var, float *Desv){
	float suma = 0;
	float sumaCuadrado = 0;

	for (int i = 0; i < Tam; ++i)
	{
		suma += *(v + i);
	}
	*Med = (suma/Tam);
	printf("La media del vector es: <%.2f>.\n", *Med);

	for (int i = 0; i < Tam; ++i)
	{
		sumaCuadrado += pow(*(v + i), 2);
	}
	*Var = ((sumaCuadrado/Tam) - pow(*Med, 2));
	printf("La varianza del vector es: <%.2f>.\n", *Var);

	*Desv = sqrt(*Var);
	printf("La desviación típica del vector es: <%.2f>.\n", *Desv);
}

void imprimeVector(int Tam, int *v){
	for (int i = 0; i < Tam; ++i)
	{
		printf("Valor nº %d del vector: <%d>.\n", (i + 1), *(v + i));
	}
}

int main(int argc, char const *argv[])
{
	int Dim;
	float Media, Varianza, DesvTip;

	printf("Introduzca la dimensión del vector.\n");
	scanf("%d", &Dim);

	int v[Dim];

	printf("\n");
	leeVector(Dim, v);
	printf("\n");
	imprimeVector(Dim, v);
	printf("\n");
	estadisticasVector(Dim, v, &Media, &Varianza, &DesvTip);
	printf("\n");

	return 0;
}