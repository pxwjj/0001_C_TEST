#include<stdio.h>

char *student_level(int n)
{
    char *level = "";
    if (n == 0){
        level = "FOOLISH";
    } else if ( n > 0 && n < 60 ) {
        level = "FAIL";
    } else if ( n >= 60 && n <= 75 ) {
        level = "MEDIUM";
    } else {
        level = "GOOD";
    }
    
    return level;
}

void switch_test(int n)
{
    switch (n)
    {
    case 1:
        printf("one ");
        // break;
    case 2:
        printf("two ");
        // break;
    case 3:
        printf("three\n");
        break;

    default:
        printf("error\n");
        break;
    }

    return;
}

int main()
{
    int n = 0;
    char *level = "FOOLISH";

    printf("key in your scores:");
    scanf("%d", &n);
    level = student_level(n);
    printf("you are level is: %s \n", level);

    int done = 1;
    while ( done )
    {
        printf("--key in your num--");
        if ( scanf("%d", &n) != 1 )
            done = 0;
        else
            switch_test(n);
    }
    
    return 0;
}