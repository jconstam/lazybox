# This file was automatically generated.  Do not modify.

add_test( lazybox ${OUTPUT_PATH}/lazybox )
set_tests_properties( lazybox PROPERTIES PASS_REGULAR_EXPRESSION "LazyBox - BusyBox's less portable, less functional cousin." )

add_test( NAME cat_multiFile1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox cat catTest1 catTest2 CMD_OUTPUT_SPLITTER First\nSecond\nThirdFourth\nFifth\n )
add_test( NAME cat_multiFile1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/cat catTest1 catTest2 CMD_OUTPUT_SPLITTER First\nSecond\nThirdFourth\nFifth\n )

add_test( NAME cat_multiFileLineNums WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox cat -n catTest1 catTest2 CMD_OUTPUT_SPLITTER "     1  First\n     2  Second\n     3  Third     1  Fourth\n     2  Fifth\n" )
add_test( NAME cat_multiFileLineNums_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/cat -n catTest1 catTest2 CMD_OUTPUT_SPLITTER "     1  First\n     2  Second\n     3  Third     1  Fourth\n     2  Fifth\n" )

add_test( NAME cat_singleFile1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox cat catTest1 CMD_OUTPUT_SPLITTER First\nSecond\nThird )
add_test( NAME cat_singleFile1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/cat catTest1 CMD_OUTPUT_SPLITTER First\nSecond\nThird )

add_test( NAME cat_singleFile2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox cat catTest2 CMD_OUTPUT_SPLITTER Fourth\nFifth\n )
add_test( NAME cat_singleFile2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/cat catTest2 CMD_OUTPUT_SPLITTER Fourth\nFifth\n )

add_test( NAME cat_singleFileLineNums WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox cat -n catTest1 CMD_OUTPUT_SPLITTER "     1  First\n     2  Second\n     3  Third" )
add_test( NAME cat_singleFileLineNums_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/cat -n catTest1 CMD_OUTPUT_SPLITTER "     1  First\n     2  Second\n     3  Third" )

add_test( NAME echo_escape_newline1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e testing\n CMD_OUTPUT_SPLITTER testing\n\n )
add_test( NAME echo_escape_newline1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e testing\n CMD_OUTPUT_SPLITTER testing\n\n )

add_test( NAME echo_escape_newline2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e -n testing\n CMD_OUTPUT_SPLITTER testing\n )
add_test( NAME echo_escape_newline2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e -n testing\n CMD_OUTPUT_SPLITTER testing\n )

add_test( NAME echo_escape_newline3 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e testing\n\n\ntesting\ntesting CMD_OUTPUT_SPLITTER testing\n\n\ntesting\ntesting\n )
add_test( NAME echo_escape_newline3_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e testing\n\n\ntesting\ntesting CMD_OUTPUT_SPLITTER testing\n\n\ntesting\ntesting\n )

add_test( NAME echo_escape_newline4 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo testing\\n CMD_OUTPUT_SPLITTER testing\\n\n )
add_test( NAME echo_escape_newline4_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo testing\\n CMD_OUTPUT_SPLITTER testing\\n\n )

add_test( NAME echo_escape_tab1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e testing\ttesting CMD_OUTPUT_SPLITTER testing\ttesting\n )
add_test( NAME echo_escape_tab1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e testing\ttesting CMD_OUTPUT_SPLITTER testing\ttesting\n )

add_test( NAME echo_escape_tab2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -e testing\t\t\ttesting CMD_OUTPUT_SPLITTER testing\t\t\ttesting\n )
add_test( NAME echo_escape_tab2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -e testing\t\t\ttesting CMD_OUTPUT_SPLITTER testing\t\t\ttesting\n )

add_test( NAME echo_many WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo "this is a lot of parameters and some are numbers 1 2 3" CMD_OUTPUT_SPLITTER "this is a lot of parameters and some are numbers 1 2 3\n" )
add_test( NAME echo_many_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo "this is a lot of parameters and some are numbers 1 2 3" CMD_OUTPUT_SPLITTER "this is a lot of parameters and some are numbers 1 2 3\n" )

add_test( NAME echo_nonewline_many WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -n this is a lot of parameters and some are numbers 1 2 3 CMD_OUTPUT_SPLITTER this is a lot of parameters and some are numbers 1 2 3 )
add_test( NAME echo_nonewline_many_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -n this is a lot of parameters and some are numbers 1 2 3 CMD_OUTPUT_SPLITTER this is a lot of parameters and some are numbers 1 2 3 )

add_test( NAME echo_nonewline_one WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo -n testing CMD_OUTPUT_SPLITTER testing )
add_test( NAME echo_nonewline_one_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo -n testing CMD_OUTPUT_SPLITTER testing )

add_test( NAME echo_nothing WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo  CMD_OUTPUT_SPLITTER \n )
add_test( NAME echo_nothing_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo  CMD_OUTPUT_SPLITTER \n )

add_test( NAME echo_one WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox echo "testing" CMD_OUTPUT_SPLITTER "testing\n" )
add_test( NAME echo_one_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/echo "testing" CMD_OUTPUT_SPLITTER "testing\n" )

