#!/bin/sh
if [ $# -ne 1 ]; then
	echo "Usage: $0 executable"
	exit -1
fi
echo "
"

echo "LD_LIBRARY_PATH = $LD_LIBRARY_PATH"

echo "export..."

export LD_LIBRARY_PATH=./lib/lib

echo "LD_LIBRARY_PATH = $LD_LIBRARY_PATH"

echo "
"
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./$1

echo "
" 
grep HEAP -A 5 ./valgrind-out.txt

echo 
grep LEAK -A 5 ./valgrind-out.txt
exit 0

