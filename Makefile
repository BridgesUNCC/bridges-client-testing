
TARGET =  all

# Incude and Library paths


all : make_java make_c++ make_python

make_java:
	cd java/web_tutorial; make; make run; 

make_c++:
	cd c++/web_tutorial; make; make run;

make_python:
#	cd python/web_tutorial; make; make run; 

clean:
	cd java/web_tutorial; make clean;
	cd c++/web_tutorial; make clean;
	

