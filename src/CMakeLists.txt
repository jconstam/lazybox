cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${PROJECT_NAME} )

set( SOURCES
    ${PROJECT_SOURCE_DIR}/commands/date.cpp
    ${PROJECT_SOURCE_DIR}/commands/echo.cpp
    
    ${PROJECT_SOURCE_DIR}/cmdRegistry.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
)

include_directories( 
	${PROJECT_NAME} 
	${PROJECT_SOURCE_DIR}/../include
    )

add_executable( ${PROJECT_NAME} ${SOURCES} )
add_custom_command( 
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ln -f -s ${PROJECT_NAME} echo
    COMMAND ln -f -s ${PROJECT_NAME} date
    )

install( 
    TARGETS ${PROJECT_NAME}
    DESTINATION ${INSTALL_PATH}
    )
install( 
    FILES 
        ${BUILD_PATH}/${PROJECT_NAME}/echo 
        ${BUILD_PATH}/${PROJECT_NAME}/date
    DESTINATION ${INSTALL_PATH}
    )