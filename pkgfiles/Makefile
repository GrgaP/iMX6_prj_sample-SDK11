DINGS= MX6SL\
	MX6SDL\
	MX6DQ\
	MX6CORE\
	muxer_config

.PHONY: all clean

all: $(patsubst %,$(CURDIR)/%.tar.bz2,$(DINGS))

$(CURDIR)/%.tar.bz2: $(CURDIR)/%/
	tar -cf $@ $<

clean::
	rm $(patsubst %,$(CURDIR)/%.tar.bz2,$(DINGS))
