/*************************************************************************
	> File Name: 105.testType.c
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Apr 2024 05:09:05 PM CST
 ************************************************************************/

#include<stdio.h>
#define SMH_HEART 0x01 //心跳
#define SMH_ACK 0x08 //ack
#define SMH_MSG 0x04 //聊天
#define SMH_WALL 0x02 //公告
#define SMH_CTL 0x10 //控制信息
#define SMH_FIN 0x100 //离场

int main() {
    int type;
    scanf("%d", &type);
    printf("%d", SMH_FIN);
    return 0;
}
