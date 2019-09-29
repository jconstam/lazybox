cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${MAIN_PROJECT_NAME} )

set( COMMAND_SOURCE_DIR ${PROJECT_SOURCE_DIR}/commands )
set( SCRIPT_DIR ${PROJECT_SOURCE_DIR}/../script )

add_subdirectory( ${COMMAND_SOURCE_DIR} )
add_subdirectory( ${COMMON_PATH} ${BUILD_PATH}/common )

set( SOURCES
    ${COMMAND_SOURCES_C}
    ${COMMAND_SOURCES_CPP}
    ${COMMON_SOURCES_C}
    ${COMMON_SOURCES_CPP}
    
    ${PROJECT_SOURCE_DIR}/cmdList.cpp
    ${PROJECT_SOURCE_DIR}/cmdRegistry.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/parseArgs.c
)

include_directories( 
	${MAIN_PROJECT_NAME} 
    ${COMMON_PATH}/include
	${PROJECT_SOURCE_DIR}/include
)

add_executable( ${MAIN_PROJECT_NAME} ${SOURCES} )
add_dependencies( ${MAIN_PROJECT_NAME} GENERATE_DOCS_${MAIN_PROJECT_NAME} )
add_custom_command( 
    TARGET ${MAIN_PROJECT_NAME} POST_BUILD
    WORKING_DIRECTORY ${BUILD_PATH}/${MAIN_PROJECT_NAME}
    COMMAND ${SCRIPT_DIR}/genSymLinks.sh ${MAIN_PROJECT_NAME}
)

get_filename_component( GENREADME_SCRIPT "${SCRIPT_PATH}/genReadme.py" REALPATH )
get_filename_component( READMEDATA_JSON "${DOC_PATH}/readmeData.json" REALPATH )
get_filename_component( MODULEDATA_JSON "${DOC_PATH}/moduleData.json" REALPATH )
get_filename_component( README_MD "${ROOT_PATH}/README.md" REALPATH )
add_custom_target( 
    GENERATE_DOCS_${MAIN_PROJECT_NAME} 
	COMMAND python ${GENREADME_SCRIPT} -r ${READMEDATA_JSON} -m ${MODULEDATA_JSON} -o ${README_MD}
)
