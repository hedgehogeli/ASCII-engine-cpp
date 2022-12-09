#ifndef __WRITTEN___H__
#define __WRITTEN___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "ncurses.h"

class Engine;

class textView: public View{
  Engine& engine;
  WINDOW *text_win;

 public:
  textView(int rows, int cols, Engine& e);
  void update(int row, const std::string& msg) override;
  void displayView() override;
};
#endif
