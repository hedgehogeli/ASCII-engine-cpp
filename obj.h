#ifndef OBJ_H
#define OBJ_H

class Cell;

class Obj {
 public:
  virtual void collide(Cell& cell, int yMultiplier, int xMultiplier) = 0;
  virtual ~Obj();
};

#endif
