TRAVIS_BUILD_NUMBER ?= 0

ROOT_PATH=$(shell pwd)
PROJ_NAME=lazybox

SOURCE_PATH=${ROOT_PATH}/src
INCLUDE_PATH=${ROOT_PATH}/include
TEST_PATH=${ROOT_PATH}/test
BUILD_PATH=${ROOT_PATH}/build
DEFAULT_INSTALL_PATH=bin
INSTALL_PATH?=${DEFAULT_INSTALL_PATH}

OUTPUT_PATH=${BUILD_PATH}/${PROJ_NAME}
OUTPUT_TEST_PATH=${BUILD_PATH}/test

.PHONY: build
build:
	mkdir -p ${OUTPUT_PATH}
	cd ${OUTPUT_PATH} && cmake ${SOURCE_PATH} -DPROJECT_NAME=${PROJ_NAME} -DBUILD_PATH=${BUILD_PATH} -DINSTALL_PATH=${INSTALL_PATH} && $(MAKE) $(MAKEFLAGS)

.PHONY: install
install: build
ifneq (${INSTALL_PATH},${DEFAULT_INSTALL_PATH})
	mkdir -p ${INSTALL_PATH}
endif
	cd ${OUTPUT_PATH} && $(MAKE) install 

.PHONY: test
test: build_tests
	cd ${OUTPUT_TEST_PATH} && ctest --output-on-failure

.PHONY: test_verbose
test_verbose: build_tests
	cd ${OUTPUT_TEST_PATH} && ctest -V

.PHONY: build_tests
build_tests:
	mkdir -p ${OUTPUT_TEST_PATH}
	cd ${OUTPUT_TEST_PATH} && cmake ${TEST_PATH} -DPROJECT_NAME=${PROJ_NAME} && $(MAKE) $(MAKEFLAGS)

.PHONY: clean
clean:
	rm -rf ${BUILD_PATH}
