#!/bin/bash

archivos=$(find $1 -maxdepth 1 -type f | wc -l)
echo -e "\nEl número de archivos en la carpeta actual es: $archivos.\n"














# awk -> filtro salida por columnas/filas
# echo "$(who | awk '{print $1}' | sort | uniq)"
# read . .. . .. . .. -> c
#

# echo "El caracater $c aparece .."

# for x in $(find)
# do
# echo "$(basename $x)"
# done | grep $c -o | wc -l
#
# echo "veces en nombre...... . .. . ."
#
