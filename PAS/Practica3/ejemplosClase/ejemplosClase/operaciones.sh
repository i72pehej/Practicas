#!/bin/bash

echo -n "Introduzca un primer número: "; read x
echo -n "Introduzca un segundo número : "; read y
suma=$(($x + $y))
resta=$[$x - $y]
let "mul=$x*$y"
div=$(($x / $y))
mod=$(($x % $y))‏

# Imprimimos las respuestas:
echo "Suma: $suma"
echo "Resta: $resta"
echo "Multiplicación: $mul"
echo "División: $div"
echo "Módulo: $mod"
