/**
 * 练习 （SIGCHLD信号 是子进程结束之后，给父进程发送的，默认处理是 忽略）
 * 
 * 父进程创建出子进程，子进程exit(2)终止，父进程自定义 SIGCHLD 信号的处理函数，在函数中调用wait获得子进程退出状态并打印
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void wait_for_child(int signo)
{
    int stat_val;
    printf("[father] I find my child dead, i wait() my child\n");

    waitpid(-1, &stat_val, 0);
    if (WIFEXITED(stat_val)){
        printf("[father]my child normally exited,[code] = %d\n", WEXITSTATUS(stat_val));
    }else if (WIFSIGNALED(stat_val)){
        printf("[father]my child signal exited,[signal] = %d\n", WTERMSIG(stat_val));
    }

    return;
}

void father_process()
{
    struct sigaction newact, oldact;
    newact.sa_handler = wait_for_child;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGCHLD, &newact, &oldact);

    while (1)
        sleep(2);
    
    return ;
}

void child_process()
{
    int done;
    done = 10;
    while ( done ){
        write(STDOUT_FILENO, "[child] I`m alive\n", 19);
        sleep(1);
        done--;
    }
    exit(2);
}

int main()
{
    pid_t childpid;

    if ( (childpid = fork()) < 0 ){
        perror("FORK");
        exit(-1);
    }

    if ( childpid ){
        father_process();
    }else{
        child_process();
    }
    
    return 0;
}