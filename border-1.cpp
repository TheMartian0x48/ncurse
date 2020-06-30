#include <ncurses.h>
#include <cstring>

using namespace std;


int main() {
    int rows, cols;

    initscr();
    getmaxyx(stdscr, rows, cols);
    rows--;
    cols--;

    move(0,0);
    addch('*');
    refresh();
    napms(50);
    for(int i = 0; i < cols - 1; i++) {
        addch('-');
        refresh();
        napms(50);
    }
    move(0, cols);
    addch('*');
    refresh();
    napms(50);

    for(int i = 1; i < rows; i++) {
        move(i,0);
        addch('|');
        refresh();
        napms(50);
    }

    move(rows, 0);
    addch('*');
    refresh();
    napms(50);

    for(int i = 0; i < cols - 1; i++) {
        addch('-');
        refresh();
        napms(50);
    }

    move(rows, cols);
    addch('*');
    refresh();
    for(int i = rows - 1; i > 0; i--) {
        move(i,cols);
        addch('|');
        refresh();
        napms(50);
    }
    char str[] = "Hello";
    mvaddstr(rows/2, (cols - strlen(str))/2, str);
    
    getch();

    endwin();
    return 0;
}
