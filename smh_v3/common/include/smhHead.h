/*************************************************************************
	> File Name: smhHead.h
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 05:03:30 PM CST
 ************************************************************************/

#ifndef _SMHHEAD_H
#define _SMHHEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


//DeBug Macro
#ifdef _D
    #define DBG(fmt, arg...) {\
        printf("[ %s : %s : %d ] ", __FILE__, __func__, __LINE__);\
        printf(fmt, ##arg);\
    }
#else
    #define DBG(fmt, arg...)
#endif

#endif
