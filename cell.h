#ifndef CELL_H
#define CELL_H

#include "gameObj.h"
#include <list>
#include <iostream>

class GameObj;

class Cell {
    std::list<GameObj*> objList; // list of GameObjs, sorted by HEIGHT

  public:
    const size_t r, c;

    Cell(size_t r, size_t c);
    void addObj(GameObj* o);
    void rmObj(GameObj* o);
    char getChar() const;

    std::vector<GameObj*> getObjsAtHeight(int h);

};
#endif

