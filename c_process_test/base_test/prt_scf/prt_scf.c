#include <stdio.h>

#define __ZERO__ (0)
//cppreference 查阅资料
int main()
{
    int a,ret;
    char str[]="hello world\n";
    const char strformat[] = "str len : %d\n";
    char str1[100] = {0};

    a = printf(str);  //printf 有返回值 为字符串的长度
    printf(strformat , a); //a = 12

    if ( (ret = scanf("input %s" , str)) != __ZERO__ )//scanf的返回值 通过标准输入 成功赋值的个数 //执行程序之后，应该输入，“input aaa” 那么就会把aaa 给str
    {
        printf("ret = %d ,output: %s \n" , ret , str);//输出 “ret = 1 ,output: aaa”
    }
    
    {
        fprintf(stdout , "fprintf stdout say:%s\n" , str); //把格式字符串 输入给某个文件中
    }

    {
        sprintf(str1 , "sprintf str1 %s" , str); //把格式字符串 输入给 另一个字符串 返回值也是 字符串的长度  字符串拼接
        printf("%s\n",str1);
    }

    while ( scanf("%s",str) != EOF ) //循环输入  EOF : end of file 文件结尾
    {
        printf("output:%s\n" , str);
    }

    return 0;
}
