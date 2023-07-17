/**
 * fd = dup(1)  相当于拷贝文件描述符 返回值 fd 为 1 的文件描述符
 * dup2(fd, fd1)  将fd1 原来的文件描述符关闭，让fd1指向 fd
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void change_stdout_fd(char *filename)
{   
    int fd, save_fd;
    if((fd = open(filename, O_RDWR)) < 0){ //fd 3
        perror("OPEN");
        exit(-1);
    }
    save_fd = dup(1); //save_fd 4

    dup2(fd, 1); //标准输出 变成 打开的文件
    close(fd); //把 3 关了

    return;
}

void write_test()
{
    write(1, "hello, i just want write to stdout ,but stdout be change,so key in file\n", 73); //在文件中显示出来
    write(4, "you can key in stdout\n", 23);   //在标准输出中显示出来

    return;
}
int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("usage : cmd filename \n");
        return 0;
    }

    change_stdout_fd(argv[1]);
    write_test();

    return 0;
}