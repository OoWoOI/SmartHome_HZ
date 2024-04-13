/*************************************************************************
	> File Name: smh_client.h
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:40:11 PM CST
 ************************************************************************/

#ifndef _SMH_CLIENT_H
#define _SMH_CLIENT_H

#include "../../common/include/smhHead.h"
#include "../../common/include/common.h"
#include "../../common/include/color.h"
#include "../../common/include/log.h"



#define CONFIG "../config/client_config.ini"
#define SIP "SERVER_IP"
#define SPORT "SERVER_PORT"
#define LOGPATH "LOG_PATH"

struct Client_info {
    char *server_ip;
    int server_port;
    char *log_path;
};

extern struct Client_info cl;

void run_client();
#endif
