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

//head file of usr
#include "smarthome_tcp.h"

struct UserInfo {
    char name[50];
    char phone[20];
};

#endif
