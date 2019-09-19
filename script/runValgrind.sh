#!/bin/bash

VALGRIND_ERR_CODE=7

valgrind \
    --leak-check=full \
    --show-leak-kinds=all \
    --error-for-leak-kinds=all \
    --error-exitcode=$VALGRIND_ERR_CODE \
    $@
    
RESULT=$?
echo "RESULT: $RESULT"
if [ "$RESULT" -eq "0" ]; then
    echo "NO ERROR"
    exit 0
elif [ "$RESULT" -eq "$VALGRIND_ERR_CODE" ]; then
    echo "VALGRIND ERROR"
    exit 1
else
    echo "APPLICATION ERROR"
    exit 0
fi