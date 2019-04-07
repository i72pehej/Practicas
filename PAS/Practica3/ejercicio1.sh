#!/bin/bash

if [ -d "$1" -a !$* ]; then
  cant1=$(find $1 -name "*.c" | wc -l)
  cant2=$(find $1 -name "*.c" | wc -l)

  echo "Tenemos $cant1 ficheros con extensión .c y $cant2 ficheros con extensión .h"

  for x in $(find $1 -type f -name "*.c" -o -type f -name "*.h"); do
    echo "El fichero $x tiene $(cat $x | wc -l) líneas y $(cat $x | wc -c) caracateres"
  done | sort -nr -k 8

else
  echo "Fallo al introducir los argumentos."
  echo "Se espera un directorio."
fi
