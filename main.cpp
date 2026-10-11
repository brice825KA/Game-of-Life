// Main of Program Game of Life
#include "include/gameoflife.hpp"
#include <ncurses.h>

int main(int argv, char **argc) {
    WINDOW *wind = initscr();
    auto x, y = 0;
    noecho();
    getmaxyx(wind, y, x);
    mvprintw(x/2, y/2, "==== Welcome to Automate Game of Life ====");
    while (auto key = getch()) {
        if (key == 'q')
            break;
    }
    endwin();
    return 0;
}