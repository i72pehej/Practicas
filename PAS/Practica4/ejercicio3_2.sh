
# Recorremos el archivo HOME y seleccionamos los que comiencen por ".".
for x in $(ls -a $HOME | grep '^\.'); do
  # Guardamos en numchar el número de caracteres del archivo.
  numchar=$(echo "$x" | wc -m)

  # Salida con formato <nombre archivo> <número de caracteres>.
  echo "$x $numchar"

# Ordenamos la salida por el número de caracteres y seleccionamos únicamente el nombre de los archivos.
done | sort -k2 -n | grep -E -o '^\.+.* '

# ==========================================================

# Control de errores.
if [ -f "$1" -a $# -eq 1 ]; then
  echo -e "\nEl fichero a procesar es: $1."
  echo -e "\nCreando el fichero copia . . ."

  # Seleccionamos lo opuesto a líneas vacías y lo introducimos en un fichero concreto.
  grep -v '^$' $1 > /home/i72pehej/PracticasV2/PAS/Practica4/$1.sinLineasVacias

  echo -e "\nEl fichero sin líneas vaías se ha guardado en <$1.sinLineasVacias>\n"
else
  echo -e "\nERROR. Se necesita añadir un fichero válido.\n"
fi

# ==========================================================

echo -e "\nListado de procesos ejecutados por el usuario $USER:\n"

# Borramos la primera línea de la salida.
ps xu | sed '1d'

# for x in $(ps xu); do
#   PID=$(grep 'i72pehej')
#   Hora=$()
#   Ejecutable=$()
# done
