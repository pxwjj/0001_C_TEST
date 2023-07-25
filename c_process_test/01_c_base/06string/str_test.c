/**
 * %X 16进制
 * 字符串操作
 * strlen(str); 字符数组中有多少个有效字符，遇到 \0 结束,sizeof()这个字符数组占多少空间
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