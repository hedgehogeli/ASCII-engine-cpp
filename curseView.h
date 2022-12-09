#ifndef __CURSES_VIEW___H__
#define __CURSES_VIEW___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "ncurses.h"

class Engine;

class curseView: public View{
    int width, height;
    Engine& engine;
    WINDOW* game_win;

    void render();

  public:
    curseView(int row, int col, Engine& m);
    ~curseView();
    void update(int row, int col, char c) override;
    void displayView() override;
};

#endif
