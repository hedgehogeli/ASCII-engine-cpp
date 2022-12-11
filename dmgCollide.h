#ifndef DMG_COLLIDE_H
#define DMG_COLLIDE_H
#include "collider.h"

class dmgCollider : public Collider {
  public:
    dmgCollider(GameObj *obj);
    // void collide() override;
    void collide(Cell& cell) override;
};

#endif
