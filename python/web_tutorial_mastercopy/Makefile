SRCS=$(wildcard *.py)


all: testing webversion

../web_tutorial_testing/%.py: %.py
	unifdef -x2 -DTESTING=1 $< -o ../web_tutorial_testing/$< 

testing: $(patsubst %,../web_tutorial_testing/%,$(SRCS))

../web_tutorial_fortheweb/%.py: %.py
	unifdef -x2 -DTESTING=0 $< -o ../web_tutorial_fortheweb/$< 


webversion: $(patsubst %,../web_tutorial_fortheweb/%,$(SRCS))
