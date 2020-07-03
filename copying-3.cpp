#include <ncurses.h>

int main(void){
    WINDOW *top, *bottom;
    int maxx, maxy, halfx, halfy, rc;

    char text1[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip exea commodo consequat.";

    char text2[]= "Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.";

    initscr();
    refresh();
    getmaxyx(stdscr, maxy, maxx);
    halfx = maxx >> 1;
    halfy = maxy >> 1;

    top = newwin(halfy, maxx, 0, 0);
    bottom = newwin(halfy, halfx, halfy, halfx);


    waddstr(top, text1);
    wrefresh(top);
    waddstr(bottom, text2);
    wrefresh(bottom);

    getch();

    rc = copywin(top, bottom, 0, 0, 0, 0, 4, 12, FALSE);
    wrefresh(bottom);
    getch();

    endwin();
    return 0;
}
