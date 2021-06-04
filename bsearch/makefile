all: bsearch

bsearch: bsearch.o primlib.o
	gcc -g $^ -o $@ -lm -lSDL -lpthread -lSDL_gfx

.c.o: 
	gcc -g -Wall -pedantic -std=c99 -c -D_REENTRANT $<

primlib.o: primlib.c primlib.h

bsearch.o: bsearch.c primlib.h

clean:
	-rm primlib.o bsearch.o bsearch
