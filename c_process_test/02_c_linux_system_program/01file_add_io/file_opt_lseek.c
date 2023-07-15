/**
 * lseek usage 
 * 返回 当前游标所在的位置
 * 错误的话返回-1 
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd, n;

    if (argc < 2){
        write(STDOUT_FILENO, "usage: cmd filename\n", 21);
        return 0;
    }
    
    if( (fd = open(argv[1], O_RDONLY | O_CREAT, 0644)) < 0 ){
        perror("open");
        return 0;
    }

    if ( (n = lseek(fd, 0, SEEK_END)) == -1 ){
        perror("lseek");
        close(fd);
        return 0;
    }
    
    printf("%s file bytes is %d\n", argv[1], n);
    close(fd);

    return 0;
}