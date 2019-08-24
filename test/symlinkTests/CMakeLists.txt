# This file was automatically generated.  Do not modify.

add_test( lazybox ${OUTPUT_PATH}/lazybox )
set_tests_properties( lazybox PROPERTIES PASS_REGULAR_EXPRESSION "LazyBox - BusyBox's less portable, less functional cousin." )

add_test( echo_many python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo this is a lot of parameters and some are numbers 1 2 3 CMD_OUTPUT_SPLITTER this is a lot of parameters and some are numbers 1 2 3\n )
add_test( echo_many_symlink python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo this is a lot of parameters and some are numbers 1 2 3 CMD_OUTPUT_SPLITTER this is a lot of parameters and some are numbers 1 2 3\n )

add_test( echo_many_nonewline python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -n this is a lot of parameters and some are numbers 1 2 3 CMD_OUTPUT_SPLITTER this is a lot of parameters and some are numbers 1 2 3 )
add_test( echo_many_nonewline_symlink python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -n this is a lot of parameters and some are numbers 1 2 3 CMD_OUTPUT_SPLITTER this is a lot of parameters and some are numbers 1 2 3 )

add_test( echo_nothing python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo  CMD_OUTPUT_SPLITTER \n )
add_test( echo_nothing_symlink python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo  CMD_OUTPUT_SPLITTER \n )

add_test( echo_one python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo testing CMD_OUTPUT_SPLITTER testing\n )
add_test( echo_one_symlink python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo testing CMD_OUTPUT_SPLITTER testing\n )

add_test( echo_one_nonewline python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -n testing CMD_OUTPUT_SPLITTER testing )
add_test( echo_one_nonewline_symlink python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -n testing CMD_OUTPUT_SPLITTER testing )

