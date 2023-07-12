/**
 * 结构体 struct 字节对齐
 * 有一个宏 可以更改默认的对齐方式
 * 
 * 共用体  union 共用体中，各个变量，谁占用的字节多，那么共用体的大小就是这个字节数
*/
#include<stdio.h>

#define P(fun) { \
    printf("(%s) = %d\n", #fun, fun); \
}

//结构体类型 字节对齐
typedef struct person
{
    char name[20]; //20
    int age;        //4
    char gender;    //4
    float hight;    //4
}person;

typedef struct a1
{
    
}a1;

typedef int char1;

union node  //sizeof(union node) = 24
{
    double a;   //8
    char b[20]; //24
    int c;      //4
};

/**
 * 使用 union将 ip 转成 数字
*/
union IP
{
    struct ip
    {
        char a1;
        char a2;
        char a3;
        char a4;
    }ip;
    int num;    
};


int main()
{
    /*
    union IP p;
    char str[100] = {0};
    int str_IP[4] = {0};
    while (scanf("%s", str) == 1)
    {
        sscanf(str, "%d.%d.%d.%d", str_IP[0], str_IP[1], str_IP[2], str_IP[3]);
        p.ip.a1 = str_IP[0];
        p.ip.a1 = str_IP[1];
        p.ip.a1 = str_IP[2];
        p.ip.a1 = str_IP[3];
        printf("%u\n", p.num);
    }
    */

   /*
    char1 b; //int b  4字节
    person a;
    person *c;

    P(sizeof(struct a1));
    P(sizeof(union node));
    P(sizeof(a));
    P(sizeof(b));
    P(sizeof(long));
    P(sizeof(short));
    P(sizeof(char *));
    P(sizeof(int *));
    P(sizeof(float));
    P(sizeof(double));
   */

    return 0;
}