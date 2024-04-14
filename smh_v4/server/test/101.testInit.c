/*************************************************************************
	> File Name: 101.testInit.c
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Apr 2024 02:56:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include "../include/server.h"

Server *sv;

int main() {
    int ret = run_server();
    if (!ret) {
        printf("sv : SERVE_RPORT [%d]\n", sv->port);
        printf("sv : DB_HOSTNAME [%s]\n", sv->db->hostname);
        printf("sv : DB_PORT [%d]\n", sv->db->port);
        printf("sv : DB_USR [%s]\n", sv->db->usr);
        printf("sv : DB_PWD [%s]\n", sv->db->pwd);
        printf("sv : DB_NAME [%s]\n", sv->db->db_name);
    } else {
        printf("ERROR!\n");
    }
    return 0;
}
