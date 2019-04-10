#!/bin/bash


#Si existen los directorios, los borramos.
if [ -e pequenos ]; then
  echo -e "\nCarpeta pequeños existente . . .\n"
  echo -e "\nBorrando carpeta . . .\n"

  rm -d -r pequenos

elif [ -e medianos ]; then
  echo -e "\nCarpeta medianos existente . . .\n"
  echo -e "\nBorrando carpeta . . .\n"

  rm -d -r medianos

elif [ -e grandes ]; then
  echo -e "\nCarpeta grandes existente . . .\n"
  echo -e "\nBorrando carpeta . . .\n"

  rm -d -r grandes

#Si no exsten los creamos.
else
  echo -e "\nCreando carpetas (pequenos, medianos, grandes) . . .\n"

  mkdir pequenos
  mkdir medianos
  mkdir grandes
fi

#Si sólo se introduce la carpeta:
if [ -d "$1" -a $# -eq 1 ]; then
  echo -e "\nSólo se ha introducido el directorio.\n"
  #Valores por defecto de los umbrales.
  umbral1=10000
  umbral2=100000

  #Se copian los archivos menores que umbral1 en la carpeta pequenos.
  for x in $(find $1 -size "-$umbral1"c -type f); do
    cp $x pequenos
  done

  #Se copian los archivos mayores que umbral1 y menores que umbral2 en la carpeta medianos.
  for x in $(find $1 -size "+$umbral1"c -type f -a -size "-$umbral2"c -type f); do
    cp $x medianos
  done

  #Se copian los archivos mayores que umbral2 en la carpeta grandes.
  for x in $(find $1 -size "+$umbral2"c -type f); do
    cp $x grandes
  done

else
  echo -e "\nERROR. Se debe especificar un directorio como primer argumento.\n"
fi

#Si se introducen los dos umbrales además de la carpeta.
if [ -d "$1" -a $# -eq 3 ]; then
  echo -e "\nSe han introducido el directorio y los dos umbrales.\n"
  #El primer valor debe ser el umbral menor.
  if [ $2 < $3 ]; then
    umbral1=$2
    umbral2=$3

    #Se copian los archivos menores que umbral1 en la carpeta pequenos.
    for x in $(find $1 -size "-$umbral1"c -type f); do
      cp $x pequenos
    done

    #Se copian los archivos mayores que umbral1 y menores que umbral2 en la carpeta medianos.
    for x in $(find $1 -size "+$umbral1"c -type f -a -size "-$umbral2"c -type f); do
      cp $x medianos
    done

    #Se copian los archivos mayores que umbral2 en la carpeta grandes.
    for x in $(find $1 -size "+$umbral2"c -type f); do
      cp $x grandes
    done

  else
    echo -e "\nERROR. El primer umbral debe ser el menor.\n"
  fi

else
  echo -e "\nERROR. Se espera un directorio y dos umbrales.\n"
fi
