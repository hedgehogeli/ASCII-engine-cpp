#include "curseView.h"
#include <ncurses.h>
// #include "engine.h"

Curses::Curses(int rows, int cols, Engine& e): width{rows}, height{cols}, engine{e} {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int yStart = yMax/2 - (rows+2+3)/2; // leave space for 3 text rows in textView
    int xStart = xMax/2 - (cols+2)/2;   // and add 2 for border chars

    game_win = newwin(cols+2, rows+2, yStart, xStart);
    wborder(game_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(game_win);
}

void Curses::update(int row, int col, char c) {
    mvwaddch(game_win, row+1, col+1, c);
}

void Curses::displayView() {
    wrefresh(game_win);
}

void Curses::render() {
    for (size_t r=0; r<width; ++r) {
        for (size_t c=0; c<height; ++c) {
            update(r, c, engine.grid[r][c].getChar());
        }
    }
    Curses::displayView();
}



Curses::~Curses() {}
