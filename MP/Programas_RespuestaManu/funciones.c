#include <stdio.h>
#include <stdlib.h>
int contar_registros(char nombre[50]){
	int registros=0;
	FILE *f;
	if((f=fopen(nombre,"rb"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO BINARIO\n");
	}
	fseek(f,0l,SEEK_END);
	registros=ftell(f);
	fclose(f);
	registros=registros/sizeof(struct libro);
	return registros;
}

struct libro *reserva(int tam){
	struct libro *aux;
	aux=(struct libro*)malloc(tam*sizeof(struct libro));
	return aux;
}

void load(char nombre[50], struct libro *v, int tam){
	FILE *f;
	if((f=fopen(nombre,"rb"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO BINARIO\n");
	}
	fread(v,sizeof(struct libro),tam,f);
	fclose(f);
}

void escribir(struct libro *v, int tam){
	FILE *f;
	if((f=fopen("stock.txt","w"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO BINARIO\n");
	}
	for (int i = 0; i < tam; ++i)
	{
		fprintf(f, "%s\n%s\n%f %d\n",v[i].titulo, v[i].autor, v[i].precio, v[i].unidades );
	}
	fclose(f);
}