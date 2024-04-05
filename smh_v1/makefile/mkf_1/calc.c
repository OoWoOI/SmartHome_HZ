/*************************************************************************
	> File Name: calc.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Apr 2024 08:27:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include"calc.h"

int calc(int n) {
    return sub(n) + mutl(n);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("calc = %d\n", calc(n));
    return 0;
}
