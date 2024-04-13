/*************************************************************************
	> File Name: 004.testNONBLOCKIO.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Apr 2024 08:08:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "../include/smhIO.h"

int main() {
    // 设置标准输入为非阻塞模式
    int ret = make_nonblock(STDIN_FILENO);
    if (ret == -1) {
        perror("make_nonblock");
        exit(EXIT_FAILURE);
    }

    // 从标准输入读取数据
    char buf[1024];
    ret = read(STDIN_FILENO, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Read %d bytes: %s\\\\\\\\n", ret, buf);

    // 恢复标准输入的阻塞模式
    ret = make_block(STDIN_FILENO);
    if (ret == -1) {
        perror("make_block");
        exit(EXIT_FAILURE);
    }

    return 0;
}

