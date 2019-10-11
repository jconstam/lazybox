TRAVIS_BUILD_NUMBER ?= 0

ROOT_PATH=$(shell pwd)
PROJ_NAME=lazybox
PROJ_NAME_BOXER=boxer
PROJ_NAME_CONFIGURE=lazybox_configure

SOURCE_PATH=${ROOT_PATH}/src
SOURCE_PATH_BOXER=${ROOT_PATH}/boxer
INCLUDE_PATH=${ROOT_PATH}/include
TEST_PATH=${ROOT_PATH}/test
BUILD_PATH=${ROOT_PATH}/build
SCRIPT_PATH=${ROOT_PATH}/script
DOC_PATH=${ROOT_PATH}/doc
BOXER_PATH=${ROOT_PATH}/boxer
CONFIG_PATH=${ROOT_PATH}/config
CONFIG_SRC_PATH=${CONFIG_PATH}/src
COMMON_PATH=${ROOT_PATH}/common

DEFAULT_INSTALL_PATH=bin
INSTALL_PATH?=${DEFAULT_INSTALL_PATH}

OUTPUT_PATH_MAIN=${BUILD_PATH}/${PROJ_NAME}
OUTPUT_PATH_BOXER=${BUILD_PATH}/${PROJ_NAME_BOXER}
OUTPUT_PATH_CONFIGURE=${BUILD_PATH}/${PROJ_NAME_CONFIGURE}
OUTPUT_PATH_MAIN_TEST=${BUILD_PATH}/test

.PHONY: build
build: config
	mkdir -p ${OUTPUT_PATH_MAIN}
	cd ${OUTPUT_PATH_MAIN} && \
	cmake ${SOURCE_PATH} \
		-DMAIN_PROJECT_NAME:STRING=${PROJ_NAME} \
		-DBUILD_PATH=${BUILD_PATH} \
		-DSCRIPT_PATH=${SCRIPT_PATH} \
		-DDOC_PATH=${DOC_PATH} \
		-DROOT_PATH=${ROOT_PATH} \
		-DCOMMON_PATH=${COMMON_PATH} \
	&& $(MAKE) $(MAKEFLAGS)

.PHONY: config
config:
	mkdir -p ${OUTPUT_PATH_BOXER}
	cd ${OUTPUT_PATH_BOXER} && \
	cmake ${BOXER_PATH} \
		-DBOXER_PROJECT_NAME:STRING=${PROJ_NAME_BOXER} \
		-DSOURCE_PATH=${SOURCE_PATH} \
		-DBUILD_PATH=${BUILD_PATH} \
		-DCOMMON_PATH=${COMMON_PATH} \
	&& $(MAKE) $(MAKEFLAGS)

.PHONY: menuconfig
menuconfig:
	mkdir -p ${OUTPUT_PATH_CONFIGURE}
	cd ${OUTPUT_PATH_CONFIGURE} && \
	cmake ${CONFIG_SRC_PATH} \
		-DCONFIGURE_PROJECT_NAME:STRING=${PROJ_NAME_CONFIGURE} \
		-DCOMMON_PATH=${COMMON_PATH} \
		-DBUILD_PATH=${BUILD_PATH} \
	&& $(MAKE) $(MAKEFLAGS)

.PHONY: install
install: build
ifneq (${INSTALL_PATH},${DEFAULT_INSTALL_PATH})
	mkdir -p ${INSTALL_PATH}
endif
	cd ${OUTPUT_PATH_MAIN} && $(MAKE) install 

.PHONY: test
test: build_tests
	-cd ${OUTPUT_PATH_MAIN_TEST} && ctest --output-on-failure -T Test -C RelWithDebInfo
	xsltproc script/ctest2junit.xsl ${BUILD_PATH}/test/Testing/`head -n 1 < ${BUILD_PATH}/test/Testing/TAG`/Test.xml > ${BUILD_PATH}/test/ctestjunittestresults.xml
	cppcheck_junit ${BUILD_PATH}/test/staticanalysis/cpptest_raw.xml ${BUILD_PATH}/test/staticanalysis/cpptest_results.xml
	cppcheck_junit ${BUILD_PATH}/test/staticanalysis/cpptest_boxer_raw.xml ${BUILD_PATH}/test/staticanalysis/cpptest_boxer_results.xml

.PHONY: test_only
test_only:
	-cd ${OUTPUT_PATH_MAIN_TEST} && ctest --output-on-failure -T Test -C RelWithDebInfo
	xsltproc script/ctest2junit.xsl ${BUILD_PATH}/test/Testing/`head -n 1 < ${BUILD_PATH}/test/Testing/TAG`/Test.xml > ${BUILD_PATH}/test/ctestjunittestresults.xml
	cppcheck_junit ${BUILD_PATH}/test/staticanalysis/cpptest_raw.xml ${BUILD_PATH}/test/staticanalysis/cpptest_results.xml
	cppcheck_junit ${BUILD_PATH}/test/staticanalysis/cpptest_boxer_raw.xml ${BUILD_PATH}/test/staticanalysis/cpptest_boxer_results.xml

.PHONY: test_verbose
test_verbose: build_tests
	cd ${OUTPUT_PATH_MAIN_TEST} && ctest -V

.PHONY: build_tests
build_tests: build
	mkdir -p ${OUTPUT_PATH_MAIN_TEST}
	cd ${OUTPUT_PATH_MAIN_TEST} && \
	cmake ${TEST_PATH} \
		-DPROJECT_NAME=${PROJ_NAME} \
		-DOUTPUT_PATH=${OUTPUT_PATH_MAIN} \
		-DCOMMON_PATH=${COMMON_PATH} \
		-DBUILD_PATH=${BUILD_PATH} \
		-Wno-dev \
	&& $(MAKE) $(MAKEFLAGS)

.PHONY: clean
clean:
	rm -rf ${BUILD_PATH}

.PHONY: docs
docs:
	python ${SCRIPT_PATH}/genReadme.py -r "${DOC_PATH}/readmeData.json" -m "${DOC_PATH}/moduleData.json" -o "${ROOT_PATH}/README.md"
