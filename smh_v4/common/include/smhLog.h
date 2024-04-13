/*************************************************************************
	> File Name: smhLog.h
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 07:19:22 PM CST
 ************************************************************************/

#ifndef _SMHLOG_H
#define _SMHLOG_H
//SMH日志系统
#define LOG_LEVEL_INFO 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 2

void log_event(int level, const char *message, const char *filename);


#endif
