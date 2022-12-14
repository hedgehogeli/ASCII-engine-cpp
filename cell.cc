#include "cell.h"
#include "gameObj.h"
#include <algorithm>

Cell::Cell(size_t r, size_t c): r{r}, c{c}, 
  objList{std::list<GameObj*>()} {}

void Cell::addObj(GameObj* o) { // insert obj to list
    auto it = objList.end();
    for (auto it = objList.begin(); it != objList.end(); ++it) {
        if ((*it)->getHeight() <= o->getHeight()) break;
    }
    objList.insert(it, o);
}

void Cell::rmObj(GameObj* o) { // rm obj from list
    objList.remove(o);
} 

bool Cell::contains(GameObj* o) {
    return (std::find(objList.begin(), objList.end(), o) != objList.end());
}

char Cell::getChar() const { 
    if (objList.empty()) { return ' '; }
    else return (*(objList.cbegin()))->charAt(r, c);
}

std::vector<GameObj*> Cell::getObjsAtHeight(int h) {
    std::vector<GameObj*> collidingObjs;
    if (h >= 0 && !objList.empty()) {
        auto it = objList.begin();
        auto end = objList.end();
        while (it!=end  &&  (*it)->getHeight() > h) { ++it; }
        while (it!=end  &&  (*it)->getHeight() == h) {
            collidingObjs.push_back(*it);
            ++it;
        }
    }
    return collidingObjs; // ret the collection regardless, empty or not
}
