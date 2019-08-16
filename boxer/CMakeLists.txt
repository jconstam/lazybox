cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 17 )

project( ${PROJECT_NAME_BOXER} )

set( SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
)

include_directories( 
	${PROJECT_NAME_BOXER} 
	${PROJECT_SOURCE_DIR}/include
    )

add_executable( ${PROJECT_NAME_BOXER} ${SOURCES} )

add_custom_command( 
    TARGET ${PROJECT_NAME_BOXER} POST_BUILD
    COMMAND ${BUILD_PATH}/${PROJECT_NAME_BOXER} 
    )
