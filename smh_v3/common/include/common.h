/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:54:43 PM CST
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

#define LOG_LEVEL_INFO 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 2

extern char *conf_val;

int make_block(int fd);
int make_nonblock(int fd);
char *get_config_value(const char *file_path, const char *key);
void log_event(int level, const char *message, const char *filename);

#endif
