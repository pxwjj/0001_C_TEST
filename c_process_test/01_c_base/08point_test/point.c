/**
 * 指针 变量 存地址
*/

#include <stdio.h>

void output(int argc, char *argv[], char *env[])
{
    printf("argc = %d\n", argc);
    for (int i = 0; argv[i] != NULL; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    for (int j = 0; env[j] != NULL; j++)
        printf("env[%d] = %s\n", j, env[j]);
}

int main(int argc, char *argv[], char *env[])
{
    output(argc, argv, env);
    if(argv[2] == NULL)
        printf("argv[2] = %d\n", argv[2]);

    return 0;
}