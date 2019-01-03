
include ../../env_vars.mk

TARGET =  all

# Incude and Library paths

DIRS=$(sort $(shell find * -maxdepth 0 -mindepth 0 -type d))

ASSIGNMENTIDSTART=2100
ASSIGNMENTIDTEST=2199

all:
	for dir in $(DIRS); do \
		echo "cd $$dir; javac *.java;" ; \
		     ( cd $$dir; javac *.java; );  \
	done

run:
	ASSIGNMENTID=$(ASSIGNMENTIDSTART) ; for TEST in $(DIRS); do \
		echo Testing $$TEST; \
		( \
			cd $$TEST; \
			java $$TEST $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER) ; \
		) ; \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done

run_%:
	cd $(subst run_,,$@); java $(subst run_,,$@) $(ASSIGNMENTIDTEST) $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)

clean:
	for dir in $(DIRS); do \
		echo "cd $$dir; rm *.class;" ; \
		( cd $$dir; rm *.class ) ; \
	done

