/*************************************************************************
	> File Name: 03.task003.c
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Apr 2024 10:53:27 AM CST
 ************************************************************************/

#include<smh.h>

int ret;

int main() {
    // 设置标准输入为非阻塞模式
    ret = make_nonblock(STDIN_FILENO);
    if (ret == -1) {
        perror("make_nonblock");
        exit(EXIT_FAILURE);
    }

    // 从标准输入读取数据
    char buf[1024] = {0};
    
    ret = read(STDIN_FILENO, buf, sizeof(buf));
    printf("%d\n", ret);
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
