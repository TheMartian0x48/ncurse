#include <ncurses.h>

int main() {
    char first[4];
    char last[4];

    initscr();
    addstr("What is first 3 letter of your first name? ");
    refresh();
    getnstr(first, 3);

    addstr("What is first 3 letter of your last name? ");
    refresh();
    getnstr(last, 3);

    printw("username: $%s-%s!", first, last);
    refresh();
    getch();

    endwin();
    return 0;
}
