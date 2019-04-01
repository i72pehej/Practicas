//Ejercicio EJEMPLO CLIENTES // LEERNOMBRES // BORRAR-ACTUALIZAR //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deudasClientes(){
	char nombre[20], apellido1[20], apellido2[20];
	int num_ref, deuda;
	float intereses;

	FILE* f;
	if ((f = fopen("fich_datos.txt", "r")) == NULL)
	{
		printf("No se ha podido abrir el fichero seleccionado: <%s>.\n", "fich_datos.txt");
		exit (-1);
	}else{
		printf("El fichero <%s> se ha abierto correctamente.\n\n", "fich_datos.txt");

		while(fscanf(f, "%s %s %s %d %f %d", nombre, apellido1, apellido2, &num_ref, &intereses, &deuda) != EOF){
			printf("Cliente número: <%d> --> %s %s, %s.\n", num_ref, apellido1, apellido2, nombre);
			printf("Deuda total: <%d>.\tInterés del <%.2f>.\n\n", deuda, intereses);
		}
	}
	fclose(f);
}

void leeV1(char *nombreFichero){
	FILE *fichero;
	char cad[35];

	if ((fichero = (fopen(nombreFichero, "r"))) == NULL)
	{
		printf("El fichero <%s> no se ha podido abrir con éxito.\n", nombreFichero);
		exit(-1);
	}

	printf("\nEl fichero <%s> se ha abierto correctamente.\n\n", nombreFichero);
	while(fgets(cad, 35, fichero) != NULL){
		if (nombreFichero[strlen(nombreFichero) - 1] == '\n')
		{
			nombreFichero[strlen(nombreFichero) - 1] = '\0';	
		}
		fprintf(stdout, "%s\n", cad);
	}

	fclose(fichero);
}

void borra_actualiza(char* nombreFichero, char* nombreFichero_copia){
	FILE* fichero_copia, * fichero_OG;
	int c;
	char nombreFichero_nuevo[20] = "nombres_fullOP.txt";

	if ((fichero_OG = fopen(nombreFichero, "r")) == NULL)
	{
		printf("El fichero <%s> no se ha podido abrir.\n", nombreFichero);
		exit(-1);
	}
	if ((fichero_copia = (fopen(nombreFichero_copia, "w"))) == NULL)
	{
		printf("No se ha podido abrir el fichero <%s>.\n", nombreFichero_copia);
		exit(-1);
	}

	while((c = fgetc(fichero_OG)) != EOF){
		fputc(c, fichero_copia);
	}

	if (rename(nombreFichero_copia, nombreFichero_nuevo) != 0)
	{
		printf("No se ha podido renombrar el fichero.\n");
	}else{
		printf("El fichero se ha renombrado correctamente.\n");
	}

	if (remove(nombreFichero) != 0)
	{
		printf("No se ha podido borrar el fichero <%s>.\n", nombreFichero_copia);
	}else{
		printf("El fichero se ha borrado correctamente.\n");
	}

	fclose(fichero_OG);
	fclose(fichero_copia);
}

int main(int argc, char const *argv[])
{
	char nombreFich[15], nombreFichOrigen[30], nombreFichDestino[30];
	printf("1-Introduzca el nombre del fichero a abrir.\n");
	fgets(nombreFich, 15, stdin);
	if (nombreFich[strlen(nombreFich) - 1] == '\n')
	{
		nombreFich[strlen(nombreFich) - 1] = '\0';	
	}

	printf("2-Introduzca el nombre del fichero origen.\n");
	fgets(nombreFichOrigen, 30, stdin);
	if (nombreFichOrigen[strlen(nombreFichOrigen) - 1] == '\n')
	{
		nombreFichOrigen[strlen(nombreFichOrigen) - 1] = '\0';	
	}

	printf("3-Introduzca el nombre del fichero destino.\n");
	fgets(nombreFichDestino, 30, stdin);
	if (nombreFichDestino[strlen(nombreFichDestino) - 1] == '\n')
	{
		nombreFichDestino[strlen(nombreFichDestino) - 1] = '\0';	
	}

	leeV1(nombreFich);
	printf("\n");
	deudasClientes();
	printf("\n");
	borra_actualiza(nombreFichOrigen, nombreFichDestino);
	printf("\n");

	return 0;
}