#include <stdio.h>
#include <stdlib.h>

int *reserva(int tam){
	int *aux;
	aux=(int*)malloc(tam*sizeof(int));
	return aux;
}
void rellena( int *v, int tam){
	for (int i = 0; i < tam; ++i)
	{
		scanf("%d",&v[i]);
	}
}
void escribe(int *v, int tam){

	FILE *f;
	if((f=fopen("enteros.txt","w"))==NULL){
		printf("ERROR A LA HORA DE ABRIR EL FICHERO\n");
		exit(-1);
	}
	for (int i = 0; i < tam; ++i)
	{
		fprintf(f, "%d\n",v[i]);
	}
	fclose(f);
}
void escribe_b(int *v,int tam){

	FILE *f;
	if((f=fopen("enteros.bin","wb"))==NULL){
		printf("ERROR A LA HORA DE ABRIR EL FICHERO\n");
		exit(-1);
	}
	fwrite(v,tam,sizeof(int),f);
	fclose(f);
}
int contar_registros(char nombre[50]){
		FILE *f;
		int tam;
	if((f=fopen("enteros.bin","rb"))==NULL){
		printf("ERROR A LA HORA DE ABRIR EL FICHERO\n");
		exit(-1);
	}
	fseek(f,0l,SEEK_END);
	tam=ftell(f);
	fclose(f);
	tam=tam/sizeof(int);
	return tam;
}
void load(char nombre[50],int *v, int tam){
		FILE *f;
		
	if((f=fopen("enteros.bin","rb"))==NULL){
		printf("ERROR A LA HORA DE ABRIR EL FICHERO\n");
		exit(-1);
	}
	fread(v,tam,sizeof(int),f);
	fclose(f);
}
void imprime(int *v, int tam){
	for (int i = 0; i < tam; ++i)
	{
		printf("%d\n",v[i]);
	}
}
void ordena(int *v, int tam){
	int aux;
	for (int i = 0; i < tam; ++i)
	{
		for (int j=0 ;j<tam-i-1 ;++j)
		{
			if(v[j]<v[j+1]){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
}
int main(int argc, char *argv[]){
	int tam;
	int *v;
	//scanf("%d",&tam);
	tam=contar_registros(argv[1]);
	v=reserva(tam);
	load(argv[1],v,tam);
	imprime(v,tam);
	ordena(v,tam);
	printf("----------------------------\n");
	imprime(v,tam);
	escribe(v,tam);
	free(v);
	return 0;


}