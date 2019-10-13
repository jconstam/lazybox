cmake_minimum_required( VERSION 3.5 )

set( PROJECT_NAME "lazybox" )

enable_testing( )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

get_filename_component( ROOT_PATH "${PROJECT_SOURCE_DIR}/.." REALPATH )
get_filename_component( SCRIPT_PATH "${PROJECT_SOURCE_DIR}/../script" REALPATH )
get_filename_component( SOURCES_ROOT "${PROJECT_SOURCE_DIR}/../src" REALPATH )
get_filename_component( SOURCES_INCLUDE "${SOURCES_ROOT}/include" REALPATH )
get_filename_component( UNITTEST_GTEST_ROOT "${PROJECT_SOURCE_DIR}/unittests/gtest_cpp" REALPATH )
get_filename_component( UNITTEST_UNITY_ROOT "${PROJECT_SOURCE_DIR}/unittests/unity_c" REALPATH )
get_filename_component( COMMAND_TEST_ROOT "${PROJECT_SOURCE_DIR}/commandTests" REALPATH )
get_filename_component( STATIC_ANALYSIS_ROOT "${PROJECT_SOURCE_DIR}/staticanalysis" REALPATH )
get_filename_component( STATIC_ANALYSIS_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/staticanalysis" REALPATH )

add_subdirectory( ${COMMON_PATH} ${BUILD_PATH}/common )
add_subdirectory( ${STATIC_ANALYSIS_ROOT} )
add_subdirectory( ${UNITTEST_GTEST_ROOT} )
add_subdirectory( ${UNITTEST_UNITY_ROOT} )
add_subdirectory( ${COMMAND_TEST_ROOT} )
