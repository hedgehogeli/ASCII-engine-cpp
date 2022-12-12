#ifndef CELL_H
#define CELL_H

#include <list>
#include <iostream>
#include <vector>

class GameObj;

class Cell {
  public:
    const size_t r, c;
  private:
    std::list<GameObj*> objList; // list of GameObjs, sorted by HEIGHT

  public:
    Cell(size_t r, size_t c);
    void addObj(GameObj* o);
    void rmObj(GameObj* o);
    bool contains(GameObj* o);
    char getChar() const;

    std::vector<GameObj*> getObjsAtHeight(int h);

};
#endif

