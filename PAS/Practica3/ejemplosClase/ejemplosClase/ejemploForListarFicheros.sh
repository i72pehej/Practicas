#!/bin/bash

# Listar todos los ficheros del directorio actual
# incluyendo información del número de nodo
for x in *
do
  ls -i $x
done

# Listar todos los ficheros del directorio /bin
for x in /bin/*
do
  ls -i $x
done
