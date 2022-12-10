#include "engine.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    initscr();
    noecho();
    curs_set(0);
    refresh();

    // int xMax, yMax;
    // getmaxyx(stdscr, yMax, xMax);
    // int yStart = (yMax/2) - (25/2);
    // int xStart = (xMax/2) - (80/2);

    // WINDOW* game_win = newwin(20+2, 78+2, yStart, xStart);
    // wborder(game_win, '|', '|', '-', '-', '+', '+', '+', '+');
    // wrefresh(game_win);
    // getch();

    // mvwaddch(game_win, 5+1, 5+1, 'u');
    // wrefresh(game_win);
    // getch();
    
    // endwin();


    // init Engine
    Engine e(20, 78);

    // e.render();

    // Engine.play():
    // while (true) {
    //     timeout(50);

    //     getch();
    // }
    getch();
    endwin();
}