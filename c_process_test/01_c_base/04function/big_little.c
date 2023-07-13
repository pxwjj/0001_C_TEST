#include<stdio.h>

int is_little()
{
    int num = 1;
    return ((char *)(&num))[0];
    // char *a = "";
    // a = &num;
    // printf("%d\n", a[0]);
    // printf("%d\n", a[3]);
    // return a[0];
}

int main()
{
    printf("my computer is %s \n", is_little() ? "little" : "big");

    return 0;
}