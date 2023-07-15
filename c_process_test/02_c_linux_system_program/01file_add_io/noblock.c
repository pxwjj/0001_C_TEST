/**
 * 非阻塞
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_N (100)

void poll_test()
{
    char buf[MAX_N + 5] = {0};
    int n, fd;
    int done = 1;

    fd = open("/dev/tty", O_RDWR | O_NONBLOCK);
    if ( fd < 0 ){
        perror("open /dev/tty");
        exit(-1);
    }

    while ( done )
    {
        n = read(fd, buf, MAX_N);
        if ( errno != EAGAIN ){
            perror("read /dev/tty");
            exit(-1);
        }
        
        if ( n > 0 ){
            printf("read %d bytes, is:", n);
            write(STDOUT_FILENO, buf, n);
            break;
        }
        write(STDOUT_FILENO, "try try?\n", 9);
        sleep(5);
    }

    return;
}

int main()
{
    poll_test();

    return 0;
}