// dados.h
// A class that represents the throw of 2 dices.

// Las funciones cortas se encuentran expresadas "inline", de manera que no son necesaias en el cuerpo.
// El return de éstas se encuentra de forma "const" para que nunca varíe la variable retornada.
// En la función "getDiferencia" encontramos una condición triple, siendo su prototipo ((condition) ? true : false).

#ifndef DADOS_V2_H
#define DADOS_V2_H

#include <vector>

class Dados{  //Las clases tienen la primera letra en mayúscula.
  private:
    int d1_, d2_, contador1_, contador2_;
    float suma1_, suma2_;
    std::vector<int> v1_, v2_;
  public:
    Dados();  // El constructor. No devuelve nada.
    void lanzamiento(); // Asigna un valor aleatorio a los dados.
    inline int getDado1() const {return (d1_);}; // Devuelve el valor del primer dado.
    inline int getDado2() const {return (d2_);}; // Devuelve el valor del segundo dado.
    bool setDado1(int num1); // Asigna valor entre 1 y 6 al primer dado.
    bool setDado2(int num2); // Asigna valor entre 1 y 6 al segundo dado.

    void pushDado1(int valor);
    void pushDado2(int valor);

    inline int getSuma() const {return (getDado1() + getDado2());};  // Devuelve la suma de los valores de ambos dados.

    inline int getDiferencia() const {return ((d1_ > d2_) ? (d1_ - d2_) : (d2_ - d1_));};  // Devuelve la diferencia entre el menor y el mayor.

    int getLanzamientos1() const {return (contador1_);};  // Devuelve el número de lanzamientos del primer dado.
    int getLanzamientos2() const {return (contador2_);};  // Devuelve el número de lanzamientos del segundo dado.

    inline float getMedia1() const {return (contador1_ == 0 ? contador1_ : suma1_ / contador1_);};  // Devuelve la media de los valores del primer dado.
    inline float getMedia2() const {return (contador2_ == 0 ? contador2_ : suma2_ / contador2_);};  // Devuelve la media de los valores del segundo dado.

    void getUltimos1(std::vector<int> &vec1) {vec1 = v1_;};  // Copia los 5 últimos valores del primer dado al vector.
    void getUltimos2(std::vector<int> &vec2) {vec2 = v2_;};  // Copia los 5 últimos valores del segundo dado al vector.
};

#endif
