#!/bin/sh

for file in *.java
do
    unifdef -DTESTING=0 ${file} -o ../web_tutorial_fortheweb/${file}
done
