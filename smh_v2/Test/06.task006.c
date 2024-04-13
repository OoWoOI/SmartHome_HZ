/*************************************************************************
	> File Name: 05.task005.c
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Apr 2024 03:10:00 PM CST
 ************************************************************************/

#include <smh.h>

int main() {
    int port = 8080;
    int sockfd;
    if ((sockfd = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }
    
    int client;
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));//清空套接字地址结构体
    socklen_t addlen = sizeof(addr);

    while (1) {
        sleep(1); 
        client = accept(sockfd, (struct sockaddr *)&addr, &addlen);
        if (client > 0) break;
    }
    
    //接收和发送消息
    while (1) {
        char buff[1024] = {0};
        ssize_t recv_size = recv(client, buff, sizeof(buff), 0);
        if (recv_size <= 0) {
            if (recv_size == 0) continue;
            perror("recv");
            break;
        } 
        DBG(GREEN"Recv data : %s\n"NONE, buff);
        ssize_t send_size = send(client, buff, strlen(buff), 0);
        if (send_size <= 0) {
            perror("send");
            break;
        }
    }

    return 0;
}
