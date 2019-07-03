# Fichero MAKEFILE.

CFLAGS = -Wall -Wpedantic -g -O3

all: examenSep2013.exe
	@echo
	@echo Ejecutado el fichero MAKEFILE completo . . .

examenSep2013.exe: examenSep2013.o ficheros.o vector.o
	@echo
	@echo Creando ejecutable . . .
	@gcc $(CFLAGS) -o $@ $^

%.o:%.c
	@gcc $(CFLAGS) -o $@ -c $<

.PHONY: clean
# Fuerza el borrado sin avisos (pide confirmación para el borrado (-i)).
clean:
	@echo
	@echo Borrando archivos innecesarios . . .
	@rm -f *.o
