#!/bin/bash

# Si no se introduce la carpeta para crear copia de seguridad.
if [ $# -eq 0 ]; then
  echo -e "\nERROR. Imposible crear copia de seguridad."
  echo -e "No se ha introducido ningún argumento.\n"
  exit 1
fi

# Comprobamos que no exista el directorio de copia de seguridad y lo creamos.
if [ ! -e $HOME/Copia ]; then
  echo -e "\nCreando la carpeta de copia de seguridad . . .\n"
  mkdir $HOME/Copia
fi

# Borramos los archivos que sean más antiguos a 200 segundos.
if [ -d $HOME/Copia ]; then
  #Segundos que han pasado desde 1/1/1970
  date=$(date +%s)

  for x in $(find $HOME/Copia/ -type f); do
    # Última modificación del fichero
    modif=$(stat $x -c %X)
    time=$date-$modif

    # Si la diferencia es mayor a 200, borramos.
    if [$time -get 200]; then
      rm -f $x
    fi
  done
fi

# Comprimimos los archivos válidos.

# tar ->  Comprime el archivo.
# c   ->  Crea un nuevo archivo.
# z   ->  Comprime el archivo usando gzip.
# f   ->  Nombre del archivo. Si pusiéramos v -> Muestra el proceso durante la creación del archivo.
tar -czf copia-$USER-$date.tar.gz $*

# Movemos el archivo comprimido al directorio Copia.
mv copia-$USER-$fecha.tar.gz $HOME/Copia/
echo -e "\nLa copia de seguridad se ha creado correctamente.\n"
