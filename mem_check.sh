#!/bin/sh
if [ $# -ne 1 ]; then
	echo "Usage: $0 executable"
	exit -1
fi
echo "
"
LD_PRELOAD="./lib/lib/libjson-c.so.3" valgrind --leak-check=full \
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

