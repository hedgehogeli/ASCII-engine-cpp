#ifndef CELL_H
#define CELL_H

#include "GameObj.h"
#include <list>

class Cell {
  const size_t r, c;
  // char c;
  
  std::list<GameObj*> objList; // list of GameObjs, sorted by HEIGHT

 public:
  Cell(size_t r, size_t c);
  
  void addObj(GameObj* o);
  void rmObj(GameObj* o);

  char getChar() const { 
    if (objList.empty()) { return ' '; }
    else return (*(objList.cbegin()))->charAt(r, c); 
  }

};
#endif

