

#
#Platform specific variables
#
include ../../env_vars.mk

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all


SRCS = $(wildcard *.cpp *.h)


OBJS = $(SRCS:.cpp=.o)

EXECUTABLES = $(SRCS:.cpp=)

STYLE_INCLUDES = $(wildcard *.h)

# Incude and Library paths



# Include and library flags

IFLAGS = -I$(BRIDGES_INCL)  -I$(CURL_INCL)  -I$(RAPID_JSON_INCL) -DTESTING=1
LDFLAGS =  -L$(CURL_LIB_PATH) $(LOCALLDFLAGS)
CXXFLAGS = -g $(IFLAGS) -std=c++11 $(LOCALCXXFLAGS)

# Libraries

LIBS = -l$(CURL_LIB)


all: testing webversion

../web_tutorial_testing/:
	mkdir ../web_tutorial_testing/

../web_tutorial_testing/%.cpp: %.cpp ../web_tutorial_testing/
	unifdef -DTESTING=1 -o ../web_tutorial_testing/$< $< ; [ $$? != 2 ]

../web_tutorial_testing/%.h: %.h ../web_tutorial_testing/
	unifdef -DTESTING=1 -o ../web_tutorial_testing/$< $<; [ $$? != 2 ]


testing: $(patsubst %,../web_tutorial_testing/%,$(SRCS))

../web_tutorial_fortheweb/:
	mkdir ../web_tutorial_fortheweb/

../web_tutorial_fortheweb/%.cpp: %.cpp ../web_tutorial_fortheweb/
	unifdef -DTESTING=0 -o ../web_tutorial_fortheweb/$< $< ; [ $$? != 2 ]

../web_tutorial_fortheweb/%.h: %.h ../web_tutorial_fortheweb/
	unifdef -DTESTING=0 -o ../web_tutorial_fortheweb/$< $< ; [ $$? != 2 ]

webversion: $(patsubst %,../web_tutorial_fortheweb/%,$(SRCS))

run_%: ../web_tutorial_testing/%.cpp
	cd ../web_tutorial_testing/; make $@

style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) $(STYLE_INCLUDES)



depend: $(SRCS)
	gcc -MD  $(IFLAGS) $(SRCS)

backup:
	tar cvfz bridges_cxx.tgz  src docs Makefile 
	cp bridges_cxx.tgz ~/Dropbox/.


# DO NOT DELETE
