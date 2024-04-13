/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Apr 2024 09:49:11 AM CST
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H


//Log define
#define LOG_LEVEL_INFO 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 2


char *get_config_value(const char *, const char *);
int make_nonblock(int );
int make_block(int );
void log_event(int , const char *, const char*);

#endif
