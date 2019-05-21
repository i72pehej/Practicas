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
comprobar que ejecutan comandos de bash /bin/bash . . .

oldIFS=$IFS
IFS=':'

while read -a fila; do
  grupo -> lo sacas de SED en etc/group basandote en el GID
  logged -> los sacas del comando WHO debe coincidir con el que está en fila 0. WHO | Grep -c
  echo -e "\n=========================" \
           "\nNombre: ${Fila[n]}" \
           "\nUID: $..."
            ...
              ...
                ...
                  ...

done < etc/password

IFS=oldIFS
