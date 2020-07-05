#include <ncurses.h>

#define TSIZE 18

int main() {
    WINDOW *b;
    int maxx, maxy, y, x;

    initscr();
    bkgd('.');
    refresh();
    getmaxyx(stdscr, maxy, maxx);

    x = (maxx-TSIZE) >> 1;

    b = newwin(1, TSIZE, 0, x);
    waddstr(b, "I'm getting sick!");

    for(y=0; y < maxy; y++){
        mvwin(b, y, x);
        wrefresh(b);
        touchline(stdscr,y-1,1);
        refresh();
        getch();
    }

    endwin();
    return 0;
}
