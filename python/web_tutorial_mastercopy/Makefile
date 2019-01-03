SRCS=$(wildcard *.py)


all: testing webversion

../web_tutorial_testing/%.py: %.py
	unifdef -DTESTING=1 -o ../web_tutorial_testing/$< $< ; [ $$? != 2 ]


testing: $(patsubst %,../web_tutorial_testing/%,$(SRCS))

../web_tutorial_fortheweb/%.py: %.py
	unifdef -DTESTING=0 -o ../web_tutorial_fortheweb/$< $< ; [ $$? != 2 ]


webversion: $(patsubst %,../web_tutorial_fortheweb/%,$(SRCS))
