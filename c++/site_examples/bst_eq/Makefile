TARGET = bst_eq

SRCS = bst_eq.cpp
OBJS = $(SRCS:.cpp=.o)


include ../../../env_vars.mk

IFLAGS = -I$(BRIDGES_INCL) -I../shaffer_incl  -I$(CURL_INCL) -I$(RAPID_JSON_INCL)

CPPFLAGS = -c -g $(IFLAGS) -std=c++11 -stdlib=libc++

LDFLAGS =  -L$(CURL_LIB_PATH)
LIBS =  -l$(CURL_LIB)

.SUFFIXES: .cpp

.cpp.o:  
	$(CXX) $(CPPFLAGS)  $< -o $@

TARGET: $(OBJS) 
	$(CXX) -g -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

clean: 
	rm -f $(TARGET) *.o


# DO NOT DELETE

