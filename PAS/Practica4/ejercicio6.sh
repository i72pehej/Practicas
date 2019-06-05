# Desarrollar un script que muestre el contenido del fichero /etc/passwd (y parte del fichero
# /etc/group) de forma amigable. El script recibira´ un u´ nico argumento que sera´ una cadena de
# texto. Solo se mostrara´n los usuarios que tengan esa cadena como shell de sistema (comprobar
# que la cadena esta´ justo en ese campo y no en otro). Por cada usuario se imprimira´:
# logname del usuario.
# UID del usuario.
# groupname de su grupo primario.
# GID de su grupo primario.
# Informacio´n gecos.
# Carpeta personal.
# Shell por defecto.
# Un 1 si el usuario esta´ actualmente logeado y un 0 en caso contrario.

if [ $# -eq 1 ]; then

  #La primera línea en la que aparece el campo grupo. Se irá incrementando de 9 en 9.
  lineaGrupo=$[4]
  lineaLog=$[9]

  # grep para seleccionar las lineas que terminan igual a la escrita y sed para modificar la salida.
  grep -E "$1$" /etc/passwd | sed -re "s/^(.*):.*:(.*):(.*):(.*):(.*):(.*)$/==========\n-> Logname:\1\n-> UID:\2\n-> Grupo:\n-> GID:\3\n-> gecos:\4\n-> Home:\5\n-> Shel por defecto:\6\n-> Logueado:/" > fichero.txt

  # Compobamos que esté loggeado.
  grupoID=$(grep -E "$1$" /etc/passwd | sed -re "s/^.*:.*:.*:(.*):.*:.*:.*$/\1/")
  usuario=$(grep -E "$1$" /etc/passwd | sed -re "s/^(.*):.*:.*:.*:.*:.*:.*$/\1/")

  # Recorremos los ficheros con la información.
  for x in $grupoID; do
    nombreGrupo=$(sed -nre "s/^(.*):.*:$x:.*$/\1/p" /etc/group)
    sed -re ""$lineaGrupo" s/^(.*)$/\1$nombreGrupo/" fichero.txt
    lineaGrupo=$[$lineaGrupo+9]
  done

  for x in $usuario; do
    # who para obtener el usuario.
    if [ "$(who | grep "^$x.*$")" ]; then
      # -i ->
      sed -re ""$lineaLog" s/^(.*)$/\11/" fichero.txt
    else
      sed -re ""$lineaLog" s/^(.*)$/\10/" fichero.txt
    fi

    lineaLog=$[$lineaLog+9]
  done

  # Imprimir y borrar el fichero.
  cat fichero.txt
  rm fichero.txt

else
  echo -e "\nERROR. El formato introducido es incorrecto."
  echo -e "\nDebe ser: <EJECUTABLE> <CADENA>."
fi
