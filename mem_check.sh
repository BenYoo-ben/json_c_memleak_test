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
         --log-file=$1.txt \
         ./$1

echo "
" 
grep HEAP -A 5 ./$1.txt

echo 
grep LEAK -A 5 ./$1.txt
exit 0

