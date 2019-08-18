#!/bin/bash

if [ "$#" -ne "1" ]; then
    echo "Usage: $0 <Main Binary>"
    exit -1
fi

MAIN_PROJECT_NAME=$1

ln -f -s ${MAIN_PROJECT_NAME} echo
ln -f -s ${MAIN_PROJECT_NAME} date