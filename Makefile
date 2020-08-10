
TARGET =  all

# Incude and Library paths


all : make_java make_c++ make_python

make_web:
	cd java/web_tutorial_mastercopy; make webversion
	cd c++/web_tutorial_mastercopy; make webversion
	cd python/web_tutorial_mastercopy; make webversion

make_testing:
	cd java/web_tutorial_testing/; make test_clean
	cd java/web_tutorial_mastercopy; make testing
	cd c++/web_tutorial_testing/; make test_clean
	cd c++/web_tutorial_mastercopy; make testing
	cd python/web_tutorial_testing/; make test_clean
	cd python/web_tutorial_mastercopy; make testing

make_java:
	cd java/web_tutorial_mastercopy; make testing;
	cd java/web_tutorial_testing; make; make run;
	cd java/data_src_dependent; make; make run;

make_c++:
	cd c++/web_tutorial_mastercopy; make testing;
	cd c++/web_tutorial_testing; make; make run;
	cd c++/data_src_dependent; make; make run;

make_python:
	cd python/web_tutorial_mastercopy; make testing; 
	cd python/web_tutorial_testing; make; make run;

clean:
	cd c++/web_tutorial_testing; make clean;
	cd c++/data_src_dependent; make clean;
	cd java/web_tutorial_testing; make clean;
	cd java/data_src_dependent; make clean;


