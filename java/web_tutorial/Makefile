
#
#Platform specific variables
#
include ../../env_vars.mk

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all


SRCS = arr1d.java arr2d.java arr3d.java sllist.java dllist.java csllist.java \
		cdllist.java  mllist.java tree.java bintree.java bst.java avl.java \
		graph_al.java graph_am.java  color_grid.java shape_collection.java kdt.java\

ADDITIONAL_SRCS = StudentInfo.java


OBJS = $(SRCS:.java=.class)

EXECUTABLES = $(OBJS:.class=)

test:
	echo $(OBJS)
	echo $(EXECUTABLES)

all : 
	javac $(SRCS)

run:
	ASSIGNMENTID=1000 ; for BINARY in $(EXECUTABLES); do \
		echo java $$BINARY $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER) ; \
		     java $$BINARY $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER) ; \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done

style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) $(STYLE_INCLUDES)

clean:
	rm -f  *.class



depend: $(SRCS)
	gcc -MD  $(IFLAGS) $(SRCS)

backup:
	tar cvfz bridges_cxx.tgz  src docs Makefile 
	cp bridges_cxx.tgz ~/Dropbox/.


# DO NOT DELETE
