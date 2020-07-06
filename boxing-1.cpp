#include <ncurses.h>


void showhelp(void);
WINDOW *help;

int main() {
    int ch;
    initscr();
    if((help = newwin(10,30,4,26)) == NULL) {
    addstr("Unable to allocate window memory\n");
    endwin();
    return(1);
    }

    mvwaddstr(help,1,7,"Help menu Screen");
    mvwaddstr(help,5,3,"Press the ~ key to quit");
    mvwaddstr(help,8,4,"Press ENTER to go back");
    box(help,0,0);
    box(stdscr,0,0);
    mvaddstr(1, 1, "Typer Program\n");
    mvaddstr(2, 1, "Press + for help:\n\n");
    move(3,1);
    refresh();
    noecho();
    do {
        ch = getch();
        refresh();
        if(ch == '+')
            showhelp();
        else
            addch(ch);
    } while (ch != '~');
    endwin();
    return 0;
}

void showhelp(void) {
    touchwin(help);
    wrefresh(help);
    getch();
    touchwin(stdscr);
    refresh();
}
