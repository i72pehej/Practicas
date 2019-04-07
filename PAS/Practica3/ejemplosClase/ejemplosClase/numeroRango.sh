5#!/bin/bash

echo -n "Introduzca un número (1 <= x < 10): "; read numero

if [ $numero -ge 1 ];
then
	if [ $numero -lt 10 ];
	then
		echo "El número $numero es correcto!"
	else
		echo "Fuera de rango!"
	fi
else
	echo "Fuera de rango!"
fi
