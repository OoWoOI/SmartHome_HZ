/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Mar 2024 01:09:35 PM CST
 ************************************************************************/

#include "./common/head.h"

int server_port = 0;
char server_ip[20] = {0};
char usr_name[20] = {0};

char *conf = "./smh.conf";
int sockfd = -1;
struct SmhMsg chat_msg;
struct SmhMsg ctl_msg;
struct User user;
int show_name = 0;
char data_stream[20] = {0};
WINDOW *message_win, *message_sub,  *info_win, *input_win, *info_sub, *input_sub;
int message_num = 0;


void logout(int signum) {
    bzero(&user, sizeof(user));
    strcpy(user.name, usr_name);
    show_message( message_sub, &user, "Bye !", 0);
    sleep(1);
    struct SmhMsg msg;
    bzero(&msg, sizeof(msg));
    //发送SYN_FIN的信息
    msg.type |= SMH_FIN;
    send(sockfd, &msg, sizeof(msg), 0);
    close(sockfd);
    exit(0);
}


int main() {
    //注册crtl + C 事件退出连接
    signal(SIGINT, logout);
   
   //读取配置信息  
   strcpy(server_ip, get_config_value("./shm.conf", "SERVER_IP"));
   server_port = atoi(get_config_value("./shm.conf", "SERVER_PORT"));
   strcpy(usr_name, get_config_value("./shm.conf", "USER_NAME"));
   usr_name[strlen(usr_name) - 1] = '\0';//去除换行   
   
   if (!(strlen(server_ip) && server_port && strlen(usr_name))) {
        fprintf(stderr, "config is error !\n");
        exit(1);
    }
    
    if ((sockfd = socket_connect(server_ip, server_port)) < 0) {
        perror("socket_connect");
        exit(1);
    }
    
    //请求登录
    struct LogRequest lreq;
    struct LogResponse lrep;
    bzero(&lreq, sizeof(lreq));//清空内存
    bzero(&lrep, sizeof(lrep));

    strcpy(lreq.name, usr_name);//拷贝数据
    strcpy(lreq.msg, "hello");
    
    ssize_t ST_size = send(sockfd, &lreq, sizeof(lreq), 0);

    if (ST_size <= 0) {
        perror("send");
        exit(1);
    }

    ssize_t RC_size = recv(sockfd, &lrep, sizeof(lrep), 0);

    if (RC_size <= 0) {
        perror("recv");
        exit(1);
    }
    

    //输出获取的数据 
    DBG("%d : %s\n", lrep.type, lrep.msg); 
   
    //修改当前语言环境
    setlocale(LC_ALL, "");
    #ifndef _D
        init_ui();
    #endif
    pthread_t recv_tid;
	pthread_create(&recv_tid, NULL, client_recv, NULL);
    while (1) {
        send_chat();
        box(input_win, 0, 0);
	    wrefresh(input_win);
    }
   // sleep(100);

    return 0;
}
