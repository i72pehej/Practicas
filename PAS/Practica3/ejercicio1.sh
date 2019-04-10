#!/bin/bash

if [ -d "$1" -a $# -eq 1 ]; then
  #Busca en el argumento 1 cualquier nombre que acabe por .c o .h
  cant1=$(find $1 -name "*.c" | wc -l)
  cant2=$(find $1 -name "*.h" | wc -l)

  echo -e "\nTenemos $cant1 ficheros con extensión .c y $cant2 ficheros con extensión .h\n"

  for x in $(find $1 -type f -name "*.c" -o -type f -name "*.h"); do
    echo "El fichero $x tiene $(cat $x | wc -l) líneas y $(cat $x | wc -c) caracateres"
  done | sort -nr -k 8
  #Ordenamos con -n de menor a mayor. -r Invierte el orden. -k para seleccionar la columna a ordenar + <número de columna>.

else
  echo -e "\nFallo al introducir los argumentos."
  echo "Se espera un directorio."
fi

echo -e
