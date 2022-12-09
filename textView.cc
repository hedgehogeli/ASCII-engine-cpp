#include "textView.h"
#include <iostream>
#include "maze.h"

Written::Written(int rows, int cols, Engine& e): engine{e} {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int yStart = yMax/2 - (rows+2+3)/2 + rows; 
    int xStart = xMax/2 - (cols+2)/2;

    text_win = newwin(rows, cols, yStart, xStart);
    wprintw(text_win, "placeholder init");
    wrefresh(text_win);
} 

// 0 <= row <= 2
void Written::update(int row, const std::string& msg) {
    mvwprintw(text_win, row, 0, msg);
}


void Written::displayView(){
  wrefresh(text_win);
}
