//Ejercicio número 5 de MEMORIA DINÁMICA.

#include <stdio.h>
#include <stdlib.h>
/*
void separaCadenas(char* cad){
	char** v;
}
*/
int main(int argc, char const *argv[])
{
	char c, *cadena = NULL;
	int nEle = 0;

	//LECTURA DE UNA CADENA CARACTER A CARACTER CON REALLOC.
	printf("Introduzca la cadena deseada.\n");
	while((c = getchar()) != '\n')
	{
		cadena = (char*) realloc(cadena, (nEle + 1) * sizeof(char));
		cadena[nEle] = c;
		nEle++;
	}
	//AÑADIMOS EL '\0'.
	cadena = (char*) realloc(cadena, (nEle + 1) * sizeof(char));
	cadena[nEle] = '\0';

	printf("\nLa cadena introducida es <%s>.\n", cadena);
	printf("nEle: %d.\n", nEle);

//	separaCadenas(cadena);

	free(cadena);
	return 0;
}