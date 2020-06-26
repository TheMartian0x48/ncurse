#include <ncurses.h>

int main(void)
{
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_RED, COLOR_BLACK);
    // bkgd(COLOR_PAIR(1) | '-');
    bkgd('-');
    attron(COLOR_PAIR(2));
    addstr("Hello World\n");
    refresh();
    getch();
    endwin();
    return 0;
}
