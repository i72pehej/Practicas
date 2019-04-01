#ejercicio eliminatorio 2014
.PHONY: clean

eliminatorio2014.out: main.o funciones.o
	gcc -Wall -o eliminatorio2014.out main.o funciones.o

main.o: main.c funciones.h
	gcc -c main.c 

funciones.o: funciones.c funciones.h
	gcc -c funciones.c 

clean:
	rm*.o