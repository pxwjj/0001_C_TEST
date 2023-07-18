/**
 * pipe Opt
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_N (100)

int main()
{
    int fd[2] = {0};
    int childpid;
    if (pipe(fd) < 0){
        perror("PIPE");
        return 0;
    }

    if ( (childpid = fork()) < 0){
        perror("FORK");
        return 0;
    }
    
    if (childpid == 0){ //子进程 去 写
        close(fd[0]);
        sleep(1);
        write(fd[1], "[child] hello,parent~\n", 23);
    }else{  //父进程 去 读
        char buf[MAX_N] = {0};
        int n, stat_val;

        close(fd[1]);
        n = read(fd[0], buf, MAX_N);
        if( n < 0 ){
            perror("READ");
            waitpid(-1, &stat_val, 0);
            exit(-1);
        }
        write(STDOUT_FILENO, buf, n);
        waitpid(-1, &stat_val, 0);
    }
    
    return 0;
}