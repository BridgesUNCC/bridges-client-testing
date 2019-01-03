
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


all : $(SRCS)

run:
	ASSIGNMENTID=3000 ; for TEST in $(SRCS); do \
		echo "python $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER)" ; \
		      python $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER) ; \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done


backup:
	tar cvfz bridges_python.tgz  src docs Makefile 
	cp bridges_python.tgz ~/Dropbox/.


# DO NOT DELETE
