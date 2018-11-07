#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 21

void cuentaDigitos(char *cad){
	char *ptr;
	int cont = 0;

	for (ptr = cad; *ptr != '\0'; ptr++)
	{
		if (isdigit(*ptr))
		{
			cont++;
		}
	}
	printf("Se ha(n) introdicido <%d> dígito(s).\n", cont);
}

void cuentaMayusculas(char *cad){
	char *ptr;
	int cont = 0;

	for (ptr = cad; *ptr != '\0'; ptr++)
	{
		if (isupper(*ptr))
		{
			cont++;
		}
	}
	printf("Se ha(n) introdicido <%d> letra(s) mayúscula(s).\n", cont);
}

void cuentaMinusculas(char *cad){
	char *ptr;
	int cont = 0;

	for (ptr = cad; *ptr != '\0'; ptr++)
	{
		if (islower(*ptr))
		{
			cont++;
		}
	}
	printf("Se ha(n) introdicido <%d> letra(s) minúscula(s).\n", cont);
}

void cuentaEspacios(char *cad){
	char *ptr;
	int cont = 0;

	for (ptr = cad; *ptr != '\0'; ptr++)
	{
		if (isspace(*ptr))
		{
			cont++;
		}
	}
	printf("Se ha(n) introdicido <%d> espacio(s).\n", cont);
}

int main(int argc, char const *argv[])
{
	char cadena[MAX];

	printf("Escriba lo que desee (Máximo 20).\n");
	fgets(cadena, MAX, stdin);
	printf("\n");
	printf("La cadena introducida es: <%s>.\n", cadena);

	printf("\n");
	cuentaDigitos(cadena);
	printf("\n");
	cuentaMayusculas(cadena);
	printf("\n");
	cuentaMinusculas(cadena);
	printf("\n");
	cuentaEspacios(cadena);

	return 0;
}