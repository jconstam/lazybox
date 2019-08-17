cmake_minimum_required( VERSION 3.5 )

set( CMAKE_VERBOSE_MAKEFILE True )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${MAIN_PROJECT_NAME} )
project( ${BOXER_PROJECT_NAME} )

set( BOXER_SOURCE_DIR ${PROJECT_SOURCE_DIR}/boxer )

set( SOURCES
    ${PROJECT_SOURCE_DIR}/commands/date.cpp
    ${PROJECT_SOURCE_DIR}/commands/echo.cpp
    
    ${PROJECT_SOURCE_DIR}/cmdRegistry.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
)

set( BOXER_SOURCES
    ${BOXER_SOURCE_DIR}/main.cpp
)

include_directories( 
	${MAIN_PROJECT_NAME} 
	${PROJECT_SOURCE_DIR}/../include
)

include_directories( 
    ${BOXER_PROJECT_NAME} 
    ${BOXER_SOURCE_DIR}/include
)

add_executable( ${MAIN_PROJECT_NAME} ${SOURCES} )
add_dependencies( ${MAIN_PROJECT_NAME} RUN_${BOXER_PROJECT_NAME} )
add_custom_command( 
    TARGET ${MAIN_PROJECT_NAME} POST_BUILD
    COMMAND ln -f -s ${MAIN_PROJECT_NAME} echo
    COMMAND ln -f -s ${MAIN_PROJECT_NAME} date
)

add_executable( ${BOXER_PROJECT_NAME} ${BOXER_SOURCES} )
add_custom_target( RUN_${BOXER_PROJECT_NAME}
    WORKING_DIRECTORY ${BUILD_PATH}
    COMMAND ${BOXER_PROJECT_NAME}
)
add_dependencies( RUN_${BOXER_PROJECT_NAME} ${BOXER_PROJECT_NAME} )

install( 
    TARGETS ${MAIN_PROJECT_NAME}
    DESTINATION ${INSTALL_PATH}
)
install( 
    FILES 
        ${BUILD_PATH}/${MAIN_PROJECT_NAME}/echo 
        ${BUILD_PATH}/${MAIN_PROJECT_NAME}/date
    DESTINATION ${INSTALL_PATH}
)
    