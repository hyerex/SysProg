#!/bin/sh
# Autor: Andreas Ly
# Version: 18.12.2018
# Parameter für gcc aufrufe anschauen

for s in liste.c fachnote.c ; do
    compile_command="gcc -c -W -Wall -pedantic -fpic $s"
    echo $compile_command
    eval $compile_command
    if [ $? -ne 0 ] ; then
	echo build failed compile
	exit 1
      fi
done
lib_command="gcc -shared fachnote.o liste.o -o libaufgabe5.so"
echo $lib_command
eval $lib_command
if [ $? -ne 0 ] ; then
    echo build failed bind
    exit 1
fi
echo build successful
