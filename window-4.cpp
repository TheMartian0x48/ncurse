#include <ncurses.h>
#include <stdlib.h>
void bomb(void);

int main(void)
{
    WINDOW *a,*b,*c,*d;
    int maxx,maxy,halfx,halfy;
    initscr();
    refresh();

    getmaxyx(stdscr,maxy,maxx);
    halfx = maxx >> 1;
    halfy = maxy >> 1;

    if( (a = newwin(halfy,halfx,0,0)) == NULL) bomb();
    if( (b = newwin(halfy,halfx,0,halfx)) == NULL) bomb();
    if( (c = newwin(halfy,halfx,halfy,0)) == NULL) bomb();
    if( (d = newwin(halfy,halfx,halfy,halfx)) == NULL) bomb();

    mvwaddstr(a,0,0,"This is window A\n");
    wrefresh(a);
    mvwaddstr(b,0,0,"This is window B\n");
    wrefresh(b);
    mvwaddstr(c,0,0,"This is window C\n");
    wrefresh(c);
    mvwaddstr(d,0,0,"This is window D\n");
    wrefresh(d);
    getch();
    getch();
    getch();

    endwin();
    return 0;
}

void bomb(void)
{
    addstr("Unable to allocate memory for new window.\n");
    refresh();
    endwin();
    exit(1);
}
