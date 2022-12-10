#include "textView.h"
#include <iostream>
#include <cstring>
#include "engine.h"

textView::textView(int rows, int cols, Engine& e): engine{e} {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int yStart = yMax/2 - (rows+2+3)/2 + rows; 
    int xStart = xMax/2 - (cols+2)/2;

    text_win = newwin(3, cols, yStart+2, xStart);
    wprintw(text_win, "placeholder init");
    wrefresh(text_win);
} 

void textView::displayView(){
  wrefresh(text_win);
}

// 0 <= row <= 2
void textView::update(int row = 0, const std::string& msg = "") {
    mvwprintw(text_win, row, 0, msg.c_str());
    displayView();
}



