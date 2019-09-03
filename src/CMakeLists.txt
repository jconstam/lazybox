cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${MAIN_PROJECT_NAME} )
project( ${BOXER_PROJECT_NAME} )

set( COMMAND_SOURCE_DIR ${PROJECT_SOURCE_DIR}/commands )
set( BOXER_SOURCE_DIR ${PROJECT_SOURCE_DIR}/boxer )
set( SCRIPT_DIR ${PROJECT_SOURCE_DIR}/../script )

add_subdirectory( ${COMMAND_SOURCE_DIR} )

set( SOURCES
    ${COMMAND_SOURCES_C}
    ${COMMAND_SOURCES_CPP}
    
    ${PROJECT_SOURCE_DIR}/cmdList.cpp
    ${PROJECT_SOURCE_DIR}/cmdRegistry.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/parseArgs.c
)

set( BOXER_SOURCES
    ${BOXER_SOURCE_DIR}/main.cpp
    ${BOXER_SOURCE_DIR}/CmdFileScanner.cpp
    ${BOXER_SOURCE_DIR}/LazyBoxCommands.cpp
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
add_dependencies( ${MAIN_PROJECT_NAME} GENERATE_DOCS_${MAIN_PROJECT_NAME} )
add_custom_command( 
    TARGET ${MAIN_PROJECT_NAME} POST_BUILD
    WORKING_DIRECTORY ${BUILD_PATH}/${MAIN_PROJECT_NAME}
    COMMAND ${SCRIPT_DIR}/genSymLinks.sh ${MAIN_PROJECT_NAME}
)

add_executable( ${BOXER_PROJECT_NAME} ${BOXER_SOURCES} )
target_link_libraries( ${BOXER_PROJECT_NAME} stdc++fs )

get_filename_component( COMMAND_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/../include/commands.hpp" REALPATH )
get_filename_component( COMMAND_LIST_PATH "${PROJECT_SOURCE_DIR}/cmdList.cpp" REALPATH )
get_filename_component( GENSYMLINK_SCRIPT_PATH "${SCRIPT_DIR}/genSymLinks.sh" REALPATH )
get_filename_component( TEST_CMAKE_PATH "${PROJECT_SOURCE_DIR}/../test/commandTests/CMakeLists.txt" REALPATH )
get_filename_component( COMMAND_CMAKE_PATH "${COMMAND_SOURCE_DIR}/CMakeLists.txt" REALPATH )

add_custom_target( 
    RUN_${BOXER_PROJECT_NAME}
    WORKING_DIRECTORY ${BUILD_PATH}
    COMMAND ${BOXER_PROJECT_NAME} 
        -c "${COMMAND_SOURCE_DIR}" 
        -i "${COMMAND_INCLUDE_PATH}"
        -l "${COMMAND_LIST_PATH}"
        -s "${GENSYMLINK_SCRIPT_PATH}"
        -t "${TEST_CMAKE_PATH}"
        -m "${COMMAND_CMAKE_PATH}"
)
add_dependencies( RUN_${BOXER_PROJECT_NAME} ${BOXER_PROJECT_NAME} )

get_filename_component( GENREADME_SCRIPT "${SCRIPT_PATH}/genReadme.py" REALPATH )
get_filename_component( READMEDATA_JSON "${DOC_PATH}/readmeData.json" REALPATH )
get_filename_component( MODULEDATA_JSON "${DOC_PATH}/moduleData.json" REALPATH )
get_filename_component( README_MD "${ROOT_PATH}/README.md" REALPATH )
add_custom_target( 
    GENERATE_DOCS_${MAIN_PROJECT_NAME} 
	COMMAND python ${GENREADME_SCRIPT} -r ${READMEDATA_JSON} -m ${MODULEDATA_JSON} -o ${README_MD}
)
add_dependencies( GENERATE_DOCS_${MAIN_PROJECT_NAME} ${BOXER_PROJECT_NAME} )

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
    