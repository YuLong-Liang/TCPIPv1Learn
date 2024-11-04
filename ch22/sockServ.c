//
// Created by xjgc on 2024/11/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <netinet/in.h>
#include <string.h>

/**
 * sock -i -s -P100000 5555
 * 该命令在从网络上读数据之前休眠 100 000秒（2 7 . 8小时）,并在端口 5555 上监听连接
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    int sleep_time = 0;
    int ser_port = 0;
    struct sockaddr_in serv_addr;
    int serv_sock;

    if (5 != argc) {
        fprintf(stderr, "Usage: %s -i -s -Pxxxx <port>\n", argv[0]);
        exit(1);
    }

    sleep_time = atoi(argv[3] + 2);
    ser_port = atoi(argv[4]);

    if (0 > socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) {
        perror("socket() failed");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(ser_port);

    if (0 > bind(serv_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) {
        perror("bind() failed");
        exit(1);
    }

    if (0 > listen(serv_sock, 5)) {
        perror("listen() failed");
        exit(1);
    }

    printf("Listening on port %d\n", ser_port);
    sleep(sleep_time);
    close(serv_sock);

    return 0;
}