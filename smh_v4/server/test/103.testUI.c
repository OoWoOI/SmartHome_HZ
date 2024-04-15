/*************************************************************************
	> File Name: 103.testUI.c
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Apr 2024 03:38:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>
#include <ncurses.h>
#include "../include/serverUI.h"

WINDOW *message_win, *message_sub;

int message_num = 0;

void clear_ui() {
    destroy_win(message_win);
    destroy_win(message_sub);
    endwin();
    return ;
}

int main() {
    setlocale(LC_ALL, "");   
    init_ui();
    sleep(10);
    clear_ui();
    return 0;
}
