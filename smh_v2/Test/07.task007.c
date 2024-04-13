/*************************************************************************
	> File Name: 07.task007.c
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Apr 2024 04:02:24 PM CST
 ************************************************************************/

#include <smh.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s ip port!\\n", argv[0]);
        exit(1);
    }
    char ip[20] = {0};
    int port = atoi(argv[2]);
    strcpy(ip, argv[1]);
    int sockfd;
    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connect");
        exit(1);
    }
    DBG(GREEN"connect to %s:%d successfully!\\n"NONE, ip, port);
}

