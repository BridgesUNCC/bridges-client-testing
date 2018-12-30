
#
#Platform specific variables
#

include ../../env_vars.mk

CC = clang++
HOME = C:/Users/mrm27
BRIDGES_INCL = $(HOME)/Desktop/bridges-python/Bridges
CURL_INCL = /usr/local/curl760/include
CURL_LIB_PATH = /usr/local/curl760/lib
CURL_LIB = curl
RAPID_JSON_INCL = /usr/local/rapidjson/include

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all


SRCS = array1d.py sllist.py dllist.py circ_sllist.py circ_dllist.py	\
		mllist.py tree.py bintree.py bst.py	avl.py	graph_alist.py \
		graph_amatrix.py StudentInfo.py color_grid.py


all : $(SRCS)

run:
	ASSIGNMENTID=3000 ; for TEST in $(SRCS:.py=); do \
		echo "python $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER)" ; \
		      python $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER) ; \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done


to_html:
	/bin/sh ./to_html_creds.sh

to_srcs:
	/bin/sh ./to_krs.sh

to_site:
	/bin/sh ./to_site.sh
	zip bridges-python-1.0.zip 
	
	
	

backup:
	tar cvfz bridges_python.tgz  src docs Makefile 
	cp bridges_python.tgz ~/Dropbox/.


# DO NOT DELETE
