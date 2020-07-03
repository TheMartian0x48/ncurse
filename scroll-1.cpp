#include <ncurses.h>
#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ifstream in("a.txt");
    WINDOW *lister;
    int maxy, maxx;

    initscr();
    refresh();
    getmaxyx(stdscr, maxy, maxx);

    lister = newwin(maxy, 3*maxx/4, 0, maxx/6);
    scrollok(lister,TRUE);
    scroll(lister);
    if (lister == NULL) {
        addstr("Unable to create window\n");
        refresh();
        getch();
        endwin();
        return 1;
    }
    if (!in.is_open()) {
        addstr("unable to open file\n");
        refresh();
        getch();
        endwin();
        return(2);
    }
    char ch;
    while (!in.eof()) {
        ch = in.get();
        waddch(lister, ch);
        wrefresh(lister);
    };

    in.close();
    getch();

    endwin();
    return 0;
}
