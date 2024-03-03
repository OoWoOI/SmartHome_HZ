/*************************************************************************
	> File Name: recv_client.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Mar 2024 04:36:36 PM CST
 ************************************************************************/

#include "./common/head.h"
extern int sockfd;
extern char usr_name[20];

void *client_recv(void *arg) {
        struct User user;
        bzero(&user, sizeof(user));
        strcpy(user.name, usr_name);
    	while (1) {
	         struct SmhMsg msg;
	         bzero(&msg, sizeof(msg));
	         recv(sockfd, &msg, sizeof(msg), 0); //粘包、拆包
	         if (msg.type & SMH_HEART) {
	             Show_Message(message_sub, &user,"来自服务器的心跳♥\n", 0);
                //需要回应服务器的心跳♥信息
                msg.type = SMH_ACK;
                send(sockfd, &msg, sizeof(msg), 0);
	        } else if (msg.type & SMH_MSG) {
	            DBG("Server Msg : %s\n", msg.msg);
                Show_Message(message_sub, &user, msg.msg, 0);
	    } else if (msg.type & SMH_WALL) {
	            char buff[2048] = {0};
                sprintf( buff,"Server Msg To All: %s", msg.msg);
                Show_Message(message_sub, &user, buff, 0);
	    } else if (msg.type & SMH_FIN) {
	            DBG("服务器正要停止。\n");
	            Show_Message(message_sub, &user, "服务器正要停止。", 0);
                close(sockfd);
	            exit(0);
	    } else {
	            DBG("Msg Unsupport\n");
                char buff[2048] = {0};
                sprintf(buff, "%d : %s", msg.type, msg.msg);
                Show_Message(message_sub, &user, buff, 0);
	    }
	}
     
    return NULL;
}
