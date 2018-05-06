#!/usr/bin/env bash

# This test verifies that the code compiles cleanly with -Wall.
# The default timeout for tests is 2 seconds; we increase it here
# because compilation can take a while.

#@test{"stderr":1, "stdout":1, "timeout": 10}
make -B -f Makefile.check

#@test{"stdout": 5, "stderr": 5}
./sumStdin < sumStdinTest1.txt

#@test{"stdout": 5, "stderr": 5}
./sumStdin < sumStdinTest2.txt

#@test{"stdout": 5, "stderr": 5}
./addCmdLine 7 3

#@test{"stdout": 5, "stderr": 5}
./addCmdLine

#@test{"stdout": 5, "stderr": 5}
./addCmdLine foo bar

