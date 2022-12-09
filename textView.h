#ifndef __WRITTEN___H__
#define __WRITTEN___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "ncurses.h"

class Engine;

class Written: public View{
  Engine& engine;
  WINDOW *text_win

 public:
  Written(int rows, int cols, Engine& e);
  void update(int row, const std::string& msg);
  void displayView() override;
};
#endif
