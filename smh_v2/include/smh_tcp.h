/*************************************************************************
	> File Name: smh_tcp.h
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Apr 2024 09:50:08 AM CST
 ************************************************************************/

#ifndef _SMH_TCP_H
#define _SMH_TCP_H

int socket_create(int port);
int socket_connect(const char *ip, int port);


#endif
