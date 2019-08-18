cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${MAIN_PROJECT_NAME} )
project( ${BOXER_PROJECT_NAME} )

set( COMMAND_SOURCE_DIR ${PROJECT_SOURCE_DIR}/commands )
set( BOXER_SOURCE_DIR ${PROJECT_SOURCE_DIR}/boxer )
set( SCRIPT_DIR ${PROJECT_SOURCE_DIR}/../script )

set( SOURCES
    ${COMMAND_SOURCE_DIR}/date.cpp
    ${COMMAND_SOURCE_DIR}/echo.cpp
    
    ${PROJECT_SOURCE_DIR}/cmdList.cpp
    ${PROJECT_SOURCE_DIR}/cmdRegistry.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
)

set( BOXER_SOURCES
    ${BOXER_SOURCE_DIR}/main.cpp
    ${BOXER_SOURCE_DIR}/CmdFileScanner.cpp
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
    WORKING_DIRECTORY ${BUILD_PATH}/${MAIN_PROJECT_NAME}
    COMMAND ${SCRIPT_DIR}/genSymLinks.sh ${MAIN_PROJECT_NAME}
)

add_executable( ${BOXER_PROJECT_NAME} ${BOXER_SOURCES} )
target_link_libraries( ${BOXER_PROJECT_NAME} stdc++fs )
add_custom_target( RUN_${BOXER_PROJECT_NAME}
    WORKING_DIRECTORY ${BUILD_PATH}
    COMMAND ${BOXER_PROJECT_NAME} 
        -c "${COMMAND_SOURCE_DIR}" 
        -i "${PROJECT_SOURCE_DIR}/../include/commands.hpp"
        -l "${PROJECT_SOURCE_DIR}/cmdList.cpp"
        -s "${SCRIPT_DIR}/genSymLinks.sh"
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
    