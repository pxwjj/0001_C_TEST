/**
 * client
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT (8000)
#define SERVER_IP "127.0.0.1"
#define MAX_LEN (100)

int main()
{
    int fd, n;
    struct sockaddr_in server_addr;
    char buf[MAX_LEN + 5] = {0};

    fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr); //pton 把字符串，转成 结构体中 的格式 类型。

    connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    while (scanf("%s", &buf) == 1)
    {
        n = write(fd, buf, strlen(buf));
        read(fd, buf, n);
        printf("%s\n", buf);
    }

    close(fd);

    return 0;
}