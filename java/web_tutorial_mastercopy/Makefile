include ../../env_vars.mk

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

SRCS = $(sort $(wildcard *.java ) )

OBJS = $(SRCS:.java=.class)

all: testing webversion

testing:
	for file in *.java; \
	do \
		unifdef -x2 -DTESTING=1 $$file -o ../web_tutorial_testing/$$file ; \
	done

webversion:
	for file in *.java; \
	do \
		unifdef -x2 -DTESTING=0 $$file -o ../web_tutorial_fortheweb/$$file ; \
	done


style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) 
