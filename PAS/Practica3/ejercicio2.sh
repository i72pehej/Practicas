#!/bin/bash

echo -e "\nNombre, Longitud Nombre Usuario, Fecha de modificación, Fecha de acceso, Tamaño, Bloques en memoria, Permisos, Ejecutable (SI/NO)\n"

#Comprobamos que el primer argumento sea un directorio y que se hayan introducido 2 argumentos.
if [ -d "$1" -a $# -eq 2 ]; then
  for x in $(find $1 -size +$2c -type f -o -size $2c -type f); do
    #Con stat -c obtenemos el estado del archivo siguiendo un formato que nosotros asignamos. Con %u obtenemos el usuario. Con wc -m contamos los caracteres.
    longitud=$(stat -c %u $x | wc -m)-1

    #Comprobamos que sea un ejecutable con -x.
    if [ -x $x ]; then
      ejecutable=1
    else
      ejecutable=0
    fi

    echo $( basename $x ), $longitud, $( stat -c %y $x ), $( stat -c %x $x ), $( stat -c %s $x ), $( stat -c %b $x ), $( stat -c %A $x ), $ejecutable
  done | sort -n -k5 -t ";"

#Comprobamos que el primer argumento sea un directorio y que se haya introducido 1 argumento.
elif [ -d "$1" -a $# -eq 1 ]; then
  for x in $( find $1 -type f ); do
    #Con stat -c obtenemos el estado del archivo siguiendo un formato que nosotros asignamos. Con %u obtenemos el usuario. Con wc -m contamos los caracteres.
    longitud=$( stat -c %u $x | wc -m )-1

    #Comprobamos que sea un ejecutable con -x.
    if [ -x $x ]; then
      ejecutable=1
    else
      ejecutable=0
    fi

    echo $( basename $x ), $longitud, $( stat -c %y $x ), $( stat -c %x $x ), $( stat -c %s $x ), $( stat -c %b $x ), $( stat -c %A $x ), $ejecutable
  done | sort -n -k5 -t ";"

else
  echo -e "\nFallo al introducir los argumentos."
  echo -e "Se espera un directorio [y un número de bytes].\n"
fi

echo -e
