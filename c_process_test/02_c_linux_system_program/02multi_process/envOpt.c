/**
 * env opt
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    extern char **environ;
    for (int i = 0 ;environ[i] != NULL ; i++)
        printf("[%d]:[%s]\n", i, environ[i]);
    

    printf("%s func usage, PATH = [%s]\n", __func__, getenv("PATH"));
    setenv("PATH", "hello", 1);
    printf("%s func usage, PATH = [%s]\n", __func__, getenv("PATH"));
    return 0;
}