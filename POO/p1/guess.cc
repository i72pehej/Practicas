// POO - Práctica 1 -Ejercicio 2.
// guess.cc
// A program that guesses a number introduced by the user.

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[])
{
	srand(time(NULL)); 	 // time(NULL) returns “UNIX Epoch”,
						 // this is seconds since
 						 // 00:00:00 1 January 1970

	int i, num_rand;
	num_rand = (rand() % 10) + 1;

	while(num_rand != i){

		std::cout << "Introduzca su posible número: ";
		std::cin >> i;

		if (i == num_rand)
		{
			std::cout << "\n¡Ha adivinado el número!\n";
		}
		else if(i < num_rand){
			std::cout << "El número a adivinar es mayor.\n\n";
		}
		else{
			std::cout << "El número a adivinar es menor.\n\n";
		}
	}

	return 0;
}
