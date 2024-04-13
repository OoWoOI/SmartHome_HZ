/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:57:17 PM CST
 ************************************************************************/
#include "../include/smhHead.h"
#include "../include/common.h"
#include "../include/color.h"

char *conf_val = NULL;

//设置fd非阻塞IO
int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    
    flag |= O_NONBLOCK;
    
    return fcntl(fd, F_SETFL, flag);
}

//设置fd为阻塞IO
int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}


//获取配置文件信息
char *get_config_value(const char *path, const char *key) {
    FILE *fp = NULL;
    if ((fp = fopen(path, "r+")) == NULL) {
        DBG(RED"ERROR : fopen %s is failue !\n"NONE, path);
        return NULL;
    }
    size_t len = 0;
    while (getline(&conf_val, &len, fp) != -1) {
        if (strstr(conf_val, key) != NULL) {
            conf_val += strlen(key) + 1;
            conf_val[strlen(conf_val) - 1] = '\0';
            break;
        }
        memset(conf_val, 0, len);
    }
    fclose(fp);
    return conf_val;
}
