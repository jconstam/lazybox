cmake_minimum_required( VERSION 3.5 )

set( PROJECT_NAME "lazybox" )

enable_testing( )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

set( SOURCES_ROOT ${PROJECT_SOURCE_DIR}/../src )
set( UNITTEST_ROOT ${PROJECT_SOURCE_DIR}/unittests )
set( SYMLINK_TEST_ROOT ${PROJECT_SOURCE_DIR}/symlinkTests )

add_subdirectory( ${UNITTEST_ROOT} )
add_subdirectory( ${SYMLINK_TEST_ROOT} )
