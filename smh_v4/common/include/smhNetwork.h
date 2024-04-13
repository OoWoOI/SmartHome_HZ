/*************************************************************************
	> File Name: smhNetwork.h
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 08:34:01 PM CST
 ************************************************************************/

#ifndef _SMHNETWORK_H
#define _SMHNETWORK_H
//监听套接字实现
int socket_create(int port);

//网络连接请求
int socket_connect(const char *ip, int port);

#endif
