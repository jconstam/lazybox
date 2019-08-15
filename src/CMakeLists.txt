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
add_custom_command( 
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ln -f -s ${PROJECT_NAME} echo
    )

message( "OUTPUT: ${CMAKE_EXECUTABLE_OUTPUT_PATH}")

install( 
    TARGETS ${PROJECT_NAME}
    DESTINATION ${INSTALL_PATH}
    )
install( 
    DIRECTORY ${BUILD_PATH}/${PROJECT_NAME}/echo
    DESTINATION ${INSTALL_PATH}
    )