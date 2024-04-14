/*************************************************************************
	> File Name: smhUI.h
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 10:05:37 PM CST
 ************************************************************************/

#ifndef _SMHUI_H
#define _SMHUI_H

#define DEFARG(name, default_value) ((#name[0]) ? (name + 0) : default_value)
extern WINDOW *message_sub;
#define Show_Message(arg0, arg1, arg2, arg3) show_message(DEFARG(arg0, message_sub), DEFARG(arg1, NULL), arg2, DEFARG(arg3, 0))

/**
#define MSG_WIDTH 80
#define INFO_WIDTH 10
#define MSG_HEIGHT 10
#define INPUT_HEIGHT 5
**/

void destroy_win(WINDOW *win);
void gotoxy(int x, int y);
void gotoxy_putc(int x, int y, int c);
void gotoxy_puts(int x, int y, char* s);
void w_gotoxy_putc(WINDOW *win, int x, int y, int c);
void w_gotoxy_puts(WINDOW *win, int x, int y, char *s);
void init_ui();
void show_info();
void show_message(WINDOW *win, struct User *user, char *msg, int type);

#endif
