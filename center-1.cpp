#include <ncurses.h>
#include <cstring>

void center(int row, char *title) {
    int len, indent, y, width;

    getmaxyx(stdscr, y, width);

    len = strlen(title);
    indent = width - len;
    indent /= 2;

    mvaddstr(row, indent, title);
    refresh();
}


int main() {
    initscr();

    center(1, "Penguin Soccer Finals");
    center(5, "Cattle Dung Sample from Temecula");
    center(7, "Catatonic Threater");
    center(9, "Why Do Ions Hate Each Other?");

    getch();
    endwin();
    return 0;
}
