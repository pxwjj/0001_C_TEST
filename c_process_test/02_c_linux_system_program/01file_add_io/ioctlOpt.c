/**
 * 
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    struct winsize size;

    if (!isatty(1))
    {
        printf(" 1 is no tty\n");
        exit(1);
    }
    
    if(ioctl(1, TIOCGWINSZ, &size) < 0 )
    {
        perror("ioctl");
        exit(1);        
    }
    printf("terminals rows is %d, columns is %d\n", size.ws_row, size.ws_col);
    return 0;
}