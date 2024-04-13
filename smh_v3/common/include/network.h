/*************************************************************************
	> File Name: network.h
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 05:09:09 PM CST
 ************************************************************************/

#ifndef _NETWORK_H
#define _NETWORK_H


//网络连接
int socket_create(int port);
int socket_connect(const char *ip, const int port);


#endif
