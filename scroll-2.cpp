#include <iostream>
#include <ncurses.h>

int main() {
    int maxx, maxy, y;
    initscr();

    getmaxyx(stdscr, maxy, maxx);
    scrollok(stdscr, TRUE);

    for (y = 0; y <= maxy; y++) {
        mvprintw(y, 0, "This is boring written to line %d.", y);
    }

    refresh();
    getch();

    scrl(3);
    refresh();
    getch();

    scrl(-5);
    refresh();
    getch();

    endwin();
    return 0;
}
