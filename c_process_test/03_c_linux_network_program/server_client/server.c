/**
 * server
 * ine
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

#define SERVER_PORT (8000)
#define MAX_LEN (100)

int main()
{
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t client_len;
    int listenfd, connfd;
    char src[16] = {0};
    char buf[MAX_LEN + 5] ={0};
    int n;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT); 
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    listen(listenfd, 3);
    printf("Accepting connections... ...\n");
    while (1){
        client_len = sizeof(clientaddr);
        connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &client_len);
        printf("client ip [%s], port [%d]\n", \
                    inet_ntop(AF_INET, &clientaddr.sin_addr, src, sizeof(src)), \
                        ntohs(clientaddr.sin_port)); //inet_ntop 结构体中 的格式，转成 字符串类型


        while ((n = read(connfd, buf, MAX_LEN)) == 0)
            sleep(1);
        
        for (int i = 0; i < n; i++)
            buf[i] = toupper(buf[i]);
        
        write(connfd, buf, n);

        close(connfd);
    }
    
    return 0;
}

//inet_ntop 将结构体中的内容转换成字符串。