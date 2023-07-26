
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

#define SERVER_PORT (9000)
#define SERVER_IP "192.168.31.20"
#define MAX_LEN 100

int main()
{
    int fd, n;
    struct sockaddr_in server_addr;
    char buf[MAX_LEN + 5] = {0};

    fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr); //*

    connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    n = read(fd, buf, MAX_LEN);
    write(STDOUT_FILENO, buf, n);

    while ( scanf("%s", buf) == 1 ){
        if (strncmp(buf, "q", 1) == 0) break;
        
        n = write(fd, buf, strlen(buf));
        read(fd, buf, n);
        printf("toupper:%s\n", buf);
    }
    
    close(fd);   
    return 0;
}