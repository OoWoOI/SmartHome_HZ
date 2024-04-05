/*************************************************************************
	> File Name: 008_main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Apr 2024 04:00:21 PM CST
 ************************************************************************/

#include<iostream>
#include<unistd.h>
using namespace std;
int main() {
   int i = 0;
    while (++i) {
        sleep(1);
        cout << "008-main-runing-" << i << endl;
    }
    return 0;
}
