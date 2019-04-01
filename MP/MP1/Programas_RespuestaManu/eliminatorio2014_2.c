#include <stdio.h>
#include <stdlib.h>

struct libro{
	char titulo[256];
	char autor[256];
	float precio;
	int unidades;
};

int contar_registros(char nombre[50]){
	FILE *f;
	int tam;
	if((f=fopen(nombre,"rb"))==NULL){
		printf("error al abrir el fichero\n");
		exit(-1);
	}
	fseek(f,0l,SEEK_END);
	tam=ftell(f);
	fclose(f);
	return tam;
}
void load(char nombre[50],struct libro *v, int tam){
	FILE *f;
	if((f=fopen(nombre,"rb"))==NULL){
		printf("error al abrir el fichero\n");
		exit(-1);
	}
	fread(v,tam,sizeof(struct libro),f);
	fclose(f);

}
void escribe(char nombre[50],struct libro *v, int tam){
	FILE *f;
	if((f=fopen(nombre,"w"))==NULL){
		printf("error al abrir el fichero\n");
		exit(-1);
	}
	for (int i = 0; i < tam; ++i)
	{
		fprintf(f, "%s\n%s\n%f %d\n",v[i].titulo, v[i].autor,v[i].precio, v[i].unidades);
	}
	fclose(f);
}
int main(int argc, char *argv[]){
	struct libro *libreria;
	int tam;
	tam=contar_registros(argv[1]);
	libreria=(struct libro*)malloc(tam*sizeof(struct libro));
	load(argv[1],libreria,tam);
 	escribe(argv[2],libreria,tam);
 	free(libreria);
	return 0;
}
