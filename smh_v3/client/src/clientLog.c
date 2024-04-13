/*************************************************************************
	> File Name: clientLog.c
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Apr 2024 03:07:54 PM CST
 ************************************************************************/

#include "../include/smhClient.h"


struct Client_info cl;

void clientLog(int level, const char *msg) {
    log_event(level, msg, cl.log_path);
    return ;
}
