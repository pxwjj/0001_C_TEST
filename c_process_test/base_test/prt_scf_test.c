#include <stdio.h>

#define __ZERO__ (0)
#define __MAX__ (100)

/**
 * 计算输入的数字有几位
*/
int sprintf_test()
{
    int num,ret;
    char str[__MAX__] = {0};

    while ( (ret = scanf("%d", &num)) != EOF )
    {
        if( ret == __ZERO__ )
        {
            printf("scanf error\n");
            break;
        }
        else
        {
            printf("length = %d \n", sprintf(str, "%d", num));
        }
    }
    
    return 0;
}

/**
 * 计算输入的字符串（带空格），去掉空格之后，还剩多少个字符，使用行缓冲（gets）
 * gets 比较危险； 可以用 scanf("%[0-9a-zA-Z ]s", str)：[0-9a-zA-Z ]正则表达式
*/
int scanf_RegEx_test()
{
    char str[__MAX__] = {0};
    char str1[__MAX__] = {0};
    int ret = 0, count = 0;
    int tmp_n;

    while ( (tmp_n = scanf("%[0-9a-zA-Z ]s", str)) != EOF )
    {
        getchar(); //用getchar 把 \n 这个流拿走，要是不拿的话，这个流一直在，所以，scanf 一直不匹配，这个流一直拿不走, 所以一直while循环。
        printf("ret = %d\n", tmp_n);
        ret = sprintf(str1, "%s", str);
        for (int i = 0; i < ret; i++)
        {
            if(str[i] == ' ')
            {
                count++;
            }
        }
        printf("out put char length: %d\n", (ret - count));
        ret = count = 0;
    }
    
    return 0;
}

int main()
{
    scanf_RegEx_test();

    return 0;
}
