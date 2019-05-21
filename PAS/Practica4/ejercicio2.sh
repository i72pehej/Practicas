# Utilizando sed, hacer un script que, dado el fichero de texto peliculas.txt, elimine las
# líneas vacías y los subrayados, extraiga el título de la película y lo sitúe
# en una línea independiente como “Título: XXX”, la fecha de estreno como “|->
# Fecha de estreno: XXX”, formatee el director y el reparto como “|-> Director: XXX”
# y “|-> Reparto: XXX” y la duración como “|-> Duración: XXX”. El script recibirá
# el nombre del fichero por la l ́ınea de comandos.
sed '/^$/d' $1 | sed -r '/=+/d' | sed -r 's/\((.{2}\/.{2}\/.{4})\) (.+)/|-> Fecha de estreno: \1/' | sed -r 's/Dirigida por (.+)/|-> Director: \1/' | sed -r 's/Reparto: (.+)/|-> Reparto: \1/' | sed -r 's/([1-2]hr [0-5][0-9]min)/|-> Duración: \1/' | sed -r '/^ +.+$/d' | sed -r 's/(^[^\|])/Título: \1/'

# # Elimina líneas vacías.
# sed '/^$/d'
#
# # Elimina los subrayados.
# sed -r '/=+/d'
#
# # Sustituye la fecha con formato (DD/MM/AAAA) por “|-> Fecha de estreno: XXX”.
# sed -r 's/(\(.{2}\/.{2}\/.{4}\)) (.+)/|-> Fecha de estreno: \1/'
#
# # Sustituye la línea "Dirigida por ..." por “|-> Director: XXX”.
# sed -r 's/Dirigida por (.+)/|-> Director: \1/'
#
# # Sustituye la línea "Reparto: ..." por “|-> Reparto: XXX”.
# sed -r 's/Reparto: (.+)/|-> Reparto: \1/'
#
# # Sustituye la duración con formato "Xhr XXmin" por “|-> Duración: XXX”.
# sed -r 's/([1-2]hr [0-5][0-9]min)/|-> Duración: \1/'
#
# # Elimina la línea de la descripción.
# sed -r '/^ +.+/d'
#
# # Sustituye la línea del título por “Título: XXX”.
# sed -r -e 's/(^[^\|])/Título: \1/'
