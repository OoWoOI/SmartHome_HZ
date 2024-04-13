/*************************************************************************
	> File Name: 005.testConf.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 08:22:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include "../include/smhConf.h"

char *conf_val;


int main() {
    char *path = "./005.testConf.ini";
    char *conf[] = {"SERVER_IP", "SERVER_PORT", "USER_NAME"};
    for (int i = 0; i < 3; i++) {
        conf_val = get_config_value(path, conf[i]);
        printf("%s = %s\n", conf[i], conf_val);
    }
    return 0;
}
