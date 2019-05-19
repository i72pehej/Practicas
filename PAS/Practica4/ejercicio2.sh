# Utilizando sed, hacer un script que, dado el fichero de texto peliculas.txt, elimine las
# líneas vacías y los subrayados, extraiga el título de la película y lo sitúe
# en una línea independiente como “Título: XXX” 1 , la fecha de estreno como “|->
# Fecha de estreno: XXX”, formatee el director y el reparto como “|-> Director: XXX”
# y “|-> Reparto: XXX” y la duración como “|-> Duración: XXX”. El script recibirá
# el nombre del fichero por la l ́ınea de comandos.
sed '/^$/d' $1 | sed -r '/=+/d' | sed -r 's/([])/|-> Fecha de estreno: \1/' |


sed '/^$/d' $1
sed -r '/=+/d'
sed -r 's/([])/|-> Fecha de estreno: \1/'
