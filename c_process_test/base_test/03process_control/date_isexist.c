#include<stdio.h>
//srand(time(0)) //随机数种子
//a = rand() %100  //a 为100以内的随机数

#define runnian(yy,mm,dd) { \
    if ( dd > 0 && dd <= 29 ) { \
        printf("%d-%d-%d exist\n", yy, mm, dd); \
        return; \
    } \
}

#define no_runnian(yy,mm,dd) { \
    if ( dd > 0 && dd < 29 ) { \
        printf("%d-%d-%d exist\n", yy, mm, dd); \
        return; \
    } \
}

void date_exist(int yy, int mm, int dd)
{
    if ( mm < 1 || mm > 12 )
    {
        printf("%d-%d-%d no exist\n", yy, mm, dd);
        return;
    }

    if ( dd < 1 || dd > 31 )
    {
        printf("%d-%d-%d no exist\n", yy, mm, dd);
        return;
    }
    
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11){
        if (dd > 0 && dd < 31){
            printf("%d-%d-%d exist\n", yy, mm, dd);
            return;
        }
    }else if (mm == 2){
        if ( yy%100 == 0 ){
            if ( yy%400 == 0 ){
                runnian(yy,mm,dd);
            }
        }else if ( yy%4 == 0 ){
            runnian(yy,mm,dd);
        }
        no_runnian(yy,mm,dd);
    }else{
        if ( dd > 0 && dd <= 31) {
            printf("%d-%d-%d exist\n", yy, mm, dd);
        }
    }
    
    printf("%d-%d-%d no exist\n", yy, mm, dd);
    return ;
}

int main()
{
    int yy, mm, dd;
    scanf("%d%d%d", &yy,&mm,&dd);
    printf("you key in date is: %d-%d-%d \n", yy, mm, dd);

    date_exist(yy,mm,dd);

    return 0;
}