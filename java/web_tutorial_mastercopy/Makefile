include ../../env_vars.mk

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

SRCS = $(sort $(wildcard *.java ) )

OBJS = $(SRCS:.java=.class)

all: testing webversion

../web_tutorial_testing/:
	mkdir ../web_tutorial_testing/

../web_tutorial_testing/%.java: %.java ../web_tutorial_testing/
	unifdef -DTESTING=1 -o ../web_tutorial_testing/$< $< ; [ $$? != 2 ]

testing: $(patsubst %,../web_tutorial_testing/%,$(SRCS))

../web_tutorial_fortheweb/:
	mkdir ../web_tutorial_fortheweb/

../web_tutorial_fortheweb/%.java: %.java ../web_tutorial_fortheweb/
	unifdef -DTESTING=0 -o ../web_tutorial_fortheweb/$< $< ; [ $$? != 2 ]


webversion: $(patsubst %,../web_tutorial_fortheweb/%,$(SRCS))


style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) 
