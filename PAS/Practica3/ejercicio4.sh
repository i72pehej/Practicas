#!/bin/bash

# Cuenta el número de ficheros en la carpeta pasada como argumento.
archivos=$( find $1 -maxdepth 1 -type f | wc -l )
echo -e "\nEl número de archivos en la carpeta actual es: $archivos.\n"

# who   ->  Muestra información de los usuarios logeados.
# awk   ->  Programa de manejo de datos. En este caso imprime el primer campo de cada línea, que le pasamos desde "Who" por una tubería.
# sort  ->  Ordenamos los usuarios alfabéticamente por la primera columna.
# uniq  ->  Imprime una copia de cada elemento, obviando los duplicados.
echo -e "\nLos usuarios logeados actualmente son:\n"
echo "$( who | awk '{print $1}' | sort -k 1| uniq )"

echo -e "\n¿Qué carácter quieres contar? (Dispone de 5 segundos para introducirlo)\n"
# read -> Lee elementos desde teclado. -t -> Opción para introducir tiempo de espera.
read -t5 c

# En caso en el que no se introduzca nada en 5 segundos: Comprobamos que "c" sea nulo y le asignamos el valor "a" por defecto.
if [[ -z $c ]]; then
  c=a
fi

echo -e "\nEl caracater $c aparece "
# find      ->  Buscamos todos los elementos de la carpeta.
# basename  ->  Obtiene el nombre base de los archivos.
# grep      ->  Busca líneas que concuerden con el patrón, en este caso el carácter. -o -> para mostrar sólo la parte que concuerda con el patrón.
for x in $( find $1); do
  echo "$( basename $x )"
done | grep $c -o | wc -l
echo -e "veces en nombres de ficheros o carpetas contenidos en la carpeta actual.\n"
