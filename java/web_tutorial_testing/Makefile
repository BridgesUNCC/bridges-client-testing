#
#Platform specific variables
#

include ../../env_vars.mk

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all



SRCS = $(sort $(shell grep -l public\ static\ void\ main *.java ) )

OBJS = $(SRCS:.java=.class)


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
