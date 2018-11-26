
TARGET =  all

# Incude and Library paths


all : make_java make_c++ make_python

make_java:
	cd java; sh to_krs.sh; make; make run; sh to_site.sh;

make_c++:
	cd c++; sh to_krs.sh; make; make run; sh to_site.sh;

make_python:
	cd python; sh to_krs.sh; make; make run; sh to_site.sh;

to_html:
	/bin/sh ./to_html_creds.sh

