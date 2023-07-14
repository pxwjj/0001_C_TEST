#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_N (100)

void mycat(char *filename)
{
    char str[MAX_N + 5] = {0};
    int fd, n;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1){
        perror("open file");
        exit(-1);
    }
    
    while ( (n = read(fd, str, MAX_N)) != -1 ){
        if ( n == 0 ){
            write(STDOUT_FILENO, "EOF\n", 5);
            break;
        }
        
        write(STDOUT_FILENO, str, n);
    }
    // perror("read");
    close(fd);

    return ;
}

void mycp(char *filename1, char *filename2)
{
    char str[MAX_N + 5] = {0};
    int fd1, fd2, n;
    
    fd1 = open(filename1, O_RDONLY);
    if (fd1 == -1){
        perror("open file");
        exit(-1);
    }
    
    fd2 = open(filename2, O_WRONLY | O_CREAT, 0644);
    if (fd2 == -1){
        perror("open file");
        exit(-1);
    }

    while ( (n = read(fd1, str, MAX_N)) != -1 ){
        if ( n == 0 )
            break;
        
        write(fd2, str, n);
    }
    // perror("read");
    close(fd1); 
    close(fd2); 

    return ;
}

int main(int argc, char *argv[])
{
    /*
    if ( argc != 2 ){
        write(STDOUT_FILENO, "usage:mycat filename\n", 22);
        exit(-1);
    }

    mycat(argv[1]); */

    /*
    if ( argc != 3 ){
        write(STDOUT_FILENO, "usage:mycp filename filename\n", 30);
        exit(-1);
    }

    mycp(argv[1], argv[2]); */

    return 0;
}