#!/bin/bash

# Imprimir todos los ficheros que se encuentren
# con extensión .sh
for x in $(find -name "*.sh")
do
  echo $x
done
