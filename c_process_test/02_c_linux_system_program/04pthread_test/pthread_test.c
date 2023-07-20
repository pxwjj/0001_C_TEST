/**
 * 线程 操作
 * pthread_create(tid, NULL, func, argv) 回调函数
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void printid(const char* tips)
{
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("%s :[pid = %u] [tid =  %u(%p)]\n", tips, pid, tid, tid);
    return;
}

void *thr_fun(void *argv)
{
    printid(argv);
    return NULL;
}

int main()
{
    pthread_t ntid;
    int ret = pthread_create(&ntid, NULL, thr_fun, "new  thread");
    if (ret){
        printf("create thread err,err:[%d],err_des:[%s]\n",ret, strerror(ret)); //strerror 来通过返回值错误码，来看错误原因
        exit(-1);
    }
    printid("main thread");
    pthread_join(ntid, NULL);
    return 0;
}