# Utilizando grep y/o sed para cada una de las siguientes tareas, realizar un script que reciba
# un nombre de fichero por la l´ınea de comandos y realice las siguientes tareas:
# Liste todos los ficheros ocultos de la carpeta personal del usuario ordenados por nu´ mero
# de caracteres.
# Haga una copia del fichero cuyo nombre se ha recibido por la l´ınea de comandos en la que
# se eliminan todas las l´ıneas vac´ıas. El nombre de la copia sera´ FICH.sinLineasVacias,
# siendo FICH el nombre del fichero que ha introducido el usuario. Esto se hara´ siempre que
# el fichero exista.
# Liste por pantalla todos los procesos que tu´ usuario esta´ ejecutando en ese momento. Para
# cada proceso debera´s mostrar PID, hora en que se lanzo´ y nombre del fichero ejecutable.
# Recorremos el archivo HOME y seleccionamos los que comiencen por ".".

for x in $(ls -a $HOME | grep '^\.'); do
  # Guardamos en numchar el número de caracteres del archivo.
  numchar=$(echo "$x" | wc -m)

  # Salida con formato <nombre archivo> <número de caracteres>.
  echo "$x $numchar"

# Ordenamos la salida por el número de caracteres y seleccionamos únicamente el nombre de los archivos.
done | sort -k2 -n | grep -E -o '^\.+.* '

echo -e "\n==========================================================\n"

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

echo -e "\n==========================================================\n"

# Filtramos la salida de los procesos en las columnas que deseamos.
# Eliminamos la primera fila, con los nombres de las columnas.
# Con el sed seleccionamos lo que queremos sustituir y lo modificamos.
ps -u $USER -o pid,start,cmd | sed '1d' | sed -r 's/([0-9]{1,}) ([0-9]{2}:[0-9]{2}:[0-9]{2}) (.+)/PID: "\1" Hora: "\2" Ejecutable: "\3"/'
