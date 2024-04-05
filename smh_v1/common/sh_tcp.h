/*************************************************************************
	> File Name: SmartHome_TCP.h
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Feb 2024 02:13:48 PM CST
 ************************************************************************/

#ifndef _SMARTHOME_TCP_H
#define _SMARTHOME_TCP_H

int socket_create(int port);
int socket_connect(const char *ip, int port);

#endif
