/*************************************************************************
	> File Name: log.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 05:25:04 PM CST
 ************************************************************************/

#include "../include/smhHead.h"
#include "../include/log.h"
#include "../include/color.h"

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
