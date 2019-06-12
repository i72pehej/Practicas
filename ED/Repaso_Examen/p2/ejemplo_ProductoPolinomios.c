ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m){
     for (int i = 0; i < this->getNumeroMonomios(); ++i)
     {
          this->polinomio_[i] *= m;
     }
     return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p){

     ed::Polinomio aux(*this);
     ed::Polinomio result();

     for (int i = 0; i < p.getNumeroMonomios(); ++i)
     {
          aux *= p.polinomio_[i];

          result += aux;

          aux = *this;
     }
     *this = result;
     return *this;
}

En los operadores externos de la clase polinomio NO se tiene que copiar y pegar código, sino que se tiene que llamar a los métodos implementados de la clase Polinomio como sigue:

ed::Polinomio & operator*(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
     ed::Polinomio nuevo(p1);
     nuevo*=p2;
     return *nuevo;
}

ed::Polinomio & operator*(ed::Polinomio const &p, ed::Monomio const & m){
     ed::Polinomio nuevo(p);
     nuevo*=m;
     return *nuevo;
}
