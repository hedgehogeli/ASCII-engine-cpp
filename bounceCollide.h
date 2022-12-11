#ifndef BOUNCE_COLLIDE_H
#define BOUNCE_COLLIDE_H

#include "collider.h"

class bounceCollider : public Collider {
  public:
    bounceCollider(GameObj *obj);
    void collide() override;
    // void collide(Cell& cell) override;
};

#endif
