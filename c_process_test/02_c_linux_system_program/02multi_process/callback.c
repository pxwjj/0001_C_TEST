/**
 * 类似重定向
 * 更改 标准输入 和 标准输出
 * 
 * dup2 的使用 以及 exec 族函数的使用
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("usage: cmd inputfile outputfile\n");
        exit(-1);
    }
    int fd;

    if ( (fd = open(argv[1], O_RDONLY)) < 0 ){
        perror("OPEN");
        exit(-1);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);

    if ( (fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0 ){
        perror("OPEN");
        exit(-1);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);

    execl("./toupper", "", NULL);
    perror("EXEC");
    return 0;
}