## 第 22 章TCP 的坚持定时器

### 22.1 引言

### 22.2 一个例子

sock 程序可以通过指定一个暂停选项 -P 使服务器在接受连接和进行第一次读动作之间进入休眠。

```bash
sock -i -s -P100000 5555
```

该命令在从网络上读数据之前休眠 100 000秒（2 7 . 8小时）。
客户运行在主机 b s d i上，并向服务器的 5 5 5 5端口执行 1 0 2 4字节的写操作。

编译执行服务端

```bash
gcc sockServ.c -o sockServ
./sockServ -i -s -P100000 5555 
```

编译执行客户端

```bash
gcc sockClient.c -o sockClient
./sockClient 127.0.0.1 5555
```