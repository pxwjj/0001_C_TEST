/**
 * 信号阻塞（信号屏蔽字）
 *  设置 信号集 sigset_t
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    sigset_t set, oldset;

    sigemptyset(&set); //初始化为空
    sigaddset(&set, SIGINT); //在集合中 添加 sigint 信号

    sigprocmask(SIG_BLOCK, &set, &oldset); //设置 阻塞信号集，把set设置进去，把原来的信号集， 返回出来

    sleep(10);

    sigprocmask(SIG_SETMASK, &oldset, NULL); //把之前的信号集，设置进去

    while (1)
        sleep(1);
    
    return 0;
}