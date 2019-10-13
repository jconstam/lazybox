#!/bin/bash

if [ "$#" -ne "3" ]; then
	echo "Usage: $0 <Parameters> <Source Path> <Output File>"
	exit 1
fi

PARAMETERS=$1
SOURCE_PATH=$2
OUTFILE=$3

echo "cppcheck ${PARAMETERS} ${SOURCE_PATH}"
cppcheck ${PARAMETERS} ${SOURCE_PATH} 2> ${OUTFILE}