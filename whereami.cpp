#include <ncurses.h>
#include <cstring>


int main() {
    initscr();
    char ch;
    int row, col;
    addstr("Type some text; '~' to end:\n");
    refresh();

    while( (ch==getch()) != '~');
    getyx(stdscr, row, col);
    printw("\n\nThe cursor was at row %d, column %d\n", row, col);
    refresh();
    getch();
    endwin();
    return 0;
}
