/**
 * thread more exit 
 * 线程退出方式
 * 1、return 2、pthread_exit() 3、pthread_cancel()
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *thr_fun1(void *argv)
{
    printf("thread [1] return\n");
    return (void *)1;
}

void *thr_fun2(void *argv)
{
    printf("thread [2] exit\n");
    pthread_exit((void *)2);
    return NULL;
}

void *thr_fun3(void *argv)
{
    while (1){
        printf("sleeping\n");
        sleep(1);
    }
    return NULL;
}

void print_ret(int num, long ret)
{
    printf("thread [%d] exit code [%ld]\n", num, ret);
    return;
}

int main()
{
    pthread_t ntid;
    void *stat;

    pthread_create(&ntid, NULL, thr_fun1, NULL);
    pthread_join(ntid, &stat); //stat 记录线程退出的返回值
    print_ret(1, stat);   

    pthread_create(&ntid, NULL, thr_fun2, NULL);
    pthread_join(ntid, &stat);
    print_ret(2, stat);

    pthread_create(&ntid, NULL, thr_fun3, NULL);
    sleep(3);
    pthread_cancel(ntid);
    pthread_join(ntid, &stat);
    print_ret(1, stat);   

    return 0;
}