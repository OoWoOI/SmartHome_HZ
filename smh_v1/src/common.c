/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Feb 2024 02:52:22 PM CST
 ************************************************************************/

#include "./common/head.h"

char *conf_val = NULL;

char *get_config_value(const char *config_file_path, const char *key) {
    FILE *fp = NULL;
    if ((fp = fopen(config_file_path, "r")) == NULL) {
        return NULL;
    }

    size_t len = 0;
    ssize_t nread = 0;
    char *buff = NULL;
    while ((nread = getline(&buff, &len, fp)) != -1) {
        if (strstr(buff, key) != NULL) {
            int key_size = strlen(key);
            conf_val = buff + (key_size + 2);
            //strncpy(conf_val, );
            conf_val = strdup(buff + (key_size + 1));
            free(buff);
            fclose(fp);
            return conf_val;
        } else {
            free(conf_val);
            conf_val = NULL;
        }
    }

    fclose(fp);
    return NULL;
}

void log_event(int level, const char* message, const char* filename) {
    time_t now = time(NULL);
    char* level_str;
    FILE* fp;

    switch(level) {
        case LOG_LEVEL_INFO:
            level_str = "INFO";
            break;
        case LOG_LEVEL_WARNING:
            level_str = "WARNING";
            break;
        case LOG_LEVEL_ERROR:
            level_str = "ERROR";
            break;
        default:
            level_str = "UNKNOWN";
            break;
    }
    fp = fopen(filename, "a");
    //ToDo；//确认是否正常打开
    if(fp != NULL) {
        fprintf(fp, "%s [%s]: %s\\n", ctime(&now), level_str, message);
        fclose(fp);
    }
}


int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag |= O_NONBLOCK; 
    return fcntl(fd, F_SETFL, flag);
}

int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}




