/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Feb 2024 02:08:58 PM CST
 ************************************************************************/

#include "../include/head.h"

void Usage(const char *argv0) {
    fprintf(stderr, "Usage : %s ip port!\n", argv0);
    return ;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        Usage(argv[0]);
        exit(1);
    }
    
    int sockfd, port;
    char ip[20] = {0};
    port = atoi(argv[2]);
    strcpy(ip, argv[1]);//复制传入的ip
    
    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connect");
        exit(1);
    }
    
    struct UserInfo usr;
    strcpy(usr.name, "王冬冬");
    strcpy(usr.phone, "13896721945");
    
    while (1) {
        char buff[1024] = {0};
        ssize_t rsize = recv(sockfd, buff, sizeof(buff) - 1, 0);
        if (rsize <= 0) {
            perror("recv");
            break;
        }
        printf("%s\n", buff);
        int opt = atoi(buff);
        switch (opt) {
            case 1: {
                ssize_t send_size = send(sockfd, usr.phone, sizeof(usr.phone), 0);
                if (send_size <= 0) {
                    perror("send");
                }
                break;
            }
            case 2: {
                ssize_t send_size = send(sockfd, usr.name, sizeof(usr.name), 0);
                if (send_size <= 0) {
                    perror("send");
                }
                break;
            }
            case 3: {
                ssize_t send_size = send(sockfd, &usr, sizeof(struct UserInfo), 0);
                if (send_size <= 0) {
                    perror("send");  
                }
                break;
            }
            case 4: {
                printf("关闭连接!\n");
                close(sockfd);
                break;
            }
            default: {

                break;
            }
        }
    }

    return 0;
}
