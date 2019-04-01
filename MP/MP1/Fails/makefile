#Fichero Makefile.
#Crea el ejecutable para la división entera.

divisionEntera.x : divisionEntera.o funcionDivision.o
	gcc -Wall -o divisionEntera.x divisionEntera.o funcionDivision.o

divisionEntera.o : divisionEntera.c funcionDivision.h
	gcc -Wall -o divisionEntera.o -c divisionEntera.c

funcionDivision.o : funcionDivision.c funcionDivision.h
	gcc -Wall -o funcionDivision.o -c funcionDivision.c
