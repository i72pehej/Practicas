#!/bin/bash


if [ -d "$1" -a !$* ]; then

fi

if [ -d "$1" -a -n "$2" -a -n "$3" -a !$* ]; then

fi



mkdir peq
for x in $(find $1 -size "-$umbral1"c -type f); do
  cp $x peq
done
