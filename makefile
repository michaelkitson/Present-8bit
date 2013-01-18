all: test

Present.o: Present.c

test.o: test.c

test: test.o Present.o
	gcc -o test test.o Present.o

clean:
	rm Present.o test.o
realclean:
	rm test Present.o test.o
