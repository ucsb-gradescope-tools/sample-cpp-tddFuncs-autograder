BINARIES=helloWorld helloStderr helloFile readFile readStdin countToN

all:	${BINARIES}

helloWorld: helloWorld.cpp
	clang++ -Wall -fsyntax-only -std=c++11 helloWorld.cpp

helloStderr: helloStderr.cpp
	clang++ -Wall -fsyntax-only -std=c++11 helloStderr.cpp

helloFile: helloStderr.cpp
	clang++ -Wall -fsyntax-only -std=c++11 helloFile.cpp

readFile: readFile.cpp
	clang++ -Wall -fsyntax-only -std=c++11 readFile.cpp

readStdin: readStdin.cpp
	clang++ -Wall -fsyntax-only -std=c++11 readStdin.cpp

countToN: countToN.cpp
	clang++ -Wall -fsyntax-only -std=c++11 countToN.cpp