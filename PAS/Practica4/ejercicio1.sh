# Crear un script que ejecute los comandos adecuados de grep que permitan realizar las si-
# guientes tareas sobre el fichero de ejemplo peliculas.txt:

if [ -f "$1" -a $# -eq 1 ]; then

  # 1. Mostrar aquellas líneas que contienen la duración de la película (uno o más
  # dígitos al principio de la línea, un espacio y la secuencia “min”).
  echo -e "\n********************************************************************"
  echo -e "\n1) Líneas con la duración de las películas.\n"
  # Opción -n: Muestra el número de la línea en la que sale lo encontrado.
  grep -n --colour '[0-9]hr [0-9][0-9]min' $1

  # 2. Mostrar aquellas líneas que contienen el país de la película (suponemos que
  # siempre aparecerá rodeado de guiones, p.ej. “-Estados Unidos-”).
  echo -e "\n********************************************************************"
  echo -e --colour "\n2) Líneas con el país de las películas.\n"
  # grep -En '\-[A-Z][a-z]+( [A-Z][a-z]+)*(, [A-Z][a-z]+)*\-' $1
  # Enlazamos con cualquier elemento (".") ninguna, una o más veces ("*"), siempre que estén entre guiones ("-").
  # Utilizamos "\" para que se tomen los guiones de forma literal.
  grep -n --colour '\-.*\-' $1

  # 3. Similar al ejercicio anterior, pero mostrar sólo los países (sin la línea completa).
  echo -e "\n********************************************************************"
  echo -e "\n3) Sólo el país de las películas.\n"
  grep -no --colour '\-.*\-' $1

  # 4. Contar cuantas películas son del 2016 y cuantas del 2017.
  echo -e "\n********************************************************************"
  echo -e "\n4) Contar el número de películas de cada año.\n"
  # Oción -c: Cuenta el número de líneas que coinciden.
  echo -e "Hay $(grep -c '\/2016)' $1) películas del 2016 y $(grep -c '\/2017)' $1) del 2017."

  # 5. Mostrar todo el fichero pero sin líneas vacías.
  echo -e "\n********************************************************************"
  echo -e "\n5) Sin líneas vacías.\n"
  grep '.' $1

  # 6. Mostrar aquellas líneas que empiezan por la letra E (haya o no espacios antes de la misma).
  echo -e "\n********************************************************************"
  echo -e "\n6) Líneas que empiezan con la letra <E> (con o sin espacios antes).\n"
  grep -E '^([[:space:]]*E)' $1

  # 7. Mostrar aquellas líneas que contengan una letra ’d’, ’l’ o ’t’, una vocal, y
  # la misma letra (por ejemplo, “Universidad”, “expectativas”, “dedicarse”...).
  echo -e "\n********************************************************************"
  echo -e "\n7) Líneas que contienen d, l, o t, una vocal y la misma letra.\n"
  grep -E '([dlt])[aeiou]\1' $1

  # 8. Todas aquellas líneas que tengan, en total, 8 vocales <a> o más (mayúsculas o minúsculas y
  # no necesariamente seguidas).
  echo -e "\n********************************************************************"
  echo -e "\n8) Líneas que contienen ocho <a> o más.\n"
  grep -E '([aA].*){7}[aA]+' $1

  # 9. Mostrar aquellas líneas que terminan con tres puntos (“...”) y no empiezan por espacio,
  # utilizando el operador de repetición \{...\} o {...}.
  echo -e "\n********************************************************************"
  echo -e "\n9) Líneas que terminan con tres puntos y no empiezan por espacio.\n"
  grep -E --colour '(^[^ ]).*[\.]{3}$' $1

  # 10. Utilizar sed para mostrar, entre comillas dobles, las vocales con tilde (mayúsculas o minúsculas).
  echo -e "\n********************************************************************"
  echo -e "\n10) Mostrar entre comillas las vocales con tilde.\n"
  sed -r 's/([áéíóúÁÉÍÓÚ])/"\1"/g' $1

  #*******************************************************************************
  echo -e "\n********************************************************************\n"

fi
