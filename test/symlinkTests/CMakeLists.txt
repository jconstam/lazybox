if( NOT ${INSTALL_PATH} MATCHES "/$" )
    set( INSTALL_PATH "${INSTALL_PATH}/" )    
endif( )

add_test( echo_dummy ${INSTALL_PATH}echo )
set_tests_properties( echo_dummy PROPERTIES PASS_REGULAR_EXPRESSION "COUNT: 1;echo" )