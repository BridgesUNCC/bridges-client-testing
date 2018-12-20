CC = javac

TARGET = list_imdb

SRCS = $(TARGET).java
OBJS = $(SRCS:.cpp=.class)


include ../../../env_vars.mk

IFLAGS = -I$(BRIDGES_INCL) -I$(CURL_INCL) -I$(RAPID_JSON_INCL)

CPPFLAGS = -c -g $(IFLAGS) -std=c++11 -stdlib=libc++

LDFLAGS =  -L$(CURL_LIB_PATH)
LIBS =  -l$(CURL_LIB)


TARGET: $(OBJS) 
	$(CC) $(OBJS)

clean:
	rm -f  $(TARGET) $(TARGET).class


# DO NOT DELETE

