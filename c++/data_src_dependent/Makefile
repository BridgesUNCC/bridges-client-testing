
include ../../env_vars.mk

TARGET =  all

# Incude and Library paths

DIRS=$(sort $(shell find * -maxdepth 0 -mindepth 0 -type d))

ASSIGNMENTIDSTART=1100
ASSIGNMENTIDTEST=1199

all:
	for dir in $(DIRS); do \
		echo "cd $$dir; make $$dir;" ; \
		    ( cd $$dir; make $$dir; );  \
	done

run:
	ASSIGNMENTID=$(ASSIGNMENTIDSTART) ; for dir in $(DIRS); do \
		echo "cd $$dir; ./$$dir $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER) ;" ; \
		    ( cd $$dir; ./$$dir $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER) ; );  \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done

run_%:
	cd $(subst run_,,$@); make $(subst run_,,$@);
	cd $(subst run_,,$@); ./$(subst run_,,$@) $(ASSIGNMENTIDTEST) $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER) ;

style:
	for dir in $(DIRS); do \
		echo "cd $$dir; make style;" ; \
		    ( cd $$dir; make style; );  \
	done


clean:
	for dir in $(DIRS); do \
		echo "cd $$dir; make clean;" ; \
		    ( cd $$dir; make clean; );  \
	done


