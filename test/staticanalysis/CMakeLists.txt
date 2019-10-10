SET( COMMON_PARAMS "--enable=all --inconclusive --error-exitcode=7 --suppress=missingIncludeSystem" )

add_test( cppcheck 
	${SCRIPT_PATH}/runCPPCheck.sh 
	"${COMMON_PARAMS} --xml" 
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