#!/bin/bash














function listararchivos()
{
  echo "<ul>"

  for x in $(find $1 -maxdepth 1); do
    if [ .. .. .. . .. directorio o archivo ???]; then
      echo "<li><strong>$x</strong></li>"
    fi
  done

  echo "</ul>"
}

echo "<html>"
echo "<head>"
echo "<title><h3>listado dir de $1</h3></title>"
echo "</head>"
echo "<body>"

listararchivos $1

echo "</body>"
echo "</html>"
