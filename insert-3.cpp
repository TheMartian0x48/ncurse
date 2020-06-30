#include <ncurses.h>
#include <cstring>

void fill() {
    int a, x, y;
    getmaxyx(stdscr, y, x);
    for(a = 0; a < y; a++) {
        addstr("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
    }
}

int main() {
    char text[] = "Stock market swells! DOW tops 15,000!";
    char *t;

    int len;
    initscr();
    bkgd('.');
    // fill();
    refresh();

    len = strlen(text);
    t = text;
    while(len) {
        move(5,6);
        insch(*(t + len - 1));
        refresh();
        napms(100);
        len--;
    }
    getch();

    endwin();
    return 0;
}
