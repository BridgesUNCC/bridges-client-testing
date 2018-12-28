#!/bin/sh

TESTING_MODE=0

for file in *.java
do
	if test "${TESTING_MODE}" -eq 0 ; then
		unifdef -DTESTING=0 ${file} > ../web_tutorial_fortheweb/${file}
	else
		unifdef -DTESTING=1 ${file} > ../web_tutorial/${file}
	fi

done
