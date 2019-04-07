#!/bin/bash

if [ ! $# -eq 1 ];
then
	echo "El uso del programa es $0 nombreFichero"
	exit 1
fi
if [ -f "$1" ];
then
	fecha="$(date +%d-%m-%y)"
	cp "$1" "$1.bak_$fecha"
else
	echo "El fichero no existe"
	exit 1
fi

