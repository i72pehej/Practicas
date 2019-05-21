# A partir de un fichero de texto con una serie de direcciones IP (IPs.txt), haz un script que
# sea capaz de hacer ping a cada una de dichas direcciones y de imprimirlas en orden segu´ n lo que
# tardan en contestar (por ejemplo, para configurar el servidor DNS ma´s adecuado). El nombre
# del fichero con las IPs se pasara´ como argumento a la l´ınea de comandos. El segundo argumento
# sera´ el nu´ mero de segundos que deben de pasar antes de dar por muerto al servidor. Debera´s
# investigar sobre el comando ping para configurarlo de forma que se mande un solo ping. Si la
# ma´quina a la que env´ıa el ping no esta´ activa, el comando ping devolvera´ un co´digo de error
# distinto de cero al sistema operativo.
ping -c 1 -w $2 IP
for x in $(cat $1); do
  ans=$(ping -c 1 -w $1 $x)
  cosillas que hay que hacer... SED
  echo "la IP $x respondió en $askld segundos"
done | sort -k6
