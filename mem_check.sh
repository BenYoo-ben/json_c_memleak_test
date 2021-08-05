#!/bin/sh
if [ $# -ne 1 ]; then
	echo "Usage: $0 executable"
	exit -1
fi
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./$1
exit 0

