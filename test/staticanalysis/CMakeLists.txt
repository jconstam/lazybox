SET( COMMON_PARAMS "--enable=all --inconclusive --error-exitcode=7 --suppress=missingIncludeSystem -i build -i doc -i script -i test" )
SET( XML_PARAMS "--xml --xml-version=2" )

add_test( cppcheck 
	${SCRIPT_PATH}/runCPPCheck.sh 
	"${COMMON_PARAMS} ${XML_PARAMS}"
	"${ROOT_PATH}"
	"${STATIC_ANALYSIS_OUTPUT_PATH}/cpptest_raw.xml"
)
add_test( cppcheck_text
	${SCRIPT_PATH}/runCPPCheck.sh 
	"${COMMON_PARAMS}"
	"${ROOT_PATH}"
	"${STATIC_ANALYSIS_OUTPUT_PATH}/cpptest_text"
)
