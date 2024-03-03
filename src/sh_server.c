/*************************************************************************
	> File Name: smarthome_server.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Feb 2024 02:58:10 PM CST
 ************************************************************************/

#include "../include/head.h"

void Usage(const char *argv0) {
    fprintf(stderr, "Usage : %s port!\n", argv0);
    return ;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        Usage(argv[0]);
        exit(1);
    }

    int server_listen, port, sockfd = 0;
    port = atoi(argv[1]);
    
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }
    
    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    socklen_t len = sizeof(client);
    if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");
            exit(1);
    }
    
    while (1) {
        char buff[1024] = {0};
        int ret = scanf("%s", buff);
        if(ret <= 0) {
            printf("未输入数据!\n");
            continue;
        }
        ssize_t rs = send(sockfd, buff, sizeof(buff) - 1, 0);
        if (rs <= 0) {
            perror("send");
            exit(1);
        }
        bzero(buff, sizeof(buff));
        ssize_t ws = recv(sockfd, buff, sizeof(buff) - 1, 0);
        if (ws <= 0) {
            perror("recv");
            exit(1);
        }
        printf("recv a msg : %s\n", buff);
    }
     
    
    return 0;
}
