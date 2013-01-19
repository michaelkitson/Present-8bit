OBJFILES = Present.o PresentCBC.o PresentECB.o testPresent.o testECB.o testCBC.o
EXECUTABLES = testPresent testECB testCBC

all: tests
Present.o: Present.c
PresentCBC.o: PresentCBC.c
PresentECB.o: PresentECB.c
testPresent.o: testPresent.c 
testCBC.o: testCBC.c
testECB.o: testECB.c

testPresent: testPresent.o Present.o
testCBC: testCBC.o PresentCBC.o Present.o
testECB: testECB.o PresentECB.o Present.o

tests: $(EXECUTABLES)

clean:
	rm $(OBJFILES)
realclean: clean
	rm $(EXECUTABLES)
