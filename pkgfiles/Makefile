DINGS= MX6SL\
	MX6SDL\
	MX6DQ\
	MX6CORE\
	muxer_config

.PHONY: all clean

FILES=$(patsubst %,%.tar.bz2,$(DINGS))

all: $(FILES)

%.tar.bz2: %/
	tar -cf $@ $<

clean::
	rm $(FILES)
