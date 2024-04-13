/*************************************************************************
	> File Name: smh_client.c
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Apr 2024 10:36:33 AM CST
 ************************************************************************/

#include<smh.h>
#include<smh_client.h>

struct Server sv;
int sockfd;

__attribute__((constructor))
void init_client() {
    //初始化客户端，并获取服务端的配置信息
    sv.ip = get_config_value(PATH, IP);
    sv.port = atoi(get_config_value(PATH, PORT));
    return ;
}

//连接服务器
static int connect_server() {
    
    return ;
}

//用户登录
static int usrLogin() {

    return ;
}

void run_client() {
    DBG("%s:%d\n", sv.ip, sv.port);
    if (connect_server() < 0) {
        DBG(RED"连接服务器失败!\n"NONE);
        return ;
    }//尝试连接服务器
    if (usrLogin() < 0){
        DBG(RED"用户登录失败!\n"NONE);
        return ;
    }//用户登录
    #ifndef _D
        init_ui();
    #endif
    
    return ;
}

