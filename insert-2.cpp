#include <ncurses.h>
#include <cstring>

int main() {
    char text[] = "Stock market swells! DOW tops 15,000!";
    char *t;

    int len;
    initscr();

    len = strlen(text);
    t = text;
    while(len) {
        move(5,5);
        insch(*(t + len - 1));
        refresh();
        napms(100);
        len--;
    }
    getch();

    endwin();
    return 0;
}
