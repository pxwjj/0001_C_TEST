/**
 * signal test
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int childpid;
    if ( (childpid = fork()) < 0){
        perror("fork");
        exit(-1);
    }

    if (childpid == 0){
        while (1){
            write(STDOUT_FILENO, "[child] hello STDOUT~\n", 23);
            sleep(1);
        }
    }else{
        int stat;
        sleep(7);
        if ( kill(childpid, SIGSEGV) < 0 ){
            perror("kill");
            wait(NULL);
            exit(-1);
        }
        waitpid(-1, &stat, 0);
        if ( WIFEXITED(stat) ){
            printf("[parent] my child process dead with [normal],exit code:[%d]\n", WEXITSTATUS(stat));
        }else if ( WIFSIGNALED(stat) ){
            printf("[parent] my child process dead with [signal],signal code:[%d]\n", WTERMSIG(stat));
        }
    }

    return 0;
}