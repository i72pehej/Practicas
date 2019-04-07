#!/bin/bash

echo -n "Introduzca su nombre de usuario: "; read usuario

if [ "$usuario" == "$USER" ]
then
	echo "Bienvenido $USER"
else
	echo "Eso es mentira!"
fi
