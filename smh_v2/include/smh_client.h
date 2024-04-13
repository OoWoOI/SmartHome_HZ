/*************************************************************************
	> File Name: smh_client.h
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Apr 2024 10:38:20 AM CST
 ************************************************************************/

#ifndef _SMH_CLIENT_H
#define _SMH_CLIENT_H

//define type

#define PATH "../data/config/server.conf"
#define IP "SERVER_IP"
#define PORT "SERVER_PORT"


//type of smh client
struct Server {
    char *ip;
    int port;
};


//func of smh client
void run_client();


#endif
