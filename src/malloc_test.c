/*
 *  author: byong.yoo
 *  description:
 *  to check if valgrind is functional.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *a = malloc(sizeof(char) * 100);

    a[100-1] = '\0';

    exit(0);

}
