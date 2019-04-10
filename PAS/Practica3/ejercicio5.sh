#!/bin/bash













#Segundos que han pasado desde 1/1/1970
date=$(date +%s)

for x in $(find copia.seg -type f); do
  modif=$(stat $x -c %X)
  time=$date-$modif

  if [$time -get 200]; then
    rm -f $x
  fi
done

tar -czf copia. . .. / . . .. /. . .  -$date.tar.gz $*
