/*************************************************************************
	> File Name: sendMsg.c
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Apr 2024 03:03:31 PM CST
 ************************************************************************/

#include <string.h>
#include <ncurses.h>
#include "../../common/include/smhDatatype.h"
#include "../../common/include/smhUI.h"
extern int sockfd;
extern WINDOW *input_sub, *input_win;
extern struct SmhMsg chat_msg;

void sendMsg() {
    echo();
    nocbreak();
    bzero(chat_msg.msg, sizeof(chat_msg.msg));
    chat_msg.type = SMH_WALL;
    curs_set(1);
    w_gotoxy_puts(input_win, 1, 1, "Input Message : ");
    mvwscanw(input_win, 2, 10, "%[^\\n]s", chat_msg.msg);
    //判断如果读入的信息非空，则发送到服务端
    wclear(input_win);
    curs_set(0);
    box(input_win, 0, 0);
    wrefresh(input_win);
    noecho();
    cbreak();

}

