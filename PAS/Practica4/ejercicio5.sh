# Escribir un script que lea informacio´n de la carpeta /proc/ e imprima:
# Modelo de procesador y Megahercios.
# Taman˜ o de cache´ e identificador de vendedor.
# Nu´ mero ma´ximo de hilos de ejecucio´n.
# Puntos de montaje activos, incluyendo el punto de montaje, el dispositivo y el tipo de dispositivo.
# Ordenarlos de forma alfabe´tica inversa por punto de montaje.
# Listado de todas las particiones disponibles, junto con su nu´ mero de bloques. Ordenarlas
# de forma alfabe´tica inversa por particio´n.
# Los ficheros que debera´s consultar son /proc/cpuinfo, /proc/mounts y /proc/partitions.
sacar el archivo, mirar las columnas y ordenarlas por la que me interese.

SED -> sed -r -n '3,$ s/.....' -> Necesita direccionamiento porque no consideras las lineas de titulos y espacio etc etc etc
