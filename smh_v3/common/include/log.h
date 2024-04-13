/*************************************************************************
	> File Name: log.h
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 05:22:50 PM CST
 ************************************************************************/

#ifndef _LOG_H
#define _LOG_H

#define LOG_LEVEL_INFO 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 2

void log_event(int level, const char *message, const char *filename);

#endif
