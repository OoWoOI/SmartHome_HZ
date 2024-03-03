/*************************************************************************
	> File Name: send_chat.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Mar 2024 06:39:51 PM CST
 ************************************************************************/

#include "./common/head.h"

extern int sockfd;
extern WINDOW *input_sub, *input_win;
extern struct User user;
extern struct SmhMsg chat_msg;

void send_chat() {
    echo();
    nocbreak();
    bzero(chat_msg.msg, sizeof(chat_msg.msg));
    chat_msg.type = SMH_WALL;
    curs_set(1);
    w_gotoxy_puts(input_win, 1, 1, "Input Message : ");
    mvwscanw(input_win, 2, 10, "%[^\n]s", chat_msg.msg);
    //判断如果读入的信息非空，则发送到服务端
    if (strlen(chat_msg.msg)) {
        struct SmhMsg tmpmsg;
        bzero(&tmpmsg, sizeof(struct SmhMsg));//清空内存
        strcpy(tmpmsg.msg, chat_msg.msg);
        tmpmsg.ctl = parse_ctl(tmpmsg.msg);//解析参数
        if (tmpmsg.ctl.action == -1) {
            tmpmsg.type = SMH_WALL;
        } else {
            tmpmsg.type = SMH_CTL;
        }
        int rsize =  send(sockfd, &tmpmsg, sizeof(struct SmhMsg), 0);
    }
    wclear(input_win);
    curs_set(0);
    box(input_win, 0, 0);
    wrefresh(input_win);
    noecho();
    cbreak();
}

struct Ctl parse_ctl(char *ctl_str) {
    struct Ctl ctl;
    bzero(&ctl, sizeof(ctl));//清空ctl的内存
    char *instruction = strtok(ctl_str, " ");
    if (instruction == NULL) {
        ctl.action = -1;
        return ctl;
    }
    if (strcmp(instruction, "#1") == 0) {
        ctl.action = ACTION_GET_DEVICES;
    } else if (strcmp(instruction, "#21") == 0) {
        ctl.action = ACTION_UPDATE_DEVICE;
        char *dev_id_str = strtok(NULL, " ");
        if (dev_id_str == NULL) {
            ctl.action = -1;
            return ctl;
        }
        ctl.dev.device_id = atoi(dev_id_str);
        ctl.dev.state = DEVICE_STATE_ON;
    } else if (strcmp(instruction, "#22") == 0) {
        ctl.action = ACTION_UPDATE_DEVICE;
        char *dev_id_str = strtok(NULL, " ");
        if (dev_id_str == NULL) {
            ctl.action = -1;
            return ctl;
        }
        ctl.dev.device_id = atoi(dev_id_str);
        ctl.dev.state = DEVICE_STATE_OFF;
    } else if (strcmp(instruction, "#23") == 0) {
        ctl.action = ACTION_UPDATE_DEVICE;
        char *dev_id_str = strtok(NULL, " ");
        if (dev_id_str == NULL) {
            ctl.action = -1;
            return ctl;
        }
        ctl.dev.device_id = atoi(dev_id_str);
        ctl.dev.state = DEVICE_STATE_STANDBY;
    } else if (strcmp(instruction, "#31") == 0) {
        ctl.action = ACTION_ADD_DEVICE;
        ctl.dev.type = DEVICE_LIGHT;
        char *dev_name = strtok(NULL, " ");
        if (dev_name == NULL) {
            ctl.action = -1;
            return ctl;
        }
        strncpy(ctl.dev.device_name, dev_name, sizeof(ctl.dev.device_name) - 1);
    } else if (strcmp(instruction, "#32") == 0) {
        ctl.action = ACTION_ADD_DEVICE;
        ctl.dev.type = DEVICE_SWITCH;
        char *dev_name = strtok(NULL, " ");
        if (dev_name == NULL) {
            ctl.action = -1;
            return ctl;
        }
        strncpy(ctl.dev.device_name, dev_name, sizeof(ctl.dev.device_name) - 1);
    } else if (strcmp(instruction, "#33") == 0) {
        ctl.action = ACTION_ADD_DEVICE;
        ctl.dev.type = DEVICE_THERMOSTAT;
        char *dev_name = strtok(NULL, " ");
        if (dev_name == NULL) {
            ctl.action = -1;
            return ctl;
        }
        strncpy(ctl.dev.device_name, dev_name, sizeof(ctl.dev.device_name) - 1);
    } else if (strcmp(instruction, "#4") == 0) {
        ctl.action = ACTION_DEL_DEVICE;
        char *dev_id_str = strtok(NULL, " ");
        if (dev_id_str == NULL) {
            ctl.action = -1;
            return ctl;
        }
        ctl.dev.device_id = atoi(dev_id_str);
    } else {
        ctl.action = -1;
    }
    return ctl;
}
