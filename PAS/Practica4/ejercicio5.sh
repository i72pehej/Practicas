# Escribir un script que lea informacio´n de la carpeta /proc/ e imprima:
# Modelo de procesador y Megahercios.
# Tamaño de cache´ e identificador de vendedor.
# Numero maximo de hilos de ejecucion.
# Puntos de montaje activos, incluyendo el punto de montaje, el dispositivo y el tipo de dispositivo.
# Ordenarlos de forma alfabetica inversa por punto de montaje.
# Listado de todas las particiones disponibles, junto con su nu´ mero de bloques. Ordenarlas
# de forma alfabetica inversa por particion.
# Los ficheros que deberas consultar son /proc/cpuinfo, /proc/mounts y /proc/partitions.

# Se hace el sed para seleccionar lo deseado y se pone head -1 para que sólo salga la primera ocurrencia.
cat /proc/cpuinfo | sed -nre 's/model name.+: (.+)/Modelo del procesador: \1/p' | head -1
cat /proc/cpuinfo | sed -nre 's/cpu MHz.+: (.+)/Megahercios: \1/p' | head -1
# En este caso contamos el número de veces que se ofrece la información de cpu, lo que implica los diferentes hilos.
echo "Número de hilos máximo de ejecución: $(cat /proc/cpuinfo | grep -E '^processor' | wc -l)"
cat /proc/cpuinfo | sed -nre 's/cache size: (.+)/Tamaño de caché: \1/p' | head -1
cat /proc/cpuinfo | sed -nre 's/vendor_id.+: (.+)/ID vendedor: \1/p' | head -1

echo -e "\n=============================================================\n"

echo -e "Puntos de montaje:\n"
cat /proc/mounts | sed -nre 's/(^\/*[a-z]+)( )(.+)( )([a-z]+)( )(.+)/-> Punto de montaje: \3, Dispositivo: \1, Tipo de dispositivo: \5/p' | sort -r -k2

echo -e "\n=============================================================\n"

echo -e "Particiones y número de bloques:\n"
# awk para seleccionar las columnas, sed para borrar las primeras 2 filas y otro sed para seleccionar lo deseado.
cat /proc/partitions | awk '{print $3, $4}'| sed -e '1,2d' | sed -nre 's/([0-9]+)( )(.+)/-> Partición: \3, Número de Bloques: \1/p'
