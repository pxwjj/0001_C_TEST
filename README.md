# 0001_C_TEST

- 配置 vim :https://github.com/amix/vimrc

- readelf
1. `readelf -S ./bin/a.out`

2. 查看a.out  是不是可以debug的程序。

3. 如果有 debug 等字段。表明可以debug 。

4. `readelf -p .debug_str ./bin/a.out`
   
   1. 可以看出 ./bin/a.out 的源码在哪个路径下面。
