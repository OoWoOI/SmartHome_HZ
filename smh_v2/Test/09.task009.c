/*************************************************************************
	> File Name: 09.task009.c
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Apr 2024 09:35:55 AM CST
 ************************************************************************/

#include<smh.h>

#define LOGPTH  "../data/log/smh.log"

int main() {
    //传入参数：LOG_LEVEL_INFO
    log_event(LOG_LEVEL_INFO, "测试日志系统是否正常", LOGPTH);
    return 0;
}
