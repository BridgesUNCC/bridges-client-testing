#
#Platform specific variables
#

include ../../env_vars.mk

#
#

TARGET =  all

#SRCS should only be the python codes with a main function
SRCS = $(sort $(shell grep -l def\ main $(wildcard *.py)))



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
#That FORCE_BRIDGES_FRAMELIMIT stops the game assignment after 10 frames
	FORCE_BRIDGES_FRAMELIMIT=10 $(PYTHON) $(subst run_,,$@).py $(ASSIGNMENTIDTEST) $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER)

style:
	echo "Run make style against the master copy"
	exit -1;

backup:
	tar cvfz bridges_python.tgz  src docs Makefile 
	cp bridges_python.tgz ~/Dropbox/.


# DO NOT DELETE
