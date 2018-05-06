#!/usr/bin/env bash

echo "This script will make the reference output"
echo "Downloading the Gradescope gs-diff-based-testing tools"

copy_files_from_dir_if_it_exists () {

    if [ -d $1 ]; then
	cp -v $1/* .
    fi

}


git clone https://github.com/ucsb-gradescope-tools/gs-diff-based-testing.git
cd gs-diff-based-testing
git pull origin master
cd ..
pip3 install --user jsonschema

DIFF_TOOLS=../gs-diff-based-testing

/bin/rm -rf MAKE-REFERENCE-OUTPUT 
mkdir -p MAKE-REFERENCE-OUTPUT

cd MAKE-REFERENCE-OUTPUT

copy_files_from_dir_if_it_exists ../EXECUTION-FILES
copy_files_from_dir_if_it_exists ../BUILD-FILES
copy_files_from_dir_if_it_exists ../REFERENCE-SOLUTION

make clean
make 

${DIFF_TOOLS}/grade-diffs.py -r ../diffs.sh 


