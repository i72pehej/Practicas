CFLAGS = -Wpedantic -O3 -g

all: crucigrama.x clean
	@echo
	@echo Ejecutado el fichero MAKEFILE completo . . .

crucigrama.x: main.o ficheros.o crucigrama.o libMemoria.a
	@echo
	@echo Creando ejecutable . . .
	@ gcc $(CFLAGS) -o $@ $^

libMemoria.a: reservaMemoria.o liberaMemoria.o
	@echo
	@echo Creando libreria . . .
	@ ar -rsv $@ $^

%.o: %.c
	@ gcc $(CFLAGS) -o $@ -c $<

.PHONY:
clean:
	@echo
	@echo Borrando archivos innecesarios . . .
	@rm -f *.o
