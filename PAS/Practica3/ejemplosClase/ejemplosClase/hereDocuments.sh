#!/bin/bash

echo "Información del uso del programa"
echo "Lista y/o borra todos los enlaces de un directorio"
echo "USO : $0 [-d] [-oD ficheroLog] [-l] [-h] [directorio]"
echo "-d borrar los enlaces"
echo "-l listar los enlaces (por defecto)"
echo "-o escribir los enlaces encontrados en un fichero de log"
echo "-D borrar los enlaces que haya dentro de un fichero de log"
echo "-h mostrar este mensaje"
cat << EOF
Información del uso del programa
Lista y/o borra todos los enlaces de un directorio
USO : $0 [-d] [-oD ficheroLog] [-l] [-h] [directorio]
-d borrar los enlaces
-l listar los enlaces (por defecto)
-o escribir los enlaces encontrados en un fichero de log
-D borrar los enlaces que haya dentro de un fichero de log
-h mostrar este mensaje
EOF

