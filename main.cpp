// Main of Program Game of Life
#include "include/gameoflife.hpp"
#include <ncurses.h>

int main(int argv, char **argc) {
    WINDOW *wind = initscr();
    int x, y = 0;
    char *set = "==== Welcome to Automate Game of Life ====";
    noecho();
    getmaxyx(wind, y, x);
    printw("%d", strlen(set));
    move((y)/2, (x - strlen(set))/2);
    printw("%s", set);
    while (auto key = getch()) {
        if (key == 'q')
            break;
    }
    endwin();
    return 0;
}