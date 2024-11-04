//
// Created by xjgc on 2024/11/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

/**
 * 客户运行在主机上，并向服务器的 5 5 5 5端口执行 1 0 2 4字节的写操作。
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {

    int cli_sock;
    struct sockaddr_in cli_addr;
    int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    if (3 != argc) {
        fprintf(stderr, "Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    if (0 > (cli_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))) {
        perror("socket() failed");
        exit(1);
    }

    memset(&cli_addr, 0, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    if(0 > inet_aton(argv[1], &cli_addr.sin_addr)) {
        perror("inet_aton() failed");
        exit(1);
    }
    cli_addr.sin_port = htons(atoi(argv[2]));

    if (0 > connect(cli_sock, (struct sockaddr*)&cli_addr, sizeof(cli_addr))) {
        perror("connect() failed");
        exit(1);
    }

    // 向服务器写入 1024 字节的数据
    memset(buffer , '*', BUFFER_SIZE);
    if (0 > write(cli_sock, buffer, BUFFER_SIZE)) {
        perror("write() failed");
        exit(1);
    }

    close(cli_sock);
}
