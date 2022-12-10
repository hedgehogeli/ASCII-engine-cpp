#include "engine.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    initscr();
    noecho();
    curs_set(0);
    refresh();

    Engine e(20, 78);
    e.play();

    endwin();
}