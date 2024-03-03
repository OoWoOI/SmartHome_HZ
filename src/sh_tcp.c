/*************************************************************************
	> File Name: SmartHome_TCP.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Feb 2024 02:12:43 PM CST
 ************************************************************************/

#include "./common/head.h"

int socket_create(int port) {
    int sockfd;
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        // perror("socket");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("0.0.0.0");
    server.sin_port = htons(port);
    int reuse_val = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void *)&reuse_val, sizeof(int));
    //绑定sockfd与结构体空间
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        // perror("bind");
        return -1;
    }

    if (listen(sockfd, 20) < 0) {
       // perror("listen");
        return -1;
    }

    return sockfd;
}

int socket_connect(const char *ip, int port) {
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
       // perror("socket");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
     //   perror("connect");
        return -1;
    }

    return sockfd;
}

int socket_connect_timeout(const char *ip, const int port, const long timeout) {
    int sockfd; 

    
    return sockfd;
}
