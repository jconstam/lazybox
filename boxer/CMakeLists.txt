cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${BOXER_PROJECT_NAME} )

add_subdirectory( ${COMMON_PATH} ${BUILD_PATH}/common )

set( BOXER_SOURCES
    ${COMMON_SOURCES_C}
    ${COMMON_SOURCES_CPP}
    ${PROJECT_SOURCE_DIR}/CmdFileScanner.cpp
    ${PROJECT_SOURCE_DIR}/LazyBoxCommands.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
)

include_directories( 
    ${BOXER_PROJECT_NAME}
    ${COMMON_PATH}/include
    ${PROJECT_SOURCE_DIR}/include
)

add_executable( ${BOXER_PROJECT_NAME} ${BOXER_SOURCES} )
target_link_libraries( ${BOXER_PROJECT_NAME} stdc++fs )

set( COMMAND_SOURCE_DIR ${SOURCE_PATH}/commands )
set( SCRIPT_DIR ${PROJECT_SOURCE_DIR}/../script )
set( CONFIG_DIR ${PROJECT_SOURCE_DIR}/../config )

get_filename_component( COMMAND_INCLUDE_PATH "${SOURCE_PATH}/include/commands.hpp" REALPATH )
get_filename_component( COMMAND_LIST_PATH "${SOURCE_PATH}/cmdList.cpp" REALPATH )
get_filename_component( GENSYMLINK_SCRIPT_PATH "${SCRIPT_DIR}/genSymLinks.sh" REALPATH )
get_filename_component( TEST_CMAKE_PATH "${PROJECT_SOURCE_DIR}/../test/commandTests/CMakeLists.txt" REALPATH )
get_filename_component( COMMAND_CMAKE_PATH "${COMMAND_SOURCE_DIR}/CMakeLists.txt" REALPATH )
get_filename_component( DEFAULT_CFG_FILE_PATH "${CONFIG_DIR}/.config" REALPATH )

add_custom_target( 
    ${BOXER_PROJECT_NAME}_run ALL
    WORKING_DIRECTORY ${BUILD_PATH}
    COMMAND ${BOXER_PROJECT_NAME} 
        -c "${COMMAND_SOURCE_DIR}" 
        -i "${COMMAND_INCLUDE_PATH}"
        -l "${COMMAND_LIST_PATH}"
        -s "${GENSYMLINK_SCRIPT_PATH}"
        -t "${TEST_CMAKE_PATH}"
        -m "${COMMAND_CMAKE_PATH}"
        -f "${DEFAULT_CFG_FILE_PATH}"
)
