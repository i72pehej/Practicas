/*
  Implementa un programa que, utilizando funciones, realice las siguientes operaciones secuencialmente:
    1. Crear una lista de N valores enteros.
    2. Imprimir la lista por pantalla.
    3. Determinar en una única función, el mayor y el menor valor de la lista,
    utilizando paso de parámetros por referencia.

  Ten en cuenta lo siguiente:
    • La función para mostrar la lista será una función recursiva.
    • El mayor y el menor valor de la lista se imprimirá desde el programa principal.
*/

#include "funciones_Ej1_ExamenNacho.h"


int main(int argc, char const *argv[]) {
  // Limpia la pantalla de la terminal, para mejor experiencia visual.
  system("clear");

  int Nelementos, seleccion = 1, max = -9999999, min = 9999999, borrar;
  struct lista *cabeza = NULL;
  // Puntero a funciones para insertar.
  void (*insert) (struct lista **);

  selecionaInsertar(&seleccion);
  // // Control de ERRORES.
  // while ((seleccion != 0) || (seleccion != 1)) {
  //   printf("Valor incorrecto. Corrija el valor.\n");
  //   selecionaInsertar(&seleccion);
  // }
  if (seleccion == 0) {insert = &insertarDelante;}
  else if (seleccion == 1) {insert = &insertarDetras;}

  printf("\n¿Cuantos elementos desea insertar? => ");
  fscanf(stdin, "%d", &Nelementos);

  // Bucle para insertar los Nelementos deseados.
  for (int i = 0; i < Nelementos; i++) {
    (*insert) (&cabeza);
  }

  imprimirLista(cabeza);

  mayor_menor(&max, &min, cabeza);
  printf("\n\nEl MAYOR valor de la lista es: %d, y el MENOR valor: %d.\n", max, min);

  printf("\n¿Qué elemento desea borrar? => ");
  fscanf(stdin, "%d", &borrar);
  borrarElemento(&cabeza, &borrar);

  printf("\n\nLista: ");
  imprimirListaRecursivo(cabeza);

  printf("\n\n");
  return 0;
}
