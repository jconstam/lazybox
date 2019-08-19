# This file was automatically generated on Mon Aug 19 18:23:43 2019

#!/bin/bash

if [ "$#" -ne "1" ]; then
	echo "Usage: $0 <Main Binary>"
	exit -1
fi

MAIN_PROJECT_NAME=$1

ln -f -s ${MAIN_PROJECT_NAME} date
ln -f -s ${MAIN_PROJECT_NAME} echo
