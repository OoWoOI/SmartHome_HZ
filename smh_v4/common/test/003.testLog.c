/*************************************************************************
	> File Name: 003.testLog.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 07:58:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include "../include/smhLog.h"
int main() {
    char filename[] = "./003.testLog.log";
    char msg[] = "测试日志系统";
    log_event(LOG_LEVEL_INFO, msg, filename);
    return 0;
}
