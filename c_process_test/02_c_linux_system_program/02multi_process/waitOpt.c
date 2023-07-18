/**
 * wait()  waitpid()
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    int childpid;

    childpid = fork();
    if (childpid < 0){
        perror("fork");
        return 0;
    }

    if (childpid == 0){
        int n = 10;
        while (n){
            printf("[child] process\n");
            n--;
            sleep(1);
        }
        exit(-1);
    }else{
        int stat_val;
        printf("child process id:[%d]\n", childpid);
        waitpid(-1, &stat_val, 0); //父进程会卡在这里等待 子进程死亡，并且 获取子进程的死亡信息
        if (WIFEXITED(stat_val)){
            printf("[child] normally exited,[code] = %d\n", WEXITSTATUS(stat_val));
        }else if (WIFSIGNALED(stat_val)){
            printf("[child] signal exited,[signal] = %d\n", WTERMSIG(stat_val));
        }
    }
    return 0;
}