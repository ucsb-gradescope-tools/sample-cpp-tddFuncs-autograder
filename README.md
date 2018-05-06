A sample C++ autograder repo to show how diff-based autograding works. The corresponding assignment can be found at https://github.com/ucsb-gradescope-tools/sample-cpp-assignment.

# Platform specific notes

## Windows

Editing bash scripts (e.g. `diffs.sh`) on Windows will convert the line endings to Windows style, causing the script to be unusable by the Docker container. Either edit the files in a Unix/Mac environment or use a tool to de-convert the line endings BEFORE uploading your autograder.zip.**

## Mac OS

On MacOS, `g++` automatically links to `clang++`.  Hence, if you are
doing anything involving `clang` or `clang++`, it might work on MacOS,
then fail to work once you load the script to Gradescope.  Be sure in
that case that your apt-get.sh includes an install of the appropriate
`clang++` toolchain.

# Components

## BUILD-FILES

Any extra files (e.g. a Makefile) that should be in the same directory as the student submission while the submission is being built.    In this repo, the EXECUTION-FILES directory has the Makefile from the [assignment repo](https://github.com/ucsb-gradescope-tools/sample-cpp-assignment).

When converting an assignment from submit.cs, any files that were "build files" on submit.cs go into this directory, along with the Makefile for the assignment.

## EXECUTION-FILES

Any extra files (e.g. data files) that should be in the same directory as the student submission while the submission is being executed. In this repo, the EXECUTION-FILES directory has `input.txt` file from the provided-files directory in the [assignment repo](https://github.com/ucsb-gradescope-tools/sample-cpp-assignment).


## REFERENCE-SOLUTION

A reference solution which will be used to generate the expected outcome for all tests. Like student solutions, this solution will be run with all files from EXECUTION-FILES in the same directory.

## MAKE-REFERENCE<i></i>.sh

A bash script that creates the expected test output using the reference solution. **Leave this unchanged when creating your own autograder.**

## apt-get<i></i>.sh
A bash script for installing any necessary dependencies for the assignment, e.g. g++.

## diffs<i></i>.sh

A bash script describing the tests to be run. See [this page](https://github.com/ucsb-gradescope-tools/gs-diff-based-testing/blob/master/README.md) for further documentation.

## grade<i></i>.sh

A bash script for generating the results of the student submission. At the top of this file, you must specify what student files should be copied from `/autograder/submission` for testing. For example, the `grade.sh` in this repo begins with:

> cp /autograder/submission/helloWorld.cpp .
> cp /autograder/submission/helloStderr.cpp .

etc.
