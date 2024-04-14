/*************************************************************************
	> File Name: handle.c
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Apr 2024 04:05:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../common/include/smhDatatype.h"
#include "../../common/include/smhNetwork.h"
#include "../../common/include/smhLog.h"
#include "../include/server.h"


#define MAX_EVENTS 1000

typedef int (*EventHandler)(int);

struct Server *sv;
static int epollfd;//epoll实例文件描述符

//服务器连接处理，将建立连接的套接字，
//注册到epoll实例中去，根据事件驱动模式，在从反应堆中完成功能逻辑
int handle_accept(int sockfd) {
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    int clientfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);
    if (clientfd < 0) {
        log_event(LOG_LEVEL_ERROR, "accept 获取连接失败", LOGPATH);
        close(clientfd);
        return -1;
    }

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = clientfd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &event) < 0) {
        log_event(LOG_LEVEL_ERROR, "Handle_accept epollfd_ctl error", LOGPATH);
        close(clientfd);
        return -1;
    }
    log_event(LOG_LEVEL_INFO, "Accept connect a new client success", LOGPATH);
    return 0;
}

//handle_message控制信息，接收来自客户端的信息，并定时发送心跳信息
//根据接受的信息，完成对相应功能需求的响应。
int handle_message(int fd) {
    //获取客户端传来的数据
    struct SmhMsg msg;
    memset(&msg, 0, sizeof(msg));//清空msg中的内存。
    size_t recvSize = recv(fd, &msg, sizeof(msg), 0);

    if (recvSize < 0) {
        log_event(LOG_LEVEL_ERROR, "数据读取失败~~~", LOGPATH);
        close(fd);
        return -1;
    }

    if (recvSize == 0) {
        log_event(LOG_LEVEL_INFO, "one client disconnected\n", LOGPATH);
        close(fd);
        return -1;
    }
    //数据获取成功，解析数据


    return 0;
}

//handle_event
//处理服务端的业务逻辑，创建socket套接字，注册监听事件，
//为了增大服务器的吞吐量，使用epoll监听套接字，采用事件驱动的模式，
//将主要业务逻辑分为连接处理，信息处理模式，使用简单的主从反应堆模式
int handle_event() {
    int server_listen;
    int epollfd;
    struct epoll_event event;

    //获取网络连接套接字
    server_listen = socket_create(sv->port);
    if (server_listen < 0) {
        log_event(LOG_LEVEL_ERROR, "server_listen 创建失败~~~~", LOGPATH);
        return -1;
    }

    //创建epoll实例
    epollfd = epoll_create1(0);

    if (epollfd < 0) {
        log_event(LOG_LEVEL_ERROR, "epollfd 创建失败~~~", LOGPATH);
        return -1;
    }

    event.events = EPOLLIN;
    event.data.fd = server_listen;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &event) < 0) {
        log_event(LOG_LEVEL_ERROR,  "添加server_listen到epoll实例中失败~~~", LOGPATH);
        return -1;
    }

    EventHandler handlers[] = {handle_accept, handle_message};//主从模式

    while (1) {
        struct epoll_event events[MAX_EVENTS];
        int numEvents = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (numEvents < 0) {
            log_event(LOG_LEVEL_ERROR, "epoll_wait failed", LOGPATH);
            return -1;
        }
        for (int i = 0; i < numEvents; i++) {
            int fd = events[i].data.fd;
            if (fd == server_listen) {
                //异常处理
                if (handlers[0](server_listen) < 0) {
                    return -1;
                }
            } else {
                //异常处理
                if (handlers[1](fd) < 0) {
                    return -1;
                }
            }
        }
    }

    return 0;
}
