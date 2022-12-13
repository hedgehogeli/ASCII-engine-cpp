#ifndef STOP_COLLIDE_H
#define STOP_COLLIDE_H

#include "collider.h"

class stopCollider : virtual public Collider {
  public:
    stopCollider(GameObj *obj);
    void stopMvmt();
    virtual void collide() override;
};

#endif
