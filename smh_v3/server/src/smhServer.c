/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 06:25:47 PM CST
 ************************************************************************/

#include "../include/smhServer.h"

struct Server_info sv;
static struct Root_info rf;
static struct Database_info db;

//初始化服务器
__attribute__((constructor))
void init_server() {
    //获取配置信息
    sv.ip = get_config_value(CONFIG, SIP);
    sv.port = atoi(get_config_value(CONFIG, SPORT));
    sv.log_path = get_config_value(CONFIG, LOG);
    //Root用户
    rf.usrname= get_config_value(CONFIG, RT);
    rf.pwd = get_config_value(CONFIG, RT_PWD);
    //数据库信息
    
    return ;
}


//测试代码：测试颜色输出与日志信息
static void test() {
    
    return ; 
}

//服务端界面启动
static int server_ui() {
    fflush(stdout);
    DBG("启动服务端界面成功!\n");
    #ifndef _D
        
    #endif

    return 0;
}


//管理员登录
static int adminLogin() {
    char name[50] = {0}, pwd[50] = {0};
    //管理员提示登录
    printf("账号：");
    scanf("%s", name);
    printf("密码：");
    scanf("%s", pwd);
    if (strcmp(name, rf.usrname) != 0 || strcmp(pwd, rf.pwd) != 0) return -1;
    return 0;
}

//服务器主要业务逻辑
static int server_work() {
    
    while (1) {
        if (adminLogin() < 0) {
            //管理员登录失败
            serverLog(LOG_LEVEL_INFO, "账号或密码错误!");
            continue;
        }
        int ret = server_ui();//登录成功
        if (ret < 0) return -1;
    }
    return 0;
}

//启动服务器
void run_server() {
    int ret = 0;
    ret = server_work();
    if (ret < 0) 
        serverLog(LOG_LEVEL_ERROR, "SERVER IS ERROR");//输出日志信息
    return ;
}


