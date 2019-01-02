/*
Ejercicio 3 - Práctica 4 - Sistemas Operativos
Implementar un programa en lenguaje C, que simule al algoritmo RR (Round Robin).
Tener en cuenta: quantum = 3.
*/

#include <stdio.h>
#include <string.h>

#define PROCESOS 5  //Número de procesos.
#define QUANTUM 3  //Quantum de ejecución de cada proceso.

typedef struct params{
  char nombre[10];  //Nombre del parámetro.
  //Se introducen.
  int t_ejec; //Tiempo de ejecución.
  int t_lleg; //Tiempo de llegada.
  //Se calculan.
  int t_com;  //Tiempo de comienzo.
  int t_fin;  //Tiempo de finalización.
  int t_ret;  //Tiempo de retorno.
  int t_esp;  //Tiempo de espera.
}parametros;

int main(int argc, char const *argv[]) {
  int i = 0, j = 0;  //Iteradores.
  int comienzo = 0;  //Variable para modificar el tiempo de comienzo.
  int t_ejecVariable[PROCESOS];  //Variable para modificar el tiempo de ejecución.

  // Inicialización de los datos de procesos
  parametros procesos[PROCESOS];
  strcpy(procesos[0].nombre, "A");
  procesos[0].t_ejec = 8;
  t_ejecVariable[0] = 8;
  procesos[0].t_lleg = 0;
  procesos[0].t_com = 0;
  procesos[0].t_fin = procesos[0].t_ejec;
  procesos[0].t_ret = procesos[0].t_fin;
  procesos[0].t_esp = 0;

  strcpy(procesos[1].nombre, "B");
  procesos[1].t_ejec = 4;
  t_ejecVariable[1] = 4;
  procesos[1].t_lleg = 1;

  strcpy(procesos[2].nombre, "C");
  procesos[2].t_ejec = 9;
  t_ejecVariable[2] = 9;
  procesos[2].t_lleg = 2;

  strcpy(procesos[3].nombre, "D");
  procesos[3].t_ejec = 5;
  t_ejecVariable[3] = 5;
  procesos[3].t_lleg = 3;

  strcpy(procesos[4].nombre, "E");
  procesos[4].t_ejec = 2;
  t_ejecVariable[4] = 2;
  procesos[4].t_lleg = 4;

  while(j != 3){  //Simulación de los tiempos de comienzo y finalización en cada ciclo (sabiendo que necesitaremos tres ciclos).
    printf("\n\n\tCiclo de ejecución: %d", (j + 1));
    printf("\n\tPROCESOS | t_comienzo | t_fin\n");

    for(i = 0; i < PROCESOS; i++){  //Primera iteración.
      if(t_ejecVariable[i] > 0){  //El proceso no ha acabado su ejecución.
        procesos[i].t_com = comienzo;
        if(t_ejecVariable[i] < QUANTUM){  //El proceso posee un tiempo de ejecución inferior al quantum.
          procesos[i].t_fin = procesos[i].t_com + t_ejecVariable[i];
          t_ejecVariable[i] = 0;
          comienzo = procesos[i].t_fin;
        }
        else{
          procesos[i].t_fin = procesos[i].t_com + QUANTUM;
          t_ejecVariable[i] -= QUANTUM;
          comienzo = procesos[i].t_fin;
        }
      }
      printf("\t-------------------------------\n");
      printf("\t  %s \t\t %d \t %d\n", procesos[i].nombre, procesos[i].t_com, procesos[i].t_fin);
    }
    j++;
  }

  printf("\n\n\tPROCESOS | t_retorno | t_espera\n");
  printf("\t-------------------------------\n");

  for(i = 0; i < PROCESOS; i++){  //Cálculo de tiempos de retorno y espera tras los tres ciclos.
    procesos[i].t_ret = procesos[i].t_fin - procesos[i].t_lleg;
    procesos[i].t_esp = procesos[i].t_ret - procesos[i].t_ejec;

    printf("\t   %s \t\t %d \t %d \n", procesos[i].nombre, procesos[i].t_ret, procesos[i].t_esp);
  }
  printf("\n\n");
  return 0;
}
