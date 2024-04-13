/*************************************************************************
	> File Name: ../src/smhConf.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 08:18:18 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "../include/smhUtils.h"

extern char *conf_val;

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
