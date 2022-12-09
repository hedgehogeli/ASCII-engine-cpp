#ifndef ___VIEW___H__
#define ___VIEW___H__

#include <string>

class View{
 public:
  virtual ~View() = default;
  virtual void update(int row, const std::string& msg) {}
  virtual void update(int row, int col, char c) {}
  virtual void displayView() = 0;
};

#endif
