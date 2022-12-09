#include "cell.h"

Cell::Cell(size_t r, size_t c): r{r}, c{c} {}

void Cell::addObj(GameObj* o) { // insert obj to list
    auto it = objList.begin();
    while ((*it)->getHeight() > o->getHeight()) { ++it; } // find height
    objList.insert(it, o);
}

void Cell::rmObj(GameObj* o) { // rm obj from list
    objList.remove(o);
} 
// should cell be working with raw gameboj ptrs here?