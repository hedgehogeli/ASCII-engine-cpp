#include "cell.h"

Cell::Cell(size_t r, size_t c): r{r}, c{c}, 
  objList{std::list<GameObj*>()} { ++count; }

void Cell::addObj(GameObj* o) { // insert obj to list
    auto it = objList.begin();
    while ((*it)->getHeight() > o->getHeight()) { ++it; } // find height
    objList.insert(it, o);
}

void Cell::rmObj(GameObj* o) { // rm obj from list
    objList.remove(o);
} 
// should cell be working with raw gameboj ptrs here?

char Cell::getChar() const { 
    // std::cout << count << std::endl;
    // std::cout << &objList << std::endl;
    if (objList.empty()) { return ' '; }
    else return (*(objList.cbegin()))->charAt(r, c);
}

int Cell::count = 0;