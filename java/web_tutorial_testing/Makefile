#
#Platform specific variables
#

include ../../env_vars.mk

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all

OBJS = $(SRCS:.java=.class)


SRCS = arr1d.java arr2d.java arr3d.java sllist.java dllist.java csllist.java \
		cdllist.java  mllist.java tree.java bintree.java bst.java avl.java \
		graph_al.java graph_am.java color_grid.java kdt.java shape_collection.java

all : 
	javac $(SRCS)

run:
	ASSIGNMENTID=2000 ; for TEST in $(SRCS:.java=); do \
		echo "java $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)" ; \
		      java $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER) ; \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done

style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) 



clean: 
	/bin/rm -f  *.class
