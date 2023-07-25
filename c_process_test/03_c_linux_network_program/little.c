/**
 * 主机字节序转换成 网网络字节序
 * htonl ntohl
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main()
{
    int a = 0X12345678;
    int biga, littlea;

    biga = htonl(a);
    printf("big:[%#x]\n", biga);
    littlea = ntohl(biga);
    printf("little:[%#x]\n", littlea);

    return 0;
}