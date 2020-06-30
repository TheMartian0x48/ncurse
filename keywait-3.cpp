#include <ncurses.h>

int kbhit(void) {
    int ch, r;
    nodelay(stdscr, TRUE);
    noecho();

    ch = getch();
    if (ch == ERR)
        r = FALSE;
    else {
        r = TRUE;
        ungetch(ch);
    }

    echo();
    nodelay(stdscr, FALSE);
    return (r);
}

int main(void)
{
    long value = 0;
    initscr();

    addstr("Press any key to end this programme: \n");
    while (!kbhit());

    endwin();
    return 0;
}
