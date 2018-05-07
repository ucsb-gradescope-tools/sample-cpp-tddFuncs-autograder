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

## `MAKE-REFERENCE.sh`

A bash script that creates the expected test output using the reference solution. **Leave this unchanged when creating your own autograder.**

## `apt-get.sh`
A bash script for installing any necessary dependencies for the assignment, e.g. g++.

## `diffs.sh`

A bash script describing the tests to be run. See [this page](https://github.com/ucsb-gradescope-tools/gs-diff-based-testing/blob/master/README.md) for further documentation.

## `grade.sh`

A bash script for generating the results of the student submission. At the top of this file, you must specify what student files should be copied from `/autograder/submission` for testing by listing them in the definition of the environment
variable EXPECTED_FILES.

For example, the `grade.sh` script in this file starts with:

```
EXPECTED_FILES="add.h add.cpp addCmdLine.cpp sumStdin.cpp"
```

You also may need to set the make targets for the `Makefile` and `Makefile.tdd` in the `BUILD_FILES` directory
if they are something other than `all` and `tests`:


```
# Set the make target for the compilation phase
MAKE_TARGET_BUILD="all"

# Set the make target for the execution/testing phase (tddFuncs tests)
# This should be a target in the Makefile.tdd makefile
MAKE_TARGET_TESTS="tests"
```
# Instructions

## Step 1: Clone this template

* Create a new empty private repo, e.g. with the name PRIVATE-cs8-s18-labxx-gs
* Clone the empty repo with `git clone <url>`
*  `cd` into that directory:
   > `cd PRIVATE-cs16-s18-labxx-gs`
* Add a remote for this sample repo via: 
   > `git remote add template git@github.com:ucsb-gradescope-tools/sample-cpp-tddFuncs-autograder.git`
* Pull from this sample repo via `git pull template master`
* Push to origin with `git push origin master`

## Step 2: Edit the template for your assignment

* In `grade.sh` edit the environment variable `EXPECTED_FILES` to list the files you expect the student to submit.  Only these
   will be copied from the student submission into the space where the assignment is graded.
   
   If you prefer *all* files to be copied in, edit the `grade.sh` script to copy all files from `/autograder/submission` into
   the target directory.

* Change the reference solution `REFERENCE-SOLUTION`, including the Makefile to be a reference solution for your assignment. In this directory, you should have a `Makefile` that matches the one you'd expect the students to be testing with, and versions of `tddFuncs.h` and `tddFuncs.cpp` that match what you'd expect the students to use.

* Look at the three Makefiles in `BUILD-FILES`, i.e. `Makefile`, `Makefile.check` and `Makefile.tdd` and create appropriate versions for your assignment.

* Make sure that instructor versions of files containing the instructor tests are in `BUILD-FILES`.    

* If you are also using diff based grading, edit the files `diffs.sh` to contain your tests.  This is where you can include
   a syntax check based on `Makefile.check`.    If you are using ONLY unit tests, this file can be an empty file.
   
* Make sure that the `Makefile` target specified in `grade.sh` match the ones in `Makefile` and `Makefile.tdd`, respectively, from the `BUILD-FILES` directory.


## Step 3: Test your autograder locally (optional)

To test your autograder locally, try putting a correct sample solution in the SAMPLE-SOLUTION-1 directory and an incorrect sample solution in the SAMPLE-SOLUTION-2 directory.  (You have the option of creating additional SAMPLE-SOLUTION-nn directories, as few or as many as you see fit if you want to test a wider range of solution possibilities.)

To check what will happen, run:
* `MAKE-REFERENCE.sh`
* `./grade.sh SAMPLE-SOLUTION-1`
* `./grade.sh SAMPLE-SOLUTION-2` 
* etc.

(When converting assignments from UCSB's submit.cs, you might adapt a "perfect" solution and a "flawed" solution from among previous student submissions, by looking at the grade assigned by submit.cs)

In each case, look at the file `results.json` to see whether it reflects what you expect the resulting grade to be.   

## Step 4: Create an `Autograder.zip` using the [link-gs-zip-with-repo](https://github.com/ucsb-gradescope-tools/link-gs-zip-with-repo) tool.
   
* Clone the [link-gs-zip-with-repo](https://github.com/ucsb-gradescope-tools/link-gs-zip-with-repo).
* In that repo, edit `env.sh` to point to your repo.  You don't need to commit that change.
* Run the script `./make_deploy_keys.sh` and upload your deploy key to the new repo you created for your assignment.
* Run the script `./make_autograder_zip.sh` and then upload the `Autograder.zip` to Gradescope.

You are now ready to test your autograded assignment.
   
