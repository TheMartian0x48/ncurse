#include <ncurses.h>
using namespace std;

#define MENUMAX 6

void drawmenu(int item) {
    int c;
    char mainmenu[] = "Main Menu";
    char menu[MENUMAX][21] = {
        "Answer E-mail",
        "Off to the Web",
        "Word processing",
        "Financial management",
        "Maintenance",
        "Shutdown"
    };

    clear();
    addstr(mainmenu);
    for (c = 0; c < MENUMAX; c++) {
        if(c == item)
            attron(A_REVERSE);
        mvaddstr(3 + c * 2, 20, menu[c]);
        attroff(A_REVERSE);
    }

    mvaddstr(17, 25, "Use arrow key to move; Enter to select:");
    refresh();
}


int main() {
    int key, menuitem;

    menuitem = 0;

    initscr();

    drawmenu(menuitem);
    keypad(stdscr, TRUE);
    noecho();
    do {
        key = getch();
        switch (key) {
            case KEY_DOWN:
                menuitem = (menuitem + 1) % MENUMAX;
                break;
            case KEY_UP:
                menuitem--;
                if(menuitem < 0)
                    menuitem = MENUMAX - 1;
                    break;
            default:
                break;
        }
        drawmenu(menuitem);
    } while (key != '\n');

    echo();
    endwin();
    return 0;
}
