/**
 * %X 16进制
 * 字符串操作
 * strlen(str);
 * strncmp(str1, str2, n);
 * strncpy(dest, src, n); 
 * memcpy(str1, str2, n); 
 * memcmp(str1, str2, n);
 * memset(str1, c, n); 
*/
#include<string.h>
#include<stdio.h>

#define MAX_N (100)
int main()
{
    int n;
    char str[MAX_N + 5] = {0};

    while ( scanf("%d", &n) == 1 )
    {
        sprintf(str, "%X", n);
        printf( "%d(%s) has %d digits\n",n, str, strlen(str));
    }
    
    return 0;
}