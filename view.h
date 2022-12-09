#ifndef ___VIEW___H__
#define ___VIEW___H__

#include <string>

class View{
 public:
  virtual ~View() = default;
  // virtual void update(const std::string& msg) = 0;
  // virtual void update(int row, int col, char c) = 0;
  virtual void displayView() = 0;
};

#endif
