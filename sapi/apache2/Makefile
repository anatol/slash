include ../../local.mk

.PHONY: clean install uninstall

APR=apr-1
APXS=apxs

SO_EXT=$(shell $(APR)-config --apr-so-ext)

mod_slash.so: mod_slash.c ../../libslash.a
	$(CC) -o $@ $(CFLAGS) \
	  -I$(shell apxs -q INCLUDEDIR) \
	  $(shell apr-1-config --includes) \
	  $(shell apr-1-config --link-ld) \
	  $(shell apr-1-config --libs) \
	  -dynamic \
	  -undefined suppress \
	  -flat_namespace \
	  $< $(LDFLAGS)

clean:
	rm -f *.o *.so *.$(SO_EXT)
	rm -rf *.dSYM .libs

install: mod_slash.so
	$(APXS) -i -a mod_slash.so

uninstall:
