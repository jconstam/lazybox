add_test( cppcheck
	cppcheck
	--enable=all
	--inconclusive
	--error-exitcode=7
	--xml
	--output-file=${STATIC_ANALYSIS_OUTPUT_PATH}/cpptest_raw.xml
	${SOURCES_ROOT}
)