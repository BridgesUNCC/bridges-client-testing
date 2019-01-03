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


ASSIGNMENTIDSTART=2000
ASSIGNMENTIDTEST=2099


all : $(OBJS)

%.class: %.java
	javac $<

run:
	ASSIGNMENTID=$(ASSIGNMENTIDSTART) ; for TEST in $(SRCS:.java=); do \
		echo "java $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER)" ; \
		      java $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER) ; \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done

run_%:
	java $(subst run_,,$@) $(ASSIGNMENTIDTEST) $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)


style:  
#	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS)
	echo "You should run the styling from the master copy and not the testing copy!!!!!"
	exit -1


clean: 
	/bin/rm -f  *.class
