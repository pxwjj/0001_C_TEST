#include<stdio.h>

/**
 * 1、递归程序
 * 2、linux 系统栈大约为 8MB  windows 为 2MB
 * 3、函数指针：把一个函数当作另一个函数的参数去使用
*/

int fun_test(int k, int x, int b)
{
    return k*x+b;
}

int fac(int n)
{
    int ret = 0;
    if( n == 1 ) return 1;

    ret = n * fac(n-1);

    return ret;
}

int main()
{
    // int k, b;
    int n;

    // while ( scanf("%d%d", &k, &b) == 2 ){
    //     for (int i = 0; i < 101; i++)
    //         printf("ret = %d\n",fun_test(k,i,b));
    // }

    while ( scanf("%d", &n) == 1 ){
        printf("%d 的阶乘为：%d \n", n, fac(n) );
    }
    
    return 0;
}