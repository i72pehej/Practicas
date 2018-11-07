// dados.h
// A class that represents the throw of 2 dices.

#ifndef DADOS_H
#define DADOS_H

class Dados{  //Las clases tienen la primera letra en mayúscula.
  private:
    int d1_, d2_, contador1, contador2;
    float suma1, suma2;
    int v1[5], v2[5];
  public:
    Dados();  // El constructor. No devuelve nada.
    void lanzamiento(); // Asigna un valor aleatorio a los dados.
    int getDado1(); // Devuelve el valor del primer dado.
    int getDado2(); // Devuelve el valor del segundo dado.
    bool setDado1(int num1); // Asigna valor entre 1 y 6 al primer dado.
    bool setDado2(int num2); // Asigna valor entre 1 y 6 al segundo dado.
    int getSuma();  // Devuelve la suma de los valores de ambos dados.

    int getDiferencia();  // Devuelve la diferencia entre el menor y el mayor.

    int getLanzamientos1();  // Devuelve el número de lanzamientos del primer dado.
    int getLanzamientos2();  // Devuelve el número de lanzamientos del segundo dado.

    float getMedia1();  // Devuelve la media de los valores del primer dado.
    float getMedia2();  // Devuelve la media de los valores del segundo dado.

    void getUltimos1(int vec1[5]);  // Copia los 5 últimos valores del primer dado al vector.
    void getUltimos2(int vec2[5]);  // Copia los 5 últimos valores del segundo dado al vector.
};

#endif
