/*************************************************************************
	> File Name: server.h
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Apr 2024 02:15:38 PM CST
 ************************************************************************/

#ifndef _SERVER_H
#define _SERVER_H


#define CONFPATH "../conf/server.ini"
#define LOGPATH "../logs/serevr.log"

typedef struct DataBase {
    char *hostname;
    int port;
    char *usr;
    char *pwd;
    char *db_name;
} DataBase;

typedef struct Server {
    int port;
    DataBase *db;
} Server;

int run_server();


#endif
