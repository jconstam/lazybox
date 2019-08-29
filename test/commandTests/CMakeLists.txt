# This file was automatically generated.  Do not modify.

add_test( lazybox ${OUTPUT_PATH}/lazybox )
set_tests_properties( lazybox PROPERTIES PASS_REGULAR_EXPRESSION "LazyBox - BusyBox's less portable, less functional cousin." )

add_test( echo_escape_newline1 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e testing\n CMD_OUTPUT_SPLITTER testing\n\n )
add_test( echo_escape_newline1_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e testing\n CMD_OUTPUT_SPLITTER testing\n\n )

add_test( echo_escape_newline2 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e -n testing\n CMD_OUTPUT_SPLITTER testing\n )
add_test( echo_escape_newline2_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e -n testing\n CMD_OUTPUT_SPLITTER testing\n )

add_test( echo_escape_newline3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e testing\n\n\ntesting\ntesting CMD_OUTPUT_SPLITTER testing\n\n\ntesting\ntesting\n )
add_test( echo_escape_newline3_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e testing\n\n\ntesting\ntesting CMD_OUTPUT_SPLITTER testing\n\n\ntesting\ntesting\n )

add_test( echo_escape_newline4 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo testing\\n CMD_OUTPUT_SPLITTER testing\\n\n )
add_test( echo_escape_newline4_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo testing\\n CMD_OUTPUT_SPLITTER testing\\n\n )

add_test( echo_escape_tab1 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e testing\ttesting CMD_OUTPUT_SPLITTER testing\ttesting\n )
add_test( echo_escape_tab1_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e testing\ttesting CMD_OUTPUT_SPLITTER testing\ttesting\n )

add_test( echo_escape_tab2 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e testing\t\t\ttesting CMD_OUTPUT_SPLITTER testing\t\t\ttesting\n )
add_test( echo_escape_tab2_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e testing\t\t\ttesting CMD_OUTPUT_SPLITTER testing\t\t\ttesting\n )

add_test( echo_many ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo "this is a lot of parameters and some are numbers 1 2 3" CMD_OUTPUT_SPLITTER "this is a lot of parameters and some are numbers 1 2 3\n" )
add_test( echo_many_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo "this is a lot of parameters and some are numbers 1 2 3" CMD_OUTPUT_SPLITTER "this is a lot of parameters and some are numbers 1 2 3\n" )

add_test( echo_nonewline_many ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -n this is a lot of parameters and some are numbers 1 2 3 CMD_OUTPUT_SPLITTER this is a lot of parameters and some are numbers 1 2 3 )
add_test( echo_nonewline_many_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -n this is a lot of parameters and some are numbers 1 2 3 CMD_OUTPUT_SPLITTER this is a lot of parameters and some are numbers 1 2 3 )

add_test( echo_nonewline_one ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -n testing CMD_OUTPUT_SPLITTER testing )
add_test( echo_nonewline_one_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -n testing CMD_OUTPUT_SPLITTER testing )

add_test( echo_nothing ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo  CMD_OUTPUT_SPLITTER \n )
add_test( echo_nothing_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo  CMD_OUTPUT_SPLITTER \n )

add_test( echo_one ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo "testing" CMD_OUTPUT_SPLITTER "testing\n" )
add_test( echo_one_symlink ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo "testing" CMD_OUTPUT_SPLITTER "testing\n" )

