CXX = g++ 
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized -std=c++11 -I/usr/include/jsoncpp

LDFLAGS = -ljsoncpp

BINARIES=arrayToStringTest arrayBoundsDemo countEvensTest \
	minOfArrayTest minOfArrayErrorTest countPrimesTest \
	maxOfArrayTest maxOfArrayErrorTest sumOddsTest \
	sumOfArrayTest utilityTest


all: ${BINARIES}

tests: ${BINARIES}
	./arrayToStringTest
	./countEvensTest
	./countPrimesTest
	./maxOfArrayTest
	./minOfArrayTest
	./sumOddsTest
	./sumOfArrayTest
	./utilityTest

errorTests: minOfArrayErrorTest maxOfArrayErrorTest
	- ./minOfArrayErrorTest
	- ./maxOfArrayErrorTest


arrayToStringTest: arrayToStringTest.o arrayToString.o tddFuncs.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

minOfArrayTest: minOfArrayTest.o arrayToString.o tddFuncs.o minOfArray.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

minOfArrayErrorTest: minOfArrayErrorTest.o arrayToString.o tddFuncs.o minOfArray.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

maxOfArrayTest: maxOfArrayTest.o arrayToString.o tddFuncs.o maxOfArray.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

maxOfArrayErrorTest: maxOfArrayErrorTest.o arrayToString.o tddFuncs.o maxOfArray.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

arrayBoundsDemo: arrayBoundsDemo.o arrayToString.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

countEvensTest: countEvensTest.o countEvens.o tddFuncs.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

sumOfArrayTest: sumOfArrayTest.o sumOfArray.o tddFuncs.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)


sumOddsTest: sumOddsTest.o sumOdds.o tddFuncs.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

countPrimesTest: countPrimesTest.o countPrimes.o tddFuncs.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

utilityTest: utilityTest.o tddFuncs.o utility.o
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDFLAGS)

clean:
	/bin/rm -f ${BINARIES} *.o
