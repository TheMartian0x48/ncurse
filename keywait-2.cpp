#include <ncurses.h>


int main(void)
{
    long value = 0;
    initscr();

    addstr("Press any key to begin:\n");
    refresh();
    getch();

    nodelay(stdscr,TRUE);
    addstr("Press any key to stop the insane loop!\n");
    while(getch() != ' ') {
        printw("%0.12d\r",value);
        value += 1566;
        refresh();
    }
    endwin();
    return 0;
}
