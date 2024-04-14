/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Apr 2024 02:17:22 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <locale.h>
#include "../include/server.h"
#include "../../common/include/smhConf.h"
#include "../../common/include/smhLog.h"
#include "../../common/include/smhUI.h"
#include "../include/handle.h"

extern Server *sv;
char *conf_val;

//初始化服务器，读取配置文件
static int init_server() {
    sv = (Server *)malloc(sizeof(Server));
    sv->db = (DataBase *)malloc(sizeof(DataBase));

    //端口
    sv->port = atoi(get_config_value(CONFPATH, "SERVER_PORT"));
    //数据库 
    sv->db->hostname = get_config_value(CONFPATH, "DB_HOSTNAME");
    sv->db->port = atoi(get_config_value(CONFPATH, "DB_PORT"));
    sv->db->usr = get_config_value(CONFPATH, "DB_USR");
    sv->db->pwd = get_config_value(CONFPATH, "DB_PWD");
    sv->db->db_name = get_config_value(CONFPATH, "DB_NAME");
    if (sv->db->port == 0 || sv->port == 0) return -1;
    if (!sv->db->hostname || !sv->db->usr || !sv->db->pwd || !sv->db->db_name) return -1;
    return 0;
}



int run_server() {
    if (init_server() < 0) {
        //日志
        log_event(LOG_LEVEL_ERROR, "获取配置信息失败!", LOGPATH);
        return -1;
    }
    //处理成功，服务端界面开启
    setlocale(LC_ALL, "");
    #ifndef _D
        //不能在_D下使用UI界面
        init_ui();
    #endif
    if (handle_event() < 0 ) {
        log_event(LOG_LEVEL_ERROR, "Server Handle ERROR !\n", LOGPATH);
        return -1;
    }
    return 0;
}

