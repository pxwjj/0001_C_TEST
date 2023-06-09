#include <stdio.h>

#define ENDSTRING '\0'

int StrLen(char *str)
{
    int i = 0;
    while (str[i] != ENDSTRING)
        i++;
    return i;
}
