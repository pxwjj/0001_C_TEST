/**
 * fcntl opt
 * 修改已打开的文件的 属性
 * 
 * 先拿到当前文件的属性，再 加（|）上我要设置 的属性
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_N (100)

int main()
{
    int flags, n;
    char buf[MAX_N + 5] = {0};

    flags = fcntl(STDOUT_FILENO, F_GETFL);
    if( flags < 0 ){
        perror("GET flags");
        return 0;
    }

    flags |= O_NONBLOCK;
    flags = fcntl(STDOUT_FILENO, F_SETFL, flags);
    if( flags < 0 ){
        perror("SET flags");
        return 0;
    }

    int done = 1;
    while( done )
    {
        n = read(STDIN_FILENO, buf, MAX_N);

        if ( n < 0 && errno != EAGAIN ){
            perror("read");
            exit(-1);
        }

        if (n > 0){
            write(STDOUT_FILENO, buf, n);
            break;            
        }
        
        write(STDOUT_FILENO, "try try?\n", 10);
        sleep(3);
    }

    return 0;
}