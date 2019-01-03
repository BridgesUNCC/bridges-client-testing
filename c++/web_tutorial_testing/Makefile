
#
#Platform specific variables
#
include ../../env_vars.mk

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all


SRCS = array.cpp array2d.cpp array3d.cpp sllist.cpp dllist.cpp circ_sllist.cpp \
		circ_dllist.cpp  mllist.cpp tree.cpp bintree.cpp bst.cpp avl.cpp \
		graph_alist.cpp graph_amatrix.cpp  color_grid.cpp shape_collection.cpp kdt.cpp


OBJS = $(SRCS:.cpp=.o)

EXECUTABLES = $(SRCS:.cpp=)

STYLE_INCLUDES = BST.h StudentInfo.h

# Incude and Library paths



# Include and library flags

IFLAGS = -I$(BRIDGES_INCL)  -I$(CURL_INCL)  -I$(RAPID_JSON_INCL) -DTESTING=1
LDFLAGS =  -L$(CURL_LIB_PATH) $(LOCALLDFLAGS)
CXXFLAGS = -g $(IFLAGS) -std=c++11 $(LOCALCXXFLAGS)

# Libraries

LIBS = -l$(CURL_LIB)

ASSIGNMENTIDSTART=1000
ASSIGNMENTIDTEST=1099

.SUFFIXES: .cpp .o

%: %.cpp
	$(CXX) -g -o $@ $< $(CXXFLAGS) $(LDFLAGS) $(LIBS)

.o:
	$(LD) $(LDFLAGS)  $< -o $@ $(LIBS)

.cpp.o:
	$(CXX) -c -g -o $@ $< $(CXXFLAGS)


all : $(EXECUTABLES)

run:
	ASSIGNMENTID=$(ASSIGNMENTIDSTART) ; for BINARY in $(EXECUTABLES); do \
		echo ./$$BINARY $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER) ; \
		     ./$$BINARY $$ASSIGNMENTID $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER) ; \
		ASSIGNMENTID=`expr $$ASSIGNMENTID + 1`; \
	done

run_%: %
	./$(subst run_,,$@) $(ASSIGNMENTIDTEST) $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)

clean:
	rm -f $(EXECUTABLES) $(OBJS)



depend: $(SRCS)
	gcc -MD  $(IFLAGS) $(SRCS)

backup:
	tar cvfz bridges_cxx.tgz  src docs Makefile 
	cp bridges_cxx.tgz ~/Dropbox/.


# DO NOT DELETE
