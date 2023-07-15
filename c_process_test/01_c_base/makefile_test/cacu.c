#include <stdio.h>
#include "add/add.h"
#include "sub/sub.h"

int main()
{
    int a,b;
    float c,d;

    scanf("%d %d" , &a , &b);
    printf("ADD: %d\n" , add_int(a,b));
    printf("SUB: %d\n" , sub_int(a,b));

    scanf("%f %f" , &c , &d);
    printf("ADD: %f\n" , add_float(c,d));
    printf("SUB: %f\n" , sub_float(c,d));

    return 0;
}
