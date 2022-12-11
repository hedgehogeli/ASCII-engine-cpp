#ifndef COLLIDER_H
#define COLLIDER_H

#include "gameObj.h"
#include "cell.h"

class Collider {
  protected:
    GameObj* obj;
  public:
    Collider(GameObj *obj);
    virtual void collide() {}
    virtual void collide(Cell& c) {}
};

#endif