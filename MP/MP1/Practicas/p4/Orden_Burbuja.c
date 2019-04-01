//PROTOTIPO ORDENACION BURBUJA
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *v;
	int aux, tam;

	for (int i = 0; i < tam; ++i)
	{
		for (int j = 0; j < (tam - i - 1); ++j)
		{
			if (v[j] < v[j + 1])
			{
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}

	return 0;
}