/*************************************************************************
	> File Name: head.h
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Feb 2024 02:05:19 PM CST
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H

//head file of sys
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>
#include <locale.h>
#include <ncurses.h>
#include <math.h>

//head file of usr
#include "sh_tcp.h"
#include "common.h"
#include "sh_pthread_pool.h"
#include "datatype.h"
#include "recv_client.h"
#include "chat_ui.h"
#include "send_chat.h"

struct UserInfo {
    char name[50];
    char phone[20];
};

extern char *conf_val;
//测试宏
#ifdef _D
#define DBG(formt, arg...) {\
//    printf("[ %s : %s : %d ] ", __FILE__, __func__, __LINE__);
    printf(formt, ##arg);\
}
#else
#define DBG(formt, arg...)
#endif
    

#endif
