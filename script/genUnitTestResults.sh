#!/bin/bash

if [ "$#" -ne "3" ]; then
	echo "Usage: $0 <Project Name> <Source Dir> <Binary Dir>"
	exit 1
fi

PROJ_NAME=$1
SRC_DIR=$2
BIN_DIR=$3

lcov \
	--capture \
	--directory ${SRC_DIR}/.. \
	--output-file ${BIN_DIR}/${PROJ_NAME}_coverage_raw.info
lcov \
	--remove ${BIN_DIR}/${PROJ_NAME}_coverage_raw.info "/usr/*" "*googletest*" "*unittests*" \
	--output-file ${BIN_DIR}/${PROJ_NAME}_coverage_filtered.info 
genhtml \
	${BIN_DIR}/${PROJ_NAME}_coverage_filtered.info \
	--output-directory ${BIN_DIR}
python \
	-m lcov_cobertura \
	${BIN_DIR}/${PROJ_NAME}_coverage_filtered.info \
	-b ${SRC_DIR} \
	-o ${BIN_DIR}/${PROJ_NAME}_coverage.xml