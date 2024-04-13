/*************************************************************************
	> File Name: serverLog.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 07:11:26 PM CST
 ************************************************************************/

#include "../include/smhServer.h"

struct Server_info sv;

void serverLog(int level, const char *msg) {
    log_event(level, msg, sv.log_path);
    return ;
}
