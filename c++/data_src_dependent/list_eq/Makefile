CC = c++

TARGET = list_eq

SRCS = $(TARGET).cpp
OBJS = $(SRCS:.cpp=.o)


include ../../../env_vars.mk

IFLAGS = -I$(BRIDGES_INCL) -I$(CURL_INCL) -I$(RAPID_JSON_INCL)

CPPFLAGS = -c -g $(IFLAGS) -std=c++11 -stdlib=libc++

LDFLAGS =  -L$(CURL_LIB_PATH)
LIBS =  -l$(CURL_LIB)

.SUFFIXES: .cpp

.cpp.o:  
	$(CC) $(CPPFLAGS)  $< -o $@

TARGET: $(OBJS) 
	$(CC) -g -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

clean:
	rm -f  $(TARGET) $(TARGET).o


# DO NOT DELETE

