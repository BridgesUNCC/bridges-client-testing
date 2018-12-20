
#
#Platform specific variables
#
CC = javac

HOME = /Users/krs

include ../../env_vars.mk

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all

OBJS = $(SRCS:.java=.class)


SRCS = arr1d.java arr2d.java arr3d.java sllist.java dllist.java csllist.java \
		cdllist.java  mllist.java tree.java bintree.java bst.java avl.java \
		graph_al.java graph_am.java color_grid.java

all : 
	javac $(SRCS)

run:
	java arr1d $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	java arr2d $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java arr3d $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java sllist $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java dllist $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java csllist $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java cdllist $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java mllist $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java tree $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java bintree $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java bst $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java avl $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java graph_al $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java graph_am $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);
	java color_grid $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER);

style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) 



clean: 
	/bin/rm -f  *.class
