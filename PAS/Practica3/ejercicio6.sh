#!/bin/bash

function listararchivos() {
  echo "<ul>"

  for x in $(find $1 -maxdepth 1); do
    # Si es un fichero.
    if [ ! -d "$x" ]; then
      echo "<li>$x</li>"

    # Si es un directorio.
    else
      echo "<li><strong>$x</strong></li>"
    fi

    listararchivos $x
  done

  echo "</ul>"
}

echo "<html>"
echo "<head>"
echo "<title><h3>listado dir de $1</h3></title>"
echo "</head>"
echo "<body>"

# Llamamos recursivamente a la función.
listararchivos $1

echo "</body>"
echo "</html>"

echo -e "\nTERMINADO!\n"
