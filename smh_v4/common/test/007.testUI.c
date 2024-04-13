/*************************************************************************
	> File Name: 007.testUI.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 10:54:06 PM CST
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <pthread.h>
#include <unistd.h>
#include "../include/smhDatatype.h"
#include "../include/smhUI.h"


int server_port = 0;
char server_ip[20] = {0};
char *conf = "./smh.conf";
int sockfd = -1;
struct SmhMsg chat_msg;
struct SmhMsg ctl_msg;
int show_name = 0;
char data_stream[20] = {0};
WINDOW *message_win, *message_sub,  *info_win, *input_win, *info_sub;
int message_num = 0;

void logout(int signum) {
  //客户端退出函数，请使用自己的
}

void *client_recv() {
    sleep(10);
    destroy_win(message_win);
    destroy_win(message_sub);
    destroy_win(info_win);
    destroy_win(input_win);
    destroy_win(info_sub);
    return NULL;
}


int main(int argc, char **argv) {
    setlocale(LC_ALL,"");
#ifndef _D
    init_ui();
#endif
    pthread_t recv_t;
    pthread_create(&recv_t, NULL, client_recv, NULL);
	sleep(100);
    return 0;
}

