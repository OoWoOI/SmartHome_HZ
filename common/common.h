/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Feb 2024 02:46:56 PM CST
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H


#define DEFARG(name, default_value) ((#name[0]) ? (name + 0) : default_value)
extern WINDOW *message_sub;
#define Show_Message(arg0, arg1, arg2, arg3) show_message(DEFARG(arg0, message_sub), DEFARG(arg1, NULL), arg2, DEFARG(arg3, 0))

#define LOG_LEVEL_INFO 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 2


int make_nonblock(int fd);
int make_block(int fd);
void log_event(int level, const char *message, const char *filename);
char *get_config_value(const char * config_file_path, const char *key);

#endif
