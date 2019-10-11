SET( COMMON_PARAMS "--enable=all --inconclusive --error-exitcode=7 --suppress=missingIncludeSystem" )
SET( XML_PARAMS "--xml --xml-version=2" )

add_test( cppcheck 
	${SCRIPT_PATH}/runCPPCheck.sh 
	"${COMMON_PARAMS} ${XML_PARAMS}" 
	"${SOURCES_ROOT}"
	"${SOURCES_INCLUDE}"
	"${STATIC_ANALYSIS_OUTPUT_PATH}/cpptest_raw.xml"
)
add_test( cppcheck_text
	${SCRIPT_PATH}/runCPPCheck.sh 
	"${COMMON_PARAMS}" 
	"${SOURCES_ROOT}"
	"${SOURCES_INCLUDE}"
	"${STATIC_ANALYSIS_OUTPUT_PATH}/cpptest_text"
)

add_test( cppcheck_boxer
	${SCRIPT_PATH}/runCPPCheck.sh 
	"${COMMON_PARAMS} ${XML_PARAMS}" 
	"${BOXER_SOURCES_ROOT}"
	"${BOXER_SOURCES_INCLUDE}"
	"${STATIC_ANALYSIS_OUTPUT_PATH}/cpptest_boxer_raw.xml"
)
add_test( cppcheck_boxer_text
	${SCRIPT_PATH}/runCPPCheck.sh 
	"${COMMON_PARAMS}" 
	"${BOXER_SOURCES_ROOT}"
	"${BOXER_SOURCES_INCLUDE}"
	"${STATIC_ANALYSIS_OUTPUT_PATH}/cpptest_boxer_text"
)