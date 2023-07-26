/**
 * server 将 client 输入的字符串，转成大写。
 * client可以一直写入，server端一直服务。

 * 多进程并发服务器：
 * 服务端可以开启多个进程，供多个客户端访问。父进程用于分配子进程。子进程用来处理业务。
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>

#define SERVER_PORT (9000)
#define MAX_LEN 100

#define perrexit(msg) { \
    perror(msg); \
    exit(-1); \
}

int  main()
{
    int sockfd, connfd, n;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char str[16] = {0}, buf[MAX_LEN + 5] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //*
    if (sockfd == -1)
        perrexit("socket");
    
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ( bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1 )  //*
        perrexit("bind");

    if ( listen(sockfd, 3) == -1 )  //*
        perrexit("listen");
    
    printf("listen ... ...\n");
    while (1){
        client_len = sizeof(client_addr);
        connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len); //*
        if (connfd == -1)
            perrexit("accept");
        
        printf("ip [%s]; port [%d]\n", \
                    inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)), \
                        ntohs(client_addr.sin_port));
        
        pid_t childpid = fork();
        if (childpid < 0)
            perrexit("fork");

        if (childpid){
            close(connfd);
            waitpid(-1, NULL, WNOHANG); //wait设置成非阻塞
            continue;
        }else{
            close(sockfd);
            write(connfd, "hello client, i`am server, you key in lower char, i can toupper it\n", 68);
        
            while ( (n = read(connfd, buf, MAX_LEN)) ){
                printf("%s\n", buf);
                if (strncmp(buf, "q", 1) == 0) break;
            
                for (int i = 0; i < n; i++)
                    buf[i] = toupper(buf[i]);
                write(connfd, buf, strlen(buf));
                bzero(buf, sizeof(buf));
            }
            close(connfd);
            exit(0);    
        }
    }
    
    return 0;
}