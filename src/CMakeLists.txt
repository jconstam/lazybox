cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${PROJECT_NAME} )

set( SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    
    ${PROJECT_SOURCE_DIR}/echo.cpp
)

include_directories( 
	${PROJECT_NAME} 
	${PROJECT_SOURCE_DIR}/../include
    )
    
add_executable( ${PROJECT_NAME} ${SOURCES} )