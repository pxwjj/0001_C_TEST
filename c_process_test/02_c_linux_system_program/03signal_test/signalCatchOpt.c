/**
 * 信号捕捉
 *  信号抵达之后，执行，程序中规定的，获取到该信号的后续操作
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void undead(int signo){
    printf("get signo[%d], you`re go dead\n", signo);
    return;
}

int main()
{
    struct sigaction newact, oldact;
    newact.sa_handler = undead;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGINT, &newact, &oldact);
    int n = 20;
    while (n > 0)
    {
        sleep(1);
        n--;
    }
    
    sigaction(SIGINT, &oldact, NULL);

    return 0;
}