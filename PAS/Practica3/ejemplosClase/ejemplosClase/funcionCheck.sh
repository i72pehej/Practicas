#!/bin/bash
function chequea() {
  if [ -e "$1" ]
  then
    return 0
  else
    return 1
  fi
}

echo -n "Introduzca el nombre del archivo: "
read x
if chequea $x
then
  echo "El archivo $x existe !"
else
  echo "El archivo $x no existe !"
fi
