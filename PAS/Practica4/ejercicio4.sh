# A partir de un fichero de texto con una serie de direcciones IP (IPs.txt), haz un script que
# sea capaz de hacer ping a cada una de dichas direcciones y de imprimirlas en orden segun lo que
# tardan en contestar (por ejemplo, para configurar el servidor DNS mas adecuado). El nombre
# del fichero con las IPs se pasara´ como argumento a la lınea de comandos. El segundo argumento
# sera´ el numero de segundos que deben de pasar antes de dar por muerto al servidor. Deberas
# investigar sobre el comando ping para configurarlo de forma que se mande un solo ping. Si la
# maquina a la que env´ıa el ping no esta activa, el comando ping devolvera un codigo de error
# distinto de cero al sistema operativo.


# Creación de ficheros temporales para gestionar mejor las salidas.
leido=$(mktemp)
ans=$(mktemp)
fallo=$(mktemp)

# Recorrido del fichero completo haciendo ping.
for x in $(cat $1); do
  ping -c 1 -W $2 $x > $leido
  # -c: Número de bloques a enviar. En nuestro caso 1 para hacer el ping.
  # -W: Tempo que espera para la recepción de una respuesta.

  # Comprobación del resultado devuelto por el ping.
  if [ $? -eq 0 ]; then
    cat $leido | sed -n -r -e 's/(.+from )(.+)(:.+ )(time=)(.+)(ms)/La IP \2 respondió en \5 milisegundos/p' >> $ans
  else
    echo "La IP $x no respondió tras $2 segundo/s." >> $fallo
  fi
done

# Ordenamos la salida por los milisegundos.
sort -n -k5 $ans

echo ""

# Imprimimos el fichero con los fallos.
cat $fallo

# Borramos ficheros temporales.
rm $leido
rm $ans
rm $fallo
