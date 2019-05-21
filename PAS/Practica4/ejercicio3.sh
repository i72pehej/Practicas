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
for x in $(ls -a $HOME | grep '\.'); do
  numchar = $(echo "$x" | wc -m)
  echo "$x $numchar"
done | sort -k2 -n | grep -E -o '\.* ' //// awk "{print $1}"

# Sin líneas vacías:
# grep -v '^+$' > ficheronombreadad
#
# Listado procesos:
# ps xu -> Los últimos son Time Command, por ahí el PID. Quedarme con las columnas con el SED.
