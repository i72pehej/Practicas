// Prueba ejemplo sencillo => FACTORIAL.C // SUMADIGITOS.C // ESCRIBEVEC.C //

#include <stdlib.h>
#include <stdio.h>

int factorial(int n){
	int resultado;

	if (n == 0)
	{
		resultado = 1;
	}else{
		resultado = n * factorial(n - 1);
	}
	return resultado;
}

int sumaDigitos(int num){
	if (num < 10)
	{
		return num;
	}else{
		return (num % 10 + sumaDigitos(num / 10));
	}
}

void escribeVector(int *V, int posicion){
	if (posicion >= 0)
	{
		escribeVector(V, posicion - 1);
		printf("\t V[%d] = <%d>.", posicion, V[posicion]);
	}
}

int main(int argc, char const *argv[])
{
	int n, num, pos = 3;
	int vec[4] = {1, 2, 3, 4}; 

	printf("Introduzca el número para calcular el factorial.\n");
	scanf("%d", &n);
	printf("Introduzca el número para calcular la suma.\n");
	scanf("%d", &num);

	printf("El factorial es: <%d>.\n", factorial(n));
	printf("La suma es: <%d>.\n", sumaDigitos(num));
	escribeVector(vec, pos);
	printf("\n");

	return 0;
}