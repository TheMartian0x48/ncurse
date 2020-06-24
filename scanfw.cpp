#include <ncurses.h>
#include <cstring>
#include <iostream>

int main(){
    char mesg[] = "Enter a string: ";
    char str[80];
    int rows, cols;

    initscr();
    getmaxyx(stdscr, rows, cols);
    mvprintw(rows/2, (cols - strlen(mesg))/2, "%s", mesg);
    getstr(str);
    mvprintw(LINES - 2, 0, "You entered: %s", str);
    getch();
    endwin();

    return 0;
}
