/*************************************************************************
	> File Name: 102.testWSIZE.c
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Apr 2024 03:20:57 PM CST
 ************************************************************************/

#include <sys/ioctl.h>
#include <stdio.h>

int main() {
    struct winsize size;
    ioctl(0, TIOCGWINSZ, &size);
    printf("Terminal width: %d\n", size.ws_col);
    printf("Terminal height: %d\n", size.ws_row);
    return 0;
}

