/**
 * 多进程
 * fork() 复制进程：成功返回子进程号 失败返回-1
 * 
 * 孤儿进程 ：主进程运行三秒，子进程运行六秒；三秒之后主进程退出，子进程变成孤儿进程，此时孤儿进程的父进程变成systemd（systemd 进程号为1），6秒之后在子进程结束后，子进程的尸体被孤儿院(systemd进程)处理
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int done_child, done_parent;

void guer_test(){  //孤儿进程
    done_child = 6;
    done_parent = 3;
}

void child_process()
{
    char *message = "";
    while (done_child){
        printf("I am child process~\n");
        done_child--;
        sleep(1);
    }
    
    return ;
}

void mast_process()
{
    char *message = "";
    while (done_parent){
        printf("I am mast process~\n");
        done_parent--;
        sleep(1);
    }
    
    return ;
}

void muiltiprocess() //创建10个子进程，并打印pid 和 ppid
{
    __pid_t childpid;
    int i;
    for (i = 0; i < 10; i++){
        childpid = fork();
        if (childpid < 0){
            perror("fork");
            exit(-1);
        }

        if (childpid == 0){
            printf("I am child %d,my id is %d, my father`s id is %d\n", i, getpid(), getppid());
            break;
        }else{
            sleep(1);
            continue;
        }
    }
    if (i < 10)
        printf("child %d exit\n", i);

    return;
}

int main()
{
    muiltiprocess();

/*
    __pid_t childpid;

    guer_test();
    
    childpid = fork();
    if (childpid < 0){
        perror("fork");
        exit(-1);
    }
    
    if (childpid == 0){
        child_process();
    }else{
        mast_process();
    }
    
    printf("return\n");
*/
    return 0;
}
