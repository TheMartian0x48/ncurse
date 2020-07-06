#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

int main() {
    char word[7];
    int x, w, r;

    srandom((unsigned) time(NULL));
    word[7] = '\0';
    initscr();

    for (x = 0; x < 200; x++) {
        for (w = 0; w < 6; w++)
            word[w] = (random() % 26) + 'a';
        printw("%s\t", word);
    }

    addch('\n');
    addstr("Press Enter to write this screen to disk\n");
    refresh();
    getch();


    r = scr_dump("windump");
    if(r == ERR)
        addstr("Error writing window to disk\n");
    else
        addstr("File written; press Enter to quit\n");
    refresh();
    getch();

    endwin();
    return 0;
}
