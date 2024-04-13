/*************************************************************************
	> File Name: head.h
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Apr 2024 09:42:16 AM CST
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H

//Head file of sys
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include <locale.h>
#include <math.h>


//Head file of usr
#include <common.h>
#include <color.h>
#include <smh_tcp.h>
#include <datatype.h>
#include <smh_ui.h>

//Test DBG
#ifdef _D
    #define DBG(fmt, arg...) {\
        printf("[ %s : %s : %d ] ", __FILE__, __func__, __LINE__);\
        printf(fmt, ##arg);\
    }
#else
    #define DBG(fmt, arg...)

#endif



extern char *conf_val;

#endif
