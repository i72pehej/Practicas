#!/bin/bash
find -name "*.sh" | while read f
do
	echo -n "--> $f "
done
