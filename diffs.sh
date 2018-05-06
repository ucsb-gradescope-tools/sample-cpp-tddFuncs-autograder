#!/usr/bin/env bash

# This test verifies that the code compiles cleanly with -Wall.
# The default timeout for tests is 2 seconds; we increase it here
# because compilation can take a while.
#@test{"stderr":1, "timeout": 10}
make -B -f check_make_errors

#@test{"stdout":10}
./helloWorld

#@test{"stderr":10}
./helloStderr

#@test{"filename":"hello.txt", "points":10}
./helloFile

#@test{"stdout": 10}
./readStdin < readStdinTest1.txt

#@test{"stdout": 10}
./readStdin < readStdinTest2.txt

#@test{"stdout": 10}
./readStdin < readStdinTest3.txt

#@test{"stdout": 10}
./readFile

#@test{"stdout": 10}
./countToN 10

#@test{"stdout": 10}
./countToN -1

#@test{"stderr": 10}
./countToN abcd