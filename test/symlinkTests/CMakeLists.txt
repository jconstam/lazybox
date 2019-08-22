# This file was automatically generated on Fri Aug 23 00:28:35 2019

add_test( lazybox ${OUTPUT_PATH}/lazybox )
set_tests_properties( lazybox PROPERTIES PASS_REGULAR_EXPRESSION "LazyBox - BusyBox's less portable, less functional cousin." )

add_test( date_dummy ${OUTPUT_PATH}/lazybox date )
set_tests_properties( date_dummy PROPERTIES PASS_REGULAR_EXPRESSION "2019" )
add_test( date_dummy_symlink ${OUTPUT_PATH}/date )
set_tests_properties( date_dummy_symlink PROPERTIES PASS_REGULAR_EXPRESSION "2019" )

add_test( echo_many ${OUTPUT_PATH}/lazybox echo this is a lot of parameters and some are numbers 1 2 3 )
set_tests_properties( echo_many PROPERTIES PASS_REGULAR_EXPRESSION "this is a lot of parameters and some are numbers 1 2 3" )
add_test( echo_many_symlink ${OUTPUT_PATH}/echo this is a lot of parameters and some are numbers 1 2 3 )
set_tests_properties( echo_many_symlink PROPERTIES PASS_REGULAR_EXPRESSION "this is a lot of parameters and some are numbers 1 2 3" )

add_test( echo_nothing ${OUTPUT_PATH}/lazybox echo )
set_tests_properties( echo_nothing PROPERTIES PASS_REGULAR_EXPRESSION "" )
add_test( echo_nothing_symlink ${OUTPUT_PATH}/echo )
set_tests_properties( echo_nothing_symlink PROPERTIES PASS_REGULAR_EXPRESSION "" )

add_test( echo_one ${OUTPUT_PATH}/lazybox echo testing )
set_tests_properties( echo_one PROPERTIES PASS_REGULAR_EXPRESSION "testing" )
add_test( echo_one_symlink ${OUTPUT_PATH}/echo testing )
set_tests_properties( echo_one_symlink PROPERTIES PASS_REGULAR_EXPRESSION "testing" )

