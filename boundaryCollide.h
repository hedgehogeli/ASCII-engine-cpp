#ifndef __BOUND_COLLIDE_H__
#define __BOUND_COLLIDE_H__

#include "collider.h"

class boundCollider : virtual public Collider {
  public:
    void collide() override;
    virtual void boundaryCollision() = 0;
};

#endif 
