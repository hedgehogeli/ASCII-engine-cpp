#ifndef STOP_COLLIDE_H
#define STOP_COLLIDE_H

#include "collider.h"

class stopCollider : public Collider {
  public:
    stopCollider(GameObj *obj);
    void collide() override;
};

#endif
