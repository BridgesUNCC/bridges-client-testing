
TARGET =  all

# Incude and Library paths


all : make_java make_c++ make_python

make_java:
	cd java; make; make run; 

make_c++:
	cd c++; make; make run;

make_python:
	cd python; make; make run; 

