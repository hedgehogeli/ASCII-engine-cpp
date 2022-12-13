#ifndef __BOUND_END_COLLIDE_H__
#define __BOUND_END_COLLIDE_H__

#include "gameEndCollide.h"
#include "boundaryCollide.h"

class boundEndCollider : virtual public endCollider, virtual public boundCollider{
  public:
    boundEndCollider(GameObj *obj, bool win);
    // void setWin() { winOnCollide = true; }
    // void setLose() { winOnCollide = false; }
    void collide() override;
    void boundaryCollision() override;

    // void collide(Cell& cell) override;
};

#endif
