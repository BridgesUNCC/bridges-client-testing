
#
#Platform specific variables
#

include ../../env_vars.mk

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all


SRCS = array1d.py sllist.py dllist.py circ_sllist.py circ_dllist.py	\
		mllist.py tree.py bintree.py bst.py	avl.py	graph_alist.py \
		graph_amatrix.py StudentInfo.py color_grid.py


ASSIGNMENTIDSTART=3000
ASSIGNMENTIDTEST=3099

all : $(SRCS)

run:
	ASSIGNMENTID=$(ASSIGNMENTIDSTART) ; for TEST in $(SRCS); do \
		echo "$(PYTHON) $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER)" ; \
		      $(PYTHON) $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER) ; \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done

run_%:
	$(PYTHON) $(subst run_,,$@).py $(ASSIGNMENTIDTEST) $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER)

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
