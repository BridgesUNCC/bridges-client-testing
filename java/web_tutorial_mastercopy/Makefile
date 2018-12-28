include ../../env_vars.mk

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

SRCS = $(sort $(shell grep -l public\ static\ void\ main *.java ) )

OBJS = $(SRCS:.java=.class)


all:

style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) 
