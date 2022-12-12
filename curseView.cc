#include "curseView.h"
#include "ncurses.h"
#include "engine.h"

curseView::curseView(int rows, int cols, Engine& e): width{rows}, height{cols}, engine{e} {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    
    int yStart = yMax/2 - (rows+2+3)/2; // leave space for 3 text rows in textView
    int xStart = xMax/2 - (cols+2)/2;   // and add 2 for border chars

    game_win = newwin(rows+2, cols+2, yStart, xStart);
    timeout(50);
    keypad(game_win, true);    
    keypad(stdscr, true);
    wborder(game_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(game_win);
}

void curseView::update(int row, int col, char c) {
    mvwaddch(game_win, row+1, col+1, c); // ???????????????????????
}

// void curseView::renderCells() {
//     for (int r=0; r<width; ++r) {
//         for (int c=0; c<height; ++c) {
//             update(r, c, engine.grid[r][c].getChar());
//         }
//     }
// update(5, 5, 'x');
//     // displayView();
// }

void curseView::displayView() {
    // render();
    wrefresh(game_win);
}





curseView::~curseView() {}
