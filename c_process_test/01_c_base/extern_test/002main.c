#include <stdio.h>

extern int StrLen(char *str);

int main()
{
    char *str = "hello";
    printf("str length is %d \n" , StrLen(str));

    return 0;
}
