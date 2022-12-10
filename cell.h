#ifndef CELL_H
#define CELL_H

#include "gameObj.h"
#include <list>

#include <iostream>

class Cell {
    static int count;
    const size_t r, c;
    // char c;
    
    std::list<GameObj*> objList; // list of GameObjs, sorted by HEIGHT

  public:
    Cell(size_t r, size_t c);
    
    void addObj(GameObj* o);
    void rmObj(GameObj* o);

    char getChar() const ;

};
#endif

