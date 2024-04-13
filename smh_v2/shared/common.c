/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Apr 2024 10:37:40 AM CST
 ************************************************************************/

#include <smh.h>

char *conf_val = NULL;

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
        free(conf_val);
    }
    fclose(fp);
    return conf_val;
}

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

void log_event(int level, const char *message, const char *filename) {
    time_t now = time(NULL);
    char *level_str;
    FILE *fp;
    switch (level) {
        case LOG_LEVEL_INFO: {
            level_str = "INFO";
        }break;
        case LOG_LEVEL_WARNING: {
            level_str = "WARNING";
        } break;
        case LOG_LEVEL_ERROR: {
            level_str = "ERROR";
        } break;
        default: {
            level_str = "UNKNOWN";
            break;
        }
    }
    
    if ((fp = fopen(filename, "a")) == NULL) {
        DBG(RED"fopen %s is ERROR!\n", filename);
        return ;
    }
    
    fprintf(fp, "%s [%s]: %s\n", ctime(&now), level_str, message);
    fclose(fp);
    return ;
}
