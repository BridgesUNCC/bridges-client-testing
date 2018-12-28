#!/bin/sh

unifdef -DTESTING=0  bst.java > test.java
mv test.java tmp/bst.java
