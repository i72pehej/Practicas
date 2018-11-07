#include <stdio.h>
#include <math.h>

int minimo(int a, int b){
	if (a<b)
	{
		return a;
	}
		return b;
}

int minimo_referencia(int x, int y, int *res){
	if (x<y)
		{
			return *res=x;
		}	
		return *res=y;
}

int main(int argc, char const *argv[])
{
	int num1, num2, resultado;

	printf("Introduce un número.");
	scanf("%d", &num1);
	printf("Introduce otro número.");
	scanf("%d", &num2);

	minimo(num1, num2);
	minimo_referencia(num1, num2, &resultado);

	printf("El mínimo en la funcion minimo es:%d\n", minimo);
	printf("El mínimo en la funcion minimo_referencia es:%d\n", minimo_referencia);

	return 0;
}