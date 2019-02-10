CC = c++

TARGET = graph_osm

SRCS = graph_osm.cpp
OBJS = $(SRCS:.cpp=.o)

BRIDGES_INCL = $(HOME)/gr/bridges/client/cxx/src
RAPID_JSON_INCL =  /usr/local/rapidjson/include
IFLAGS = -I.  -I/usr/local/curl760/include/curl -I$(BRIDGES_INCL)  -I$(RAPID_JSON_INCL)

CPPFLAGS = -c -g $(IFLAGS) -std=c++11 -stdlib=libc++

LDFLAGS =  -L/usr/local/curl760/lib
LIBS =  -lcurl

.SUFFIXES: .cpp

.cpp.h: $(INCLUDES)
	$(CC) $(CPPFLAGS)  $< -o $@

.cpp.o:  
	$(CC) $(CPPFLAGS)  $< -o $@

TARGET: $(OBJS) 
	$(CC) -g -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

clean:
	rm bstTest.o bstt


# DO NOT DELETE

