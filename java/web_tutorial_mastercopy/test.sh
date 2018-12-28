#!/bin/sh

for file in *.java;
do
    unifdef -DTESTING=1  ${file} -o ../web_tutorial_testing/${file}
done

