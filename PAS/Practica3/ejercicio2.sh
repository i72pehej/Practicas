#!/bin/bash

echo "Nombre, Longitud nombre usuario, Fecha de modificación, Fecha de acceso, Tamaño, Bloques en memoria, Permisos, Ejecutable (SI/NO)"
if [ -d "$1" -a -n "$2" -a !$* ]; then
  for x in $(find $1 -size +$2c -type f -o -size $2c -type f); do
    longitud=$(stat -c %u $x | wc -m) -1
    if [[ -executable $x ]]; then
      ejecutable=1
    else
      ejecutable=0
    fi
    echo "$(basename $x)", $longitud, $(stat -c %y $x), $(stat -c %x $x), $(stat -c %s $x), $(stat -c %b $x), $(stat -c %A $x), $ejecutable
  done

elif [[ -d "$1" -a !$* ]]; then
  for x in $(find $1 -type f); do
    longitud=$(stat -c %u $x | wc -m) -1
    if [[ -executable $x ]]; then
      ejecutable=1
    else
      ejecutable=0
    fi
    echo "$(basename $x)", $longitud, $(stat -c %y $x), $(stat -c %x $x), $(stat -c %s $x), $(stat -c %b $x), $(stat -c %A $x), $ejecutable
  done

else
  echo "Fallo al introducir los argumentos."
  echo "Se espera un directorio [y un número de bytes]."
fi
