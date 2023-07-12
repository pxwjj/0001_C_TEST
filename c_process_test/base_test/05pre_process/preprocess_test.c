/**
 * 数组
 * 预处理命令
 * gcc -E 看一下 宏替换之后的结果
*/
#include<stdio.h>

#define MAX_N (100)
// #define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX(a, b) ( \
    {  \
        __typeof(a) __temp_a = (a); \
        __typeof(a) __temp_b = (b); \
        __temp_a > __temp_b ? __temp_a : __temp_b ;\
    } \
)

#define P(fun) { \
    printf("%s = %d\n", #fun, fun); \
}

/**
 * 打印log 的宏 输出所在函数以及行号等信息
 * 
 * __FILE__ 返回所在的文件
 * __func__ 以字符串形式返回所在函数名称
 * __LINE__ 整数形式返回代码的行号
*/
char pre_fmt[MAX_N] = "";
#define MY_LOG(fmat, arg, val) { \
    sprintf(pre_fmt, "[%s : %s() %s] %s = %s\n","%s", "%s", "%d","%s", fmat); \
    printf(pre_fmt , __FILE__, __func__, __LINE__, arg, val); \
}

int is_prime(int n)
{
    for (int i = 2; i < n; i++){
        if (n % i == 0) return 0;
    }

    return 1;
}


int main()
{
    /*
    int n;
    while ( scanf("%d", &n) == 1 ){
        if (n == 1)
        {
            printf("1 NO\n");
            continue;
        }
        printf("%d %s prime\n", n, is_prime(n) ? "is":"isn`t" );
    }
    */
   
    /*
    int a = 7;
    P(MAX(2,3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    printf("a = %d\n", a);
    */

    char a[MAX_N] = "hello world";
    int b = 123;
    MY_LOG("%s", "a", a);
    MY_LOG("%d", "b", b);

    return 0;
}