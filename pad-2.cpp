#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

#define TALL 24
#define WIDE 19
#define SPACER 5

void bomb(){
    char m[] = "Error\n";
    addstr(m);
    refresh();
    getch();
    endwin();
    exit(1);
}


int main() {
    WINDOW *p;

    initscr();
    refresh();

    p = newpad(200, WIDE + 1);
    if(!p)
        bomb();

    ifstream in("a.txt");
    if(!in.is_open()){
        bomb();
    }

    char ch;
    while (!in.eof()) {
        ch = in.get();
        waddch(p, ch);
    };

    in.close();

    prefresh(p, 0, 0, 0, 0, TALL-1, WIDE);
    prefresh(p, TALL, 0, 0, WIDE+SPACER, TALL-1, WIDE*2+SPACER);
    prefresh(p, TALL*2, 0, 0,WIDE*2+SPACER*2, TALL-1, WIDE*3+SPACER*2);

    wgetch(p);
    endwin();
    return 0;
}
