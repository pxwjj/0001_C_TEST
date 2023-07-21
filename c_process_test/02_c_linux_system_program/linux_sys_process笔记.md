1. **linux系统编程**
   1. 系统 会提供 让用户操作的 接口
   
   2. 用户空间（自己写的程序） 内核空间（os） 
   
   3. 用户程序，使用操作系统内核提供的接口（system call），去操作终端、网络等等就是系统编程。
   
   4. **特点**：
   
      1. 不跨平台
      2. 速度慢 用户空间到内核空间的切换需要时间
      3. 更加底层，功能很强很全面，接口更复杂
   
   5. **文件与IO**
   
      1. open read write close 和 fopen fgetc fputc fclose区别：内核函数不带缓冲区，clib中的函数带缓冲区（效率更高）。在网络编程时候，使用内核函数较好，满足实时变更内容。
   
      2. 进程控制块，进程控制块中有一个指针，指向files_struct（文件描述符表），fd就是文件描述符表中的某个下标。`STDIN_FILENO`0 `STDOUT_FILENO`1 `STDERR_FILENO`2
         1. 每个进程 是独立的 文件描述符表
         2. open 每次打开的文件描述符 都是文件描述符表中，未使用的最小的一个序号
   
      3. `perror() //errno open函数出错之后，perror会把errno 对应的错误描述 打印出来。`
   
      4. `fd = open(argv[1], O_RDWR | O_CREAT, 0666);`
   
      5. `close(fd);`
   
      6. read() 返回值：成功返回读取的字节数，出错返回-1，设置errno，如果在调用read之前已经到达文件末尾，则read返回 0；
         1. 从终端设备上读取内容，一般以换行符结束。
   
      7. write()
   
      8. 阻塞（block）和非阻塞
         1. 轮询（Poll）非阻塞read-->数据处理-->sleep-->非阻塞read-->... ...
   
      9. lseek() 移动游标
         1. `n = lseek(fd, 0, SEEK_END);`返回值n为当前游标所在位置，SEEK_END 为文件末尾，0为偏移， 最终游标所在位置是` 文件末尾+0`
         2. 函数出错 返回-1
   
      10. fcntl() 修改已打开的文件的 属性；先拿到当前文件的属性，再 加（|）上要设置 的属性
   
         1. ```c
                flags = fcntl(STDOUT_FILENO, F_GETFL);
                if( flags < 0 ){
                    perror("GET flags");
                    return 0;
                }
                  
                flags |= O_NONBLOCK;
                flags = fcntl(STDOUT_FILENO, F_SETFL, flags);
                if( flags < 0 ){
                    perror("SET flags");
                    return 0;
                }
            ```
   
      11. ioctl()
   
      12. mmap()
   
   6. **虚拟文件系统（vfs）**
   
      1. inode table
   
      2. data block
   
      3. ![image-20230717123839377](C:\Users\12721\AppData\Roaming\Typora\typora-user-images\image-20230717123839377.png)
   
      4. stat() 查看inode 信息
   
      5. dup(), dup2() 复制一个现存的文件描述符
   
         1. ```c
            /**
             * fd = dup(1)  相当于拷贝文件描述符 返回值 fd 为 1 的文件描述符
             * dup2(fd, fd1)  将fd1 原来的文件描述符关闭，让fd1指向 fd
            */
            0001_C_TEST/c_process_test/02_c_linux_system_program/01file_add_io/dupOpt.c
            ```
   
   7. **进程体系和进程管理**
   
      1. 进程控制块（pcb），task_struct 结构体
   
      2. 进程控制fork() ；复制进程：成功返回子进程号 失败返回-1
   
         1. 根据现有的进程复制一个新进程，进程控制块也一样（只有进程控制块中的pid不一样）
   
         2. ![image-20230718132413046](C:\Users\12721\AppData\Roaming\Typora\typora-user-images\image-20230718132413046.png)
   
         3. ```c
            int main()
            {
                __pid_t childpid;
                
                childpid = fork();
                if (childpid < 0){
                    perror("fork");
                    exit(-1);
                }
                
                if (childpid == 0){
                    child_process();
                }else{
                    mast_process();
                }
                
                printf("return\n");
                return 0;
            }
            ```
   
         4. getpid() getppid() 主进程想要得到子进程的id 只能在fork()的时候记录返回值；
   
         5. 孤儿进程 ：主进程运行三秒，子进程运行六秒；三秒之后主进程退出，子进程变成孤儿进程，此时孤儿进程的父进程变成systemd（systemd 进程号为1），6秒之后在子进程结束后，子进程的尸体被孤儿院(systemd进程)处理
   
         6. 僵尸进程：在UNIX系统中，一个进程结束了，但是其父进程没有等待（调用wait/waitpid）它，那么它将变成一个僵尸进程。通过PS命令可以查看其带有defunct的标志，**僵尸进程是一个早已死亡的进程，但在进程表中仍占据一个位置**
   
      3. 操作环境变量
   
         1. ```c
            int main(void)
            {
                extern char **environ;
                for (int i = 0; environ[i] != NULL; i++)
                    printf("[%d]:[%s]\n", i, environ[i]);
                
            
                printf("%s func usage, PATH = [%s]\n", __func__, getenv("PATH"));
                setenv("PATH", "hello", 1);
                printf("%s func usage, PATH = [%s]\n", __func__, getenv("PATH"));
                return 0;
            }
            ```
   
      4. exec族函数
   
         1. 只有出错返回值 没有成功返回值， 因为成功的话就被新程序替代了，执行新程序的代码
   
         2. ```c
            execlp("/usr/bin/ls", "ls", "-al", NULL);
            ```
   
      5. wait() waitpid() wait相当于收尸（回收子进程的资源）
   
         1. ```c
                if (childpid == 0){
                    int n = 5;
                    while (n){
                        printf("[child] process\n");
                        n--;
                        sleep(1);
                    }
                    exit(-1);
                }else{
                    int stat_val;
                    waitpid(-1, &stat_val, 0); //父进程会卡在这里等待 子进程死亡，并且 获取子进程的死亡信息
                    if (WIFEXITED(stat_val)){
                        printf("[child] normally exited,[code] = %d\n", WEXITSTATUS(stat_val));
                    }else if (WIFSIGNALED(stat_val)){
                        printf("[child] signal exited,[signal] = %d\n", WTERMSIG(stat_val));
                    }
                }
            ```
   
      6. 进程间通信(IPC)
   
         1. pipe()管道 `pipe(int fd[2]);//返回值为-1 则出错` fd[0] 是读端 fd[1]是写端
   
         2. ```c
            int main()
            {
                int fd[2] = {0};
                int childpid;
                if (pipe(fd) < 0){
                    perror("PIPE");
                    return 0;
                }
            
                if ( (childpid = fork()) < 0){
                    perror("FORK");
                    return 0;
                }
                
                if (childpid == 0){ //子进程 去 写
                    close(fd[0]);
                    sleep(1);
                    write(fd[1], "[child] hello,parent~\n", 23);
                }else{  //父进程 去 读
                    char buf[MAX_N] = {0};
                    int n, stat_val;
            
                    close(fd[1]);
                    n = read(fd[0], buf, MAX_N);
                    if( n < 0 ){
                        perror("READ");
                        waitpid(-1, &stat_val, 0);
                        exit(-1);
                    }
                    write(STDOUT_FILENO, buf, n);
                    waitpid(-1, &stat_val, 0);
                }
                
                return 0;
            }
            ```
   
         3. 有名管道 共享内存 消息队列 socket
   
   8. **信号**
   
      1. 产生信号 
   
         1. `kill(childpid, SIGSEGV)` 返回值为-1 则出错
   
      2. 阻塞信号
   
         1. pending 未决 block 阻塞
   
         2. ![image-20230719111608830](C:\Users\12721\AppData\Roaming\Typora\typora-user-images\image-20230719111608830.png)
   
         3. 信号集操作函数
   
            1. ```c
               /**
                * 信号阻塞集（信号屏蔽字）
                *  设置 信号集 sigset_t
               */
               int main()
               {
                   sigset_t set, oldset;
               
                   sigemptyset(&set); //初始化为空
                   sigaddset(&set, SIGINT); //在集合中 添加 sigint 信号
               
                   sigprocmask(SIG_BLOCK, &set, &oldset); //设置 阻塞信号集，把set加进原来的屏蔽集合中，把原来的信号集返回出来
               //SIG_BLOCK 把set 加进原来的集合
               //SIG_UNBLOCK 把set在原来的集合中减去
                   sleep(10);
               
                   sigprocmask(SIG_SETMASK, &oldset, NULL); //把之前的信号集，设置进去
               
                   while (1)
                       sleep(1);
                   
                   return 0;
               }
               ```
   
            2. sigpending()未决信号集
   
      3. 捕捉信号
   
         1.  信号抵达之后，执行，程序中规定的，获取到该信号的后续操作
   
         2. ```c
            void undead(int signo){
                printf("get signo[%d], you`re go dead\n", signo);
                return;
            }
            
            int main()
            {
                struct sigaction newact, oldact;
                newact.sa_handler = undead;
                newact.sa_flags = 0;
                sigemptyset(&newact.sa_mask);
            
                sigaction(SIGINT, &newact, &oldact);
                int n = 20;
                while (n > 0)
                {
                    sleep(1);
                    n--;
                }
                
                sigaction(SIGINT, &oldact, NULL);
            
                return 0;
            }
            ```
   
         3. 练习：父进程创建出子进程，子进程exit(2)终止，父进程自定义 SIGCHLD 信号的处理函数，在函数中调用wait获得子进程退出状态并打印（SIGCHLD信号 是子进程结束之后，给父进程发送的，默认处理是 忽略）
   
         ```c
         0001_C_TEST/c_process_test/02_c_linux_system_program/03signal_test/mulitprocess_signal.c
         ```
   
   9. **线程** 在一个进程中同时执行多个控制流程，操作系统能够进行运算调度的最小单位。
   
      1. 线程
   
         1. 同一个进程的多个线程共享同一个地址空间。定义一个函数，各线程都可以调用。 定义一个全局变量，在各线程中都可以访问。
         2. 栈区不共享，堆区共享， 全局区共享。
         3. -lpthread
   
      2. 线程控制
   
         1. `pthread_create(&tid, NULL, func, argv) 回调函数`在一个进程中创建一个线程，执行 func。pthread_create调用成功返回0，错误返回错误码。
         2. `pthread_self()`获得当前线程的id
         3. `pthread_exit()` 终止当前线程
         4. `pthread_join()`等待一个线程的结束，相当于waitpid收尸
         5. `pthread_cancel()`让某个线程结束
   
      3. 线程间同步
   
         1. 如果不控制线程，则会出现资源竞争 
   
         2. 互斥锁
   
         3. ```c
            pthread_mutex_t add_lock = PTHREAD_MUTEX_INITIALIZER;//互斥锁
            int cnt = 0;
            void *addcnt(void *arg)
            {
                int val;
                for (int i = 0; i < 5000; i++){
                    pthread_mutex_lock(&add_lock);
                    val = cnt;                                           //相当与把这三行绑定到一起执行。
                    printf("[cnt = %d]\t[%p]\n", cnt, pthread_self());
                    cnt = val+1;
                    pthread_mutex_unlock(&add_lock);
                }
                return NULL;
            }
            
            int main()
            {
                pthread_t tida, tidb;
                pthread_create(&tida, NULL, addcnt, NULL);
                pthread_create(&tidb, NULL, addcnt, NULL);
            
                pthread_join(tida, NULL);
                pthread_join(tidb, NULL);
                return 0;
            }
            ```