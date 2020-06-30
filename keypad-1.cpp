#include <iostream>
#include <ncurses.h>
using namespace std;

int main() {
    int ch;
    initscr();

    keypad(stdscr, TRUE);
    noecho();
    do {
        ch = getch();
        switch(ch) {
            case KEY_F(5):
                addstr("F5\n");
                break;
            case KEY_DOWN:
                addstr("Down\n");
                break;
            case KEY_UP:
                addstr("Up\n");
                break;
            case KEY_LEFT:
                addstr("Left\n");
                break;
            case KEY_RIGHT:
                addstr("Right\n");
                break;
            default:
                break;
        }
    } while(ch != '\n');

    endwin();
    return 0;
}
