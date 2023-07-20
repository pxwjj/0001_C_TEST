/**
 * 两个线程对同一个 全局变量加
 * 线程之间的资源竞争
 * 添加互斥锁 mutex
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t add_lock = PTHREAD_MUTEX_INITIALIZER;//互斥锁
int cnt = 0;
void *addcnt(void *arg)
{
    int val;
    for (int i = 0; i < 5000; i++){
        pthread_mutex_lock(&add_lock);
        val = cnt;                                           //相当与把这三行绑定到一起执行。
        printf("[cnt = %d]\t[%p]\n", cnt, pthread_self());
        cnt = val+1;
        pthread_mutex_unlock(&add_lock);
    }
    return NULL;
}

int main()
{
    pthread_t tida, tidb;
    pthread_create(&tida, NULL, addcnt, NULL);
    pthread_create(&tidb, NULL, addcnt, NULL);

    pthread_join(tida, NULL);
    pthread_join(tidb, NULL);
    return 0;
}