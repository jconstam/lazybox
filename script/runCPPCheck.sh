#!/bin/bash

if [ "$#" -ne "4" ]; then
	echo "Usage: $0 <Parameters> <Source Path> <Include Path> <Output File>"
	exit 1
fi

PARAMETERS=$1
SOURCE_PATH=$2
INCLUDE_PATH=$3
OUTFILE=$4

echo "cppcheck ${PARAMETERS} -I ${INCLUDE_PATH} ${SOURCE_PATH}"
cppcheck ${PARAMETERS} -I ${INCLUDE_PATH} ${SOURCE_PATH} 2> ${OUTFILE}