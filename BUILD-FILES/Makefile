BINARIES=helloWorld helloStderr helloFile readFile readStdin countToN

all:	${BINARIES}

helloWorld: helloWorld.cpp
	g++ -std=c++11 helloWorld.cpp -o helloWorld

helloStderr: helloStderr.cpp
	g++ -std=c++11 helloStderr.cpp -o helloStderr

helloFile: helloFile.cpp
	g++ -std=c++11 helloFile.cpp -o helloFile

readFile: readFile.cpp
	g++ -std=c++11 readFile.cpp -o readFile

readStdin: readStdin.cpp
	g++ -std=c++11 readStdin.cpp -o readStdin

countToN: countToN.cpp
	g++ -std=c++11 countToN.cpp -o countToN

clean:
	/bin/rm -rf *.o ${BINARIES}