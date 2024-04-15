/*************************************************************************
	> File Name: 104.testNcui.c
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Apr 2024 04:12:15 PM CST
 ************************************************************************/

#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] = {
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Exit",
};
int n_choices = sizeof(choices) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight);

int main() {
    initscr(); // 初始化 ncurses
    clear(); // 清空屏幕
    noecho(); // 禁止回显输入
    cbreak(); // 禁用行缓冲，使字符立即可用
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    WINDOW *menu_win;
    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    refresh();

    print_menu(menu_win, 1);
    int choice = 0;
    int c;
    while (1) {
        c = wgetch(menu_win);
        switch (c) {
            case KEY_UP:
                if (choice == 0)
                    choice = n_choices - 1;
                else
                    --choice;
                break;
            case KEY_DOWN:
                if (choice == n_choices - 1)
                    choice = 0;
                else
                    ++choice;
                break;
            case 10:
                mvprintw(23, 0, "You chose item %d: %s", choice + 1, choices[choice]);
                clrtoeol();
                refresh();
                if (choice == n_choices - 1)
                    goto end;
                break;
        }
        print_menu(menu_win, choice);
    }

    end:
    delwin(menu_win);
    endwin();
    return 0;
}

void print_menu(WINDOW *menu_win, int highlight) {
    int x, y;
    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
        ++y;
    }
    wrefresh(menu_win);
}

