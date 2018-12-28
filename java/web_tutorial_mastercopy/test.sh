#!/bin/sh

for file in *.java;
do
    unifdef -DTESTING=1  ${file} -o ../web_tutorial_testing/${file}
done

# unifdef -DTESTING=0  bst.java > test.java
# mv test.java tmp/bst.java
