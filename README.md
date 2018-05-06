# sample-cpp-tddFuncs-autograder

This sample autograder builds on top of [sample-cpp-diff-autograder](https://github.com/ucsb-gradescope-tools/sample-cpp-diff-autograder) by adding an extra layer of functionalilty: the ability to directly record the results of tests from the tddFuncs.h/tddFuncs.cpp unit testing framework into the Gradescope JSON.

The autograder can still incorporate diff-based tests before or after the unit tests are executed.  The key point is that each stage in the grading pipeline adds on to the results.json of the previous stage.

The corresponding assignment can be found at github.com/ucsb-gradescope-tools/sample-cpp-tddFuncs.assignment.

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

Any extra files (e.g. a Makefile) that should be in the same directory as the student submission while the submission is being built.    In this repo, the BUILD-FILES directory has three Makefiles:

1.  `Makefile`, the Makefile from the
   [assignment repo](https://github.com/ucsb-gradescope-tools/sample-cpp-tddFuncs-assignment).
2.  `Makefile.check` A separate Makefile for checking syntax that is referenced in `diffs.sh`; this allows the instructor
   to assign a certain number of points for a "clean compile" with no warnings or errors.
3. `Makefile.tdd` This is a makefile that builds versions of the executable that link with the version of `tddFuncs.cpp`
   that generates the JSON for Gradescope.

When converting an assignment from submit.cs, any files that were "build files" on submit.cs go into this directory, along with the Makefile for the assignment.

## EXECUTION-FILES

Any extra files (e.g. data files) that should be in the same directory as the student submission while the submission is being executed. In this repo, the EXECUTION-FILES directory has `input.txt` file from the provided-files directory in the [assignment repo](https://github.com/ucsb-gradescope-tools/sample-cpp-tddFuncs-assignment).


## REFERENCE-SOLUTION

A reference solution which will be used to generate the expected outcome for all tests. Like student solutions, this solution will be run with all files from EXECUTION-FILES in the same directory.

## MAKE-REFERENCE<i></i>.sh

A bash script that creates the expected test output using the reference solution. **Leave this unchanged when creating your own autograder.**

## `apt-get.sh`
A bash script for installing any necessary dependencies for the assignment, e.g. g++.

## `diffs.sh`

A bash script describing the tests to be run. See [this page](https://github.com/ucsb-gradescope-tools/gs-diff-based-testing/blob/master/README.md) for further documentation.

## `grade.sh`

A bash script for generating the results of the student submission. At the top of this file, you must specify what student files should be copied from `/autograder/submission` for testing by listing them in the definition of the environment
variable EXPECTED_FILES.

For example, the `grade.sh` script in this file starts with:

EXPECTED_FILES="countToN.cpp helloFile.cpp helloWorld.cpp helloStderr.cpp \
                readFile.cpp readStdin.cpp "
