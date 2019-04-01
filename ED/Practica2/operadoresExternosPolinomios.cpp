/*!
   \file    operadoresExternosPolinomios.cpp
   \brief   Fichero que contiene el código de las funciones de la clase Polinomio
	 \author  Julen Pérez Hernández
   \date    31/03/2019
 */


 // Ficheros de cabecera
 #include <iostream>

 #include "operadoresExternosPolinomios.hpp"

 #include "operadoresExternosMonomios.hpp"

 // Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed {

////////////////////////////////////////////////////////////////////////////////

	//Operadores de igualdad.

////////////////////////////////////////////////////////////////////////////////

	bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2) {
		for(int i = 0;	i <	p1.size();	i++) {

			if((p1.getMonomios()[i]) != (p2.getMonomios()[i])) {
				return false;
			}
		}
		return true;
	}

	bool operator==(ed::Polinomio const & p1, ed::Monomio const & m1) {
		if((p1.size() == 1) and (p1.getMonomios()[0] == m1)) {
			return true;
		}
		return false;
	}

	bool operator==(ed::Monomio const & m1,ed::Polinomio const & p1) {
		if((p1.size() == 1) and (p1.getMonomios()[0] == m1)) {
			return true;
		}
		return false;
	}

	bool operator==(ed::Polinomio const & p1, double const &x) {
		Monomio m(x,0);

		if((p1.size() == 1) and (p1.getMonomios()[0] == m)) {
			return true;
		}
		return false;
	}

	bool operator==(double const &x, ed::Polinomio const & p1)
	{
		Monomio m(x,0);

		if((p1.size() == 1) and (p1.getMonomios()[0] == m)) {
			return true;
		}
		return false;
	}

////////////////////////////////////////////////////////////////////////////////

 // Operadores de desigualdad.

////////////////////////////////////////////////////////////////////////////////

	bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2) {
		if ((p1.size()) != (p2.size())) {
			return true;
		}

		for(int i=0; i <	p1.size();	i++) {
			if((p1.getMonomios()[i]) != (p2.getMonomios()[i])) {
				return true;
			}
		}
		return false;
	}

	bool operator!=(ed::Polinomio const & p1, ed::Monomio const & m1) {
		if((p1.size() == 1) and (p1.getMonomios()[0] == m1)) {
			return false;
		}
		return true;
	}

	bool operator!=( ed::Monomio const & m1, ed::Polinomio const & p1) {
		if((p1.size() == 1) and (p1.getMonomios()[0] == m1)) {
			return false;
		}
		return true;
	}

	bool operator!=(ed::Polinomio const & p1, double const &x) {
		Monomio m(x,0);

		if((p1.size() == 1) and (p1.getMonomios()[0] == m)) {
			return false;
		}
		return true;
	}


	bool operator!=(double const &x, ed::Polinomio const & p1) {
		Monomio m(x,0);

		if(p1.size() == 1 and p1.getMonomios()[0]==m)	{
			return false;
		}
		return true;
	}

////////////////////////////////////////////////////////////////////////////////

 // Operadores unarios

////////////////////////////////////////////////////////////////////////////////

	ed::Polinomio & operator+(ed::Polinomio const & p) {
		// Se crea un nuevo objeto
		ed::Polinomio *nuevo = new ed::Polinomio(p);

		/*nuevo->setMonomios(getMonomios());*/

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Polinomio const & p) {

		ed::Polinomio *nuevo= new ed::Polinomio;

		nuevo->limpiarVector();

		for(int i = 0; i < p.size(); i++) {
			nuevo->setMonomios(- p.getMonomios()[i]);
		}

		return *nuevo;
	}

////////////////////////////////////////////////////////////////////////////////

 // Operadores binarios de la suma

////////////////////////////////////////////////////////////////////////////////

	ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2) {
		ed::Polinomio *nuevo = new ed::Polinomio(p1);
		(*nuevo) += p2;

		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Polinomio const &p,  ed::Monomio const & m) {
		ed::Polinomio * nuevo =new ed::Polinomio(p);
		(*nuevo)+=m;

		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Monomio const &m,  ed::Polinomio const &p) {
		ed::Polinomio * nuevo =new ed::Polinomio(p);
		(*nuevo)+=m;

		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Polinomio const &p,  double const x) {
		ed::Polinomio * nuevo = new ed::Polinomio(p);
		(*nuevo)+=x;

		return *nuevo;
	}

	ed::Polinomio & operator+(double const x,  ed::Polinomio const &p) {
		ed::Polinomio * nuevo = new ed::Polinomio(p);
		(*nuevo)+=x;

		return *nuevo;
	}

////////////////////////////////////////////////////////////////////////////////

	// Operadores binarios de la resta.

////////////////////////////////////////////////////////////////////////////////

	ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2) {
		ed::Polinomio *nuevo = new ed::Polinomio(p1);
		(*nuevo)-=p2;

		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Polinomio const &p,  ed::Monomio const & m) {
		ed::Polinomio * nuevo =new ed::Polinomio(p);
		(*nuevo)-=m;

		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Monomio const &m,  ed::Polinomio const &p) {
		ed::Polinomio * nuevo =new ed::Polinomio(p);
		(*nuevo)-=m;

		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Polinomio const &p,  double const x) {
		ed::Polinomio * nuevo = new ed::Polinomio(p);
		(*nuevo)-=x;

		return *nuevo;
	}

	ed::Polinomio & operator-(double const x,  ed::Polinomio const &p) {
		ed::Polinomio * nuevo = new ed::Polinomio(p);
		(*nuevo)-=x;

		return *nuevo;
	}

////////////////////////////////////////////////////////////////////////////////

	// Operadores binarios de la multiplicación.

////////////////////////////////////////////////////////////////////////////////

	ed::Polinomio & operator*(ed::Polinomio const &p1,  ed::Polinomio const &p2) {
		ed::Polinomio *nuevo = new ed::Polinomio(p1);
		(*nuevo)*=p2;

		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Polinomio const &p1, ed::Monomio const &m) {
		ed::Polinomio *nuevo = new ed::Polinomio(p1);
		(*nuevo)*=m;

		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Monomio const &m, ed::Polinomio const &p1) {
		ed::Polinomio *nuevo = new ed::Polinomio(p1);
		(*nuevo)*=m;

		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Polinomio const &p1, double x){
		ed::Polinomio *nuevo = new ed::Polinomio;

		for(int i = 0;i < p1.size(); i++) {
			nuevo->setMonomios(p1.getMonomios()[i].getCoeficiente() * x);
		}

		return *nuevo;
	}

	ed::Polinomio & operator*(double x, ed::Polinomio const &p1) {
		ed::Polinomio *nuevo = new ed::Polinomio;

		for(int i = 0;i < p1.size(); i++){
				nuevo->setMonomios(p1.getMonomios()[i].getCoeficiente() * x);
		}

		return *nuevo;
	}

////////////////////////////////////////////////////////////////////////////////

	// Operadores binarios de la división.

////////////////////////////////////////////////////////////////////////////////

	ed::Polinomio & operator/(ed::Polinomio const &p1, ed::Polinomio const &p2) {
		ed::Polinomio *nuevo = new ed::Polinomio;
		ed::Polinomio p3(p1);
		ed::Monomio aux, aux2, aux3;

		nuevo->limpiarVector();

		while(p3.getGrado() >= p2.getGrado()) {

			aux = p3.getMonomio(p3.getGrado());
			aux2 = p2.getMonomio(p2.getGrado());
			aux3 = (aux / aux2);

			nuevo->setMonomios(aux3);

			p3-=(aux3*p2);
		}

		return *nuevo;
	}

	ed::Polinomio & operator/(ed::Polinomio const &p1, ed::Monomio const &m) {
		ed::Polinomio *nuevo = new ed::Polinomio(p1);
		Polinomio p;

		p.limpiarVector();
		p.setMonomios(m);

		(*nuevo)/=p;

		return *nuevo;
	}


	ed::Polinomio & operator/(ed::Monomio const &m, ed::Polinomio const &p1) {
		ed::Polinomio *nuevo = new ed::Polinomio(p1);
		Polinomio p;

		p.limpiarVector();
		p.setMonomios(m);

		(*nuevo)/=p;

		return *nuevo;
	}

	ed::Polinomio & operator/(double x, ed::Polinomio const &p1) {
		ed::Polinomio *nuevo = new ed::Polinomio;

		for(int i = 0;i < p1.size(); i++){
			nuevo->setMonomios(p1.getMonomios()[i].getCoeficiente() / x);
		}

		return *nuevo;
	}

	ed::Polinomio & operator/(ed::Polinomio const &p1,double x){

		ed::Polinomio *nuevo = new ed::Polinomio;
		for(int i = 0;i < p1.size(); i++){
			nuevo->setMonomios(p1.getMonomios()[i].getCoeficiente() / x);
		}

		return *nuevo;
	}

////////////////////////////////////////////////////////////////////////////////

	// Sobrecarga del operador de entrada y salida.

////////////////////////////////////////////////////////////////////////////////

	istream &operator>>(istream &stream, Polinomio &p) {
		double coeficiente;
		int grado, tam;
		ed::Monomio m;

		p.limpiarVector();

		std::cout<<"Introduzca el número de Monomios que desee: "<<std::endl;
		std::cin>>tam;

		while(!std::cin || tam == 0){
			std::cin.clear(); // Borrar la entrada fallida
			std::cin.ignore(); //Saltar la entrada no válida

			std::cout<< "Introduzca correctamente el número de Monomios:";
			std::cin>>tam;
		}

		for(int i = 0; i < tam; i++) {
			std::cout << "Introduzca el coeficiente y grado separados por un espacio: " << std::endl;

			stream >> coeficiente >> grado;

			while(!stream || coeficiente == 0 || grado < 0){
				stream.clear(); // Borrar la entrada fallida
				stream.ignore(); //Saltar la entrada no válida

				std::cout << "Introduzca correctamente el coeficiente y el grado:" << std::endl;
				stream >> coeficiente >> grado;
			}

			m.setCoeficiente(coeficiente);
			m.setGrado(grado);
			p.setMonomios(m);
		}

		// Se devuelve el flujo de entrada
	  return stream;
	}

	ostream &operator<<(ostream &stream, Polinomio const &p) {
		for(int i = 0; i < (int)p.getMonomios().size(); i++) {
			if (!p.esNulo()) {
				if(p.getMonomios()[i].getCoeficiente() == 1) {
					if(p.getMonomios()[i].getGrado() == 0) {
						stream << "1"; //Si el coeficiente es 1 y el grado 0.
					}

					else if(p.getMonomios()[i].getGrado()==1) {
						stream << "X"; //Si el coeficiente es 1 y el grado 1
					}
					else {
						stream << "X^" << p.getMonomios()[i].getGrado(); //Si el coeficiente es 1 y el grado distinto de 1 y 0.
					}
				}

				else if(p.getMonomios()[i].getCoeficiente()==-1) {
					if(p.getMonomios()[i].getGrado() == 0) {
						stream << "-1"; //Si el coeficiente es -1 y el grado 0
					}

					else if(p.getMonomios()[i].getGrado() == 1) {
						stream << "-X"; //Si el coeficiente es -1 y el grado 1
					}
					else {
						stream << "-X^" << p.getMonomios()[i].getGrado(); //Si el coeficiente es -1 y el grado distinto de 1 y 0.
					}
				}

				else if(p.getMonomios()[i].getCoeficiente() == 0) {  //Si el coeficiente es 0.
					if ((int)p.getMonomios().size() > 1) {
						stream << "0"; //???????????????????
					}
					else {
						stream << "0";
					}
				}

				else {
					if(p.getMonomios()[i].getGrado() == 0) {
						stream<<p.getMonomios()[i].getCoeficiente(); //Si el coeficiente no es 1 y el grado es 0
					}

					else if(p.getMonomios()[i].getGrado() == 1) {
						stream << p.getMonomios()[i].getCoeficiente() << "X"; //Si el coeficiente no es 1 y el grado es 1
					}
					else {
						stream << p.getMonomios()[i].getCoeficiente() << "X^" << p.getMonomios()[i].getGrado(); //Si el coeficiente no es 1 y el grado no es ni 1 ni 0
					}
				}

				if((i <= (int)p.getMonomios().size() - 2) and (p.getMonomios().size() > 1) and (p.getMonomios()[i + 1].getCoeficiente() != 0)) {
					stream << " + ";
				}
			}
			
			else {
				stream << "0";
			}
		}

		// Se devuelve el flujo de salida
		return stream;
	}
} // Fin del espacio de nombres ed
