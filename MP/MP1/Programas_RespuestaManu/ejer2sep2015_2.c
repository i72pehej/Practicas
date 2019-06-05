#include <stdio.h>
#include <stdlib.h>

struct producto{
	char nombre[50];
	int cod;
	float precio;
	int unidades;
};
void filtrar(char nombre[50], int pedido,char nombre2[50], char nombre3[50]){
	FILE *f;
	FILE *f1;
	FILE *f2;
	struct producto aux;
	if((f=fopen(nombre, "rb"))==NULL){
		printf("error \n");
		exit(-1);
	}
	f1=fopen(nombre2,"w");
	f2=fopen(nombre3,"w");
	if(f1==NULL || f2==NULL){
		printf("error \n");
		exit(-1);
	}
	while(fread(&aux,sizeof(struct producto),1,f)==1){
		if(aux.precio<=pedido){
			fprintf(f1, "%s\n%d\n%f %d\n",aux.nombre,aux.cod,aux.precio,aux.unidades);
		}
		else{
			fprintf(f2, "%s\n%d\n%f %d\n",aux.nombre,aux.cod,aux.precio,aux.unidades);
		}
	}
	fclose(f);
	fclose(f1);
	fclose(f2);
}
int main(int argc, char *argv[])
{	int pedido;
	scanf("%d",&pedido);
	filtrar(argv[1],pedido,argv[2],argv[3]);
	return 0;
}
