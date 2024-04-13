/*************************************************************************
	> File Name: smhIO.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 08:10:02 PM CST
 ************************************************************************/

#include <fcntl.h>

//设置fd非阻塞IO
int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    
    flag |= O_NONBLOCK;
    
    return fcntl(fd, F_SETFL, flag);
}

//设置fd为阻塞IO
int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}


