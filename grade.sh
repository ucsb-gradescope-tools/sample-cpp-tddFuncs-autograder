#!/usr/bin/env bash

EXPECTED_FILES="add.h add.cpp addCmdLine.cpp sumStdin.cpp"

# Set the make target for the compilation phase

MAKE_TARGET_BUILD="all"

# Set the make target for the execution/testing phase (tddFuncs tests)
# This should be a target in the Makefile.tdd makefile

MAKE_TARGET_TESTS="tests"

DIFF_TOOLS=gs-diff-based-testing

###### YOU TYPICALLY SHOULD NOT NEED TO EDIT BELOW THIS POINT ######

echo $EXPECTED_FILES

if [ -d $DIFF_TOOLS ]; then
  cd $DIFF_TOOLS
  git pull origin master
  cd ..
else
  git clone https://github.com/ucsb-gradescope-tools/${DIFF_TOOLS}.git
fi


if [ "$#" -eq 1 ]; then
    SUBMISSION_SOURCE=`pwd`/$1
else
    SUBMISSION_SOURCE=/autograder/submission
fi

if [ -d $SUBMISSION_SOURCE ]; then  
   echo "Checking submission from $SUBMISSION_SOURCE"
else
   echo "ERROR: $SUBMISSION_SOURCE does not exist"
   exit
fi

copy_files_from_dir_if_it_exists () {
    if [ -d $1 ]; then
        cp -v $1/* .
    fi
}

/bin/rm -rf MAKE-STUDENT-OUTPUT
mkdir -p MAKE-STUDENT-OUTPUT

cd MAKE-STUDENT-OUTPUT

copy_files_from_dir_if_it_exists ../BUILD-FILES

for f in $EXPECTED_FILES; do
    if [ -f $SUBMISSION_SOURCE/$f ]; then
        cp -v $SUBMISSION_SOURCE/$f .
    else
        echo "WARNING: Expected file $f not found in $SUBMISSION_SOURCE"
    fi
done

rm -f results.json

make clean

if [ -z "$MAKE_TARGET_BUILD" ]; then
    echo "****** WARNING: MAKE_TARGET_BUILD is not set ******"
else
   make $MAKE_TARGET_BUILD
fi

copy_files_from_dir_if_it_exists ../EXECUTION-FILES
for f in $EXPECTED_FILES; do
    if [ -f $SUBMISSION_SOURCE/$f ]; then
        cp -v $SUBMISSION_SOURCE/$f .
    else
        echo "WARNING: Expected file $f not found in $SUBMISSION_SOURCE"
    fi
done

../${DIFF_TOOLS}/grade-diffs.py ../diffs.sh 

make clean
if [ -z "$MAKE_TARGET_TESTS" ]; then
    echo "****** WARNING: MAKE_TARGET_TESTS is not set ******"
else
   make -f Makefile.tdd $MAKE_TARGET_TESTS
fi

if [ -d /autograder/results ]; then
    cp -v results.json /autograder/results/results.json
fi

cd ..

