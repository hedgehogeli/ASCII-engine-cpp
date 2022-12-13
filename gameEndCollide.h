#ifndef __END_COLLIDE_H__
#define __END_COLLIDE_H__

#include "stopCollide.h"

class endCollider : virtual public stopCollider {
    bool winOnCollide;
  public:
    endCollider(GameObj *obj, bool win);

    // void setWin() { winOnCollide = true; }
    // void setLose() { winOnCollide = false; }

    void end();
    
    void collide() override;

    // void collide(Cell& cell) override;
};

#endif
