# Download and unpack googletest at configure time
configure_file( CMakeLists.txt.in googletest-download/CMakeLists.txt )
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . RESULT_VARIABLE result WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if( result )
  message( FATAL_ERROR "CMake step for googletest failed: ${result}" )
endif()
execute_process( COMMAND ${CMAKE_COMMAND} --build . RESULT_VARIABLE result WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message( FATAL_ERROR "Build step for googletest failed: ${result}" )
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )

# Add googletest directly to our build. This defines the gtest and gtest_main targets.
add_subdirectory( ${CMAKE_CURRENT_BINARY_DIR}/googletest-src ${CMAKE_CURRENT_BINARY_DIR}/googletest-build EXCLUDE_FROM_ALL )

message( "COMMON_SOURCES_CPP: ${COMMON_SOURCES_CPP}" )

set( UNITTEST_GTEST_SOURCES
  ${COMMON_SOURCES_CPP}
  ${SOURCES_ROOT}/cmdRegistry.cpp

  ${UNITTEST_GTEST_ROOT}/cmdRegistry_Test.cpp
  ${UNITTEST_GTEST_ROOT}/fileCommon_Test.cpp
)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -fno-inline -O0" )

set( UNITTEST_GTEST_PROJECT_NAME
  "${PROJECT_NAME}_unittests_gtest_cpp"
)
include_directories( 
  ${UNITTEST_GTEST_PROJECT_NAME}
  ${SOURCES_INCLUDE}
  ${gtest_SOURCE_DIR}/include
  ${gmock_SOURCE_DIR}/include
  ${COMMON_PATH}/include
)
add_executable( ${UNITTEST_GTEST_PROJECT_NAME} ${UNITTEST_GTEST_SOURCES} )
target_link_libraries( ${UNITTEST_GTEST_PROJECT_NAME} gtest_main gmock ${PROJ_NAME_COMMON_LIB} )

add_test( ${UNITTEST_GTEST_PROJECT_NAME} 
          ${UNITTEST_GTEST_PROJECT_NAME} 
          --gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_GTEST_PROJECT_NAME}_results.xml
          )
add_test( ${UNITTEST_GTEST_PROJECT_NAME}_coverage
          bash ${SCRIPT_PATH}/genUnitTestResults.sh
          "${UNITTEST_GTEST_PROJECT_NAME}"
          "${PROJECT_SOURCE_DIR}"
          "${CMAKE_CURRENT_BINARY_DIR}"
          )