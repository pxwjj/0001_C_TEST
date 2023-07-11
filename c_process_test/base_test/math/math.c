#include<stdio.h>
#include<math.h>

#define swap_test(a,b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}


// a=__temp^a;   -->  a=a^b^a  -->  a=a^a^b  -->  a=0^b  -->  a=b
#define swap_test_advance(a,b){ \
    __typeof(a) __temp1 = a ^ b; \ 
    a = __temp1 ^ a; b = __temp1 ^ b; \
}

// void swap_test(int *a , int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
//     return 0;
// }

int main()
{
    int a, b, ret;
    ret = scanf("%d%d", &a, &b);
    if (ret == 2)
    {
        printf("a = %d,b = %d\n", a, b);
        swap_test_advance(a, b);
        printf("a = %d,b = %d\n", a, b);
    }
    

    return 0;
}