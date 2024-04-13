/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:43:27 PM CST
 ************************************************************************/

#include "../include/smhClient.h"

struct Client_info cl;

//初始化客户端
__attribute__((constructor))
void init_client() {
    cl.server_ip = get_config_value(CONFIG, SIP);
    cl.server_port = atoi(get_config_value(CONFIG, SPORT));
    cl.log_path = get_config_value(CONFIG, LOGPATH);
    return ;
}


static int logIn() {
    

    return 0;
}

static int client_work() {
    
    return 0;
}

void run_client() {
    //启动客户端 
    int ret = client_work();
    if (ret < 0) {
        
    } 
    return ;
}


