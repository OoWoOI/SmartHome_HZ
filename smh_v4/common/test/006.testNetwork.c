/*************************************************************************
	> File Name: 006.testNetwork.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 08:42:37 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include <string.h>
#include "../include/smhNetwork.h"

//测试创建监听套接字，实现一个简单的echo服务器
void testListen() {
    int server_listen = socket_create(8080);
    if (server_listen < 0) {
        perror("socket_create");
        return ;
    }
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    int cli_fd;
    memset(&cli_addr, 0, cli_len);
    cli_fd = accept(server_listen, (struct sockaddr *)&cli_addr, &cli_len);
    if (cli_fd < 0){
        perror("accept");
        return ;
    }
   
    printf("连接成功\n");
    while (1) {
        char buff[1024] = {0};
        ssize_t recv_size = recv(cli_fd, buff, sizeof(buff), 0);
        if (recv_size < 0) {
            perror("recv_size");
            return ;
        }
        if (recv_size == 0) {
            printf("disconnect\n");
            break;
        }
        printf("recv [%lu] : %s\n", recv_size, buff);
        send(cli_fd, buff, strlen(buff), 0);//传输信息
    }

    return ;
}

//测试连接远程服务
void testConnect() {
    char ip[20] = "47.92.209.244";
    int port = 22;
    int sockfd;
    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connect");
        return ;
    }
    printf("connect to %s:%d successfully!\n", ip, port);
    return ;
}

int main() {
    
    testConnect();
    return 0;
}
