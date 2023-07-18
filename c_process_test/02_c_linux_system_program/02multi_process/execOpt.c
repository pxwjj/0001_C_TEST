/**
 * exec 族函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    execlp("/usr/bin/ls", "ls", "-al", NULL);

    return 0;
}