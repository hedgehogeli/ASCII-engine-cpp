#include "bounceCollide.h"

bounceCollider::bounceCollider(GameObj *obj): Collider{obj} {}

void bounceCollider::collide() {
    obj->multMvmt(-1, -1);
}