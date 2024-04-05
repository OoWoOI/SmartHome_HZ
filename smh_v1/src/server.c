/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Mar 2024 03:13:58 PM CST
 ************************************************************************/

#include "./common/head.h"

int main(int argc, char **argv) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port !\n", argv[0]);
        exit(1);
    }

    int server_listen, port;

    port = atoi(argv[1]);

    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }
    int sockfd;
    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    socklen_t len = sizeof(client);
    if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");
            exit(1);
    }
    
    struct LogRequest lreq;
    struct LogResponse lrep;
    ssize_t lrep_len = sizeof(lrep);
    ssize_t lreq_len = sizeof(lreq);
    bzero(&lrep, lrep_len);
    bzero(&lreq, lreq_len);
    
    ssize_t recv_size = recv(sockfd, &lreq, lreq_len, 0);

    if (recv_size <= 0) {
        perror("recv");
        exit(1);
    }
    
    printf("%s : %s\n", lreq.name, lreq.msg);
     
    lrep.type = 1;
    strcpy(lrep.msg, "hi");
    ssize_t send_size = send(sockfd, &lrep, lrep_len, 0);
    if (send_size <= 0) {
        perror("send");
        exit(1);
    }
    close(sockfd);
    close(server_listen);
    return 0;
}
