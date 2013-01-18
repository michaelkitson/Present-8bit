all: tests
Present.o: Present.c
PresentECB.o: PresentECB.c
PresentCBC.o: PresentCBC.c
testPresent.o: testPresent.c 
testECB.o: testECB.c
testECB.o: testCBC.c

tests: Present.o testPresent.o testECB.o testCBC.o
	gcc -o testPresent testPresent.o Present.o
	gcc -o testECB testECB.o PresentECB.o Present.o
#	gcc -o testCBC testCBC.o PresentCBC.o Present.o

clean:
	rm Present.o testPresent.o testECB.o testCBC.o
realclean: clean
	rm testPresent testECB testCBC
