# Download and unpack unity at configure time
configure_file( CMakeLists.txt.in unity-download/CMakeLists.txt )
execute_process( COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . RESULT_VARIABLE result WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/unity-download )
if( result )
  message( FATAL_ERROR "CMake step for unity failed: ${result}" )
endif()
execute_process( COMMAND ${CMAKE_COMMAND} --build . RESULT_VARIABLE result WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/unity-download )
if(result)
  message( FATAL_ERROR "Build step for unity failed: ${result}" )
endif()

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -fno-inline -O0" )

set( UNITTEST_UNITY_SOURCES
	${CMAKE_CURRENT_BINARY_DIR}/unity-src/src/unity.c

	${UNITTEST_UNITY_ROOT}/main.c
)
set( UNITTEST_UNITY_INCLUDES 
	${CMAKE_CURRENT_BINARY_DIR}/unity-src/src
	${SOURCES_INCLUDE}
)
set( UNITTEST_UNITY_PROJECT_NAME 
	"${PROJECT_NAME}_unittests_unity_c"
)

include_directories( ${UNITTEST_UNITY_PROJECT_NAME}_parseArgs
	${UNITTEST_UNITY_INCLUDES}
)
add_executable( ${UNITTEST_UNITY_PROJECT_NAME}_parseArgs 
	${UNITTEST_UNITY_SOURCES}

	${SOURCES_ROOT}/parseArgs.c
	${UNITTEST_UNITY_ROOT}/parseArgs_tests.c
)

add_test( ${UNITTEST_UNITY_PROJECT_NAME}_parseArgs
          ${UNITTEST_UNITY_PROJECT_NAME}_parseArgs
          )