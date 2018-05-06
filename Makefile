
TEMP_DIRS=diffs.sh-reference diffs.sh-student gs-diff-based-testing MAKE-REFERENCE-OUTPUT MAKE-STUDENT-OUTPUT

clean:
	/bin/rm -rf ${TEMP_DIRS}

