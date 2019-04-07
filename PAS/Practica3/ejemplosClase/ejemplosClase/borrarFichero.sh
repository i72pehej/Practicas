#!/bin/bash
echo -n "Introduzca el nombre del fichero a borrar: "
read fichero

rm -i $fichero
echo "Fichero $fichero ha sido borrado del sistema!"

