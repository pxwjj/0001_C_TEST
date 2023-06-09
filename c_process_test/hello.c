#include <stdio.h>

int math(int a , int b)
{
    return a+b;
}

int main()
{  
    int c;
    c = math(1,1);
    printf("hello world\n");
    printf("1 + 1 = %d\n" , c);
    return 0;
}
