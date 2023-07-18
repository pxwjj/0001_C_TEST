/**
 * 字符转大写
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char c;
    while ( (c = getchar()) != EOF){
        c = toupper(c);
        // printf("%c", c);
        putchar(c);
    }

    return 0;
}