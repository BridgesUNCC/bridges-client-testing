
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

INCLUDES = 	DataStructure.h Array.h Element.h SLelement.h DLelement.h \
			CircSLelement.h CircDLelement.h MLelement.h \
			TreeElement.h BTElement.h BSTElement.h AVLTreeElement.h \
			GraphAdjList.h GraphAdjMatrix.h \
			SymbolCollection.h Symbol.h \
			Rectangle.h Circle.h Polygon.h Label.h \
			ElementVisualizer.h	LinkVisualizer.h Color.h Edge.h base64.h\
			Bridges.h Connector.h \
			data_src/ActorMovieIMDB.h \
			data_src/EarthquakeUSGS.h \
			data_src/Book.h \
			data_src/Game.h \
			data_src/CancerIncidence.h \
			data_src/GutenbergBook.h \
			data_src/Shakespeare.h \
			data_src/Song.h

STYLE_INCLUDES = BST.h StudentInfo.h

# Incude and Library paths



# Include and library flags

IFLAGS = -I$(BRIDGES_INCL)  -I$(CURL_INCL)  -I$(RAPID_JSON_INCL) -DTESTING=1
LDFLAGS =  -L$(CURL_LIB_PATH) $(LOCALLDFLAGS)
CXXFLAGS = -g $(IFLAGS) -std=c++11 $(LOCALCXXFLAGS)

# Libraries

LIBS = -l$(CURL_LIB)

.SUFFIXES: .cpp .o

%: %.cpp
	$(CXX) -g -o $@ $< $(CXXFLAGS) $(LDFLAGS) $(LIBS)

.o:
	$(LD) $(LDFLAGS)  $< -o $@ $(LIBS)

.cpp.o:
	$(CXX) -c -g -o $@ $< $(CXXFLAGS)


all : $(EXECUTABLES)

run:
	for BINARY in $(EXECUTABLES); do \
		./$$BINARY $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY) $(BRIDGES_SERVER); \
	done

style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) $(STYLE_INCLUDES)

clean:
	rm -f $(EXECUTABLES) $(OBJS)



depend: $(SRCS)
	gcc -MD  $(IFLAGS) $(SRCS)

backup:
	tar cvfz bridges_cxx.tgz  src docs Makefile 
	cp bridges_cxx.tgz ~/Dropbox/.


# DO NOT DELETE
