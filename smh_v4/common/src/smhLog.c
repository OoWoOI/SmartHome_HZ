/*************************************************************************
	> File Name: smhLog.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 07:22:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include "../include/smhLog.h"
#include "../include/smhUtils.h"

void log_event(int level, const char *message, const char *filename) {
    time_t now = time(NULL);
    char *level_str;
    FILE *fp;
    switch (level) {
        case LOG_LEVEL_INFO: {
            DBG(GREEN"%s\n"NONE, message);
            level_str = "INFO";
        }break;
        case LOG_LEVEL_WARNING: {
            DBG(YELLOW"%s\n"NONE, message);
            level_str = "WARNING";
        } break;
        case LOG_LEVEL_ERROR: {
            DBG(RED"%s\n"NONE, message);
            level_str = "ERROR";
        } break;
        default: {
            DBG("%s\n", message);
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

