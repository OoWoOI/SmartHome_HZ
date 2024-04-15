/*************************************************************************
	> File Name: smhSend.c
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Apr 2024 02:54:15 PM CST
 ************************************************************************/

extern WINDOW *input_sub, *input_win;
extern struct SmhMsg chat_msg;

void send_chat(int sockfd) {
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

