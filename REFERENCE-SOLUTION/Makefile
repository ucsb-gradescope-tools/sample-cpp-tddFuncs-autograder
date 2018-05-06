CXX = g++ 
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized -std=c++11 $(EXTRA_CXXFLAGS)

BINARIES=addCmdLine biggerTest sumStdin sumTest

all: ${BINARIES}

tests: ${BINARIES}
	./sumTest
	./biggerTest

sumTest: add.o sumTest.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

biggerTest: add.o biggerTest.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

addCmdLine: add.o addCmdLine.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

sumStdin: add.o sumStdin.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

clean:
	/bin/rm -f ${BINARIES} *.o
