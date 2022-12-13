#ifndef __BOUND_DTOR_COLLIDE_H__
#define __BOUND_DTOR_COLLIDE_H__

#include "boundaryCollide.h"

class boundDestroyCollider : public boundCollider { 
  public:
    boundDestroyCollider(GameObj* obj);
    void boundaryCollision() override;

};


#endif