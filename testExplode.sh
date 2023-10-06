#!/bin/bash

function cleanup()
{
    [ -e testFile ] && rm testFile
}

function error()
{
    echo -e "ERROR: $1"
    cleanup
    exit 1
}

make explode &>> /dev/null

if [ $? -ne 0 ]; then
    error "make failed!" 
fi

[ -x explode ] || error "explode not found or not executable"

declare -A stringTest
stringTest["a"]="a"
stringTest["ab"]="aab"
stringTest["abc"]="aababc"

for key in "${!stringTest[@]}"
do
    echo ${key} > testFile
    actual=`./explode testFile`
    expected="${key} --> ${stringTest[${key}]}"
    [ "${actual}" != "${expected}" ] && error "\texpecting: ${expected}\n\t   actual: ${actual}"
done

cleanup

exit 0
