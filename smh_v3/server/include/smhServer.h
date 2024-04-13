/*************************************************************************
	> File Name: smhServer.h
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 06:17:56 PM CST
 ************************************************************************/

#ifndef _SMHSERVER_H
#define _SMHSERVER_H

#include "../../common/include/smhHead.h"
#include "../../common/include/common.h"
#include "../../common/include/color.h"

#define CONFIG "./config/smhServer.ini"
#define SIP "SERVER_IP"
#define SPORT "SERVER_PORT"
#define RT "ROOT_USER"
#define RT_PWD "ROOT_PWD"
#define LOG "LOG_PATH"

struct Server_info {
    char *ip;
    int port;
    char *log_path;
};

struct Root_info {
    char *usrname;
    char *pwd;
};

struct Database_info {
    char *usrname;
    char *pwd;
};


extern struct Server_info sv;



void run_server();
void serverLog(int level, const char *msg);



#endif
