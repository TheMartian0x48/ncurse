#include <ncurses.h>

int main(void) {
    char buf[81];
    initscr();

    addstr("Press any key to begin:\n");
    refresh();
    getch();

    addstr("Type on the keyboard whilst I wait...\n");
    refresh();
    napms(5000);
    /* 5 seconds */
    addstr("Here is what you typed:\n");
    flushinp();
    getnstr(buf,80);
    refresh();

    endwin();
    return 0;
}
