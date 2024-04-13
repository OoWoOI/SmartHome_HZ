/*************************************************************************
	> File Name: 01.task001.c
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Apr 2024 12:14:16 PM CST
 ************************************************************************/

#include <smh.h>

#define PTH "../data/config/server.conf"
#define IP "SERVER_IP"
#define PORT "SERVER_PORT"


int main() {
    char *val = NULL; 
    val = get_config_value(PTH, IP);
    DBG("%s", val);
    return 0;
}
