#include <ncurses.h>


int main(void)
{
    initscr();
    char text[] = "Greetings from NCurses!";
    char *t = text;

    while(*t) {
        addch(*t++);
        refresh();
        napms(100);
    }
    endwin();
    return 0;
}
