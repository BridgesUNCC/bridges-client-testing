#!/bin/sh

for i in *.java
do
	unifdef -DTESTING=1  $i > test.java
	mv test.java ../$i
done
