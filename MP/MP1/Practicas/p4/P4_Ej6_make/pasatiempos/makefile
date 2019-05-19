CFLAGS = -Wpedantic -O3 -g

all: crucigrama.x clean
	@echo
	@echo Ejecutado el fichero MAKEFILE completo . . .
	@echo

crucigrama.x: main.o ficheros.o crucigrama.o libMemoria.a
	@echo Creando ejecutable . . .
	@ gcc $(CFLAGS) -o $@ $^
	@echo

libMemoria.a: reservaMemoria.o liberaMemoria.o
	@echo Creando libreria . . .
	@ ar -rsv $@ $^
	@echo

%.o: %.c
	@ gcc $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	@echo Borrando archivos innecesarios . . .
	@rm -f *.o
	@echo
