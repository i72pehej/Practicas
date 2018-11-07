
#ifndef FUNCIONES
#define FUNCIONES
struct libro{
	char titulo[100];
	char autor[50];
	float precio;
	int unidades;
};
int contar_registros(char nombre[50]);

struct libro *reserva(int tam);

void load(char nombre[50], struct libro *v, int tam);

void escribir(struct libro *v, int tam);
#endif