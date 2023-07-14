/**
 * 1、全缓冲 行缓冲 无缓冲
 * 2、进程控制块：进程控制块中有一个指针，指向files_struct（文件描述符表）：每个进程 是独立的 文件描述符表
 * 3、STDIN_FILENO STDOUT_FILENO STDERR_FILENO
 * 
 * 4、perror() //errno open函数出错之后，perror会把errno 对应的错误描述 打印出来。
 * 5、exit() //结束整个程序
 * 
 * 6、阻塞 非阻塞
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define P(fun) { \
	printf("%s = %d\n", #fun, fun); \
}

#define MAX_N (100)

void test_file(char *filename)
{
	int fd;
	// fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0644);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		perror("open");

	return;
}

int main(int argc, char *argv[])
{
	int fd, n;
	char buf[MAX_N + 5] = {0};

	if (argc != 2){
		printf("usage: process filename\n");
		return 0;
	}
	
	if ( (fd = open(argv[1], O_RDONLY)) != -1 ){
		printf(	"fd = %d, %s file open success!\n", fd, argv[1]);
		
		while ( (n = read(fd, buf, MAX_N)) != 0 )
		{
			printf("read %d bytes, file content is %s \n", n, buf);
		}
		
		close(fd); 
	}else{
		perror("open"); //errno open函数出错之后，perror会把errno 对应的错误描述 打印出来。
	}

//	test_file(argv[1]); //练习
	write(STDOUT_FILENO, buf, 10);

	P(STDIN_FILENO);
	P(STDOUT_FILENO);
	P(STDERR_FILENO);
    return 0;
}
