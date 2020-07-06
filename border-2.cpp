#include <ncurses.h>


int main(void) {
    initscr();
    border(0xba,0xba,0xcd,0xcd,0xc9,0xbb,0xc8,0xbc);
    // border('{', '}', '_', '~', '+', '+', '+', '+');
    refresh();
    getch();
    endwin();
    return 0;
}
