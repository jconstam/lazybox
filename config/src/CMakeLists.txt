cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${CONFIGURE_PROJECT_NAME} )

add_subdirectory( ${COMMON_PATH} ${BUILD_PATH}/common )

set( CONFIGURE_SOURCES
    ${CONFIGURE_SOURCES}
    ${COMMON_SOURCES_C}
    ${COMMON_SOURCES_CPP}
    ${PROJECT_SOURCE_DIR}/main.cpp
)

include_directories( 
    ${CONFIGURE_PROJECT_NAME}
    ${COMMON_PATH}/include
    ${PROJECT_SOURCE_DIR}/include
)

get_filename_component( CONFIG_DIR "${PROJECT_SOURCE_DIR}/.." REALPATH )

add_executable( ${CONFIGURE_PROJECT_NAME} ${CONFIGURE_SOURCES} )
target_link_libraries( ${CONFIGURE_PROJECT_NAME} )

add_custom_target( 
    ${CONFIGURE_PROJECT_NAME}_run ALL
    WORKING_DIRECTORY ${BUILD_PATH}
    COMMAND ${CONFIGURE_PROJECT_NAME}
        -c ${CONFIG_DIR}
)
