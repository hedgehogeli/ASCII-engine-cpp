#include "stopCollide.h"

stopCollider::stopCollider(GameObj *obj): Collider{obj} {}

void stopCollider::collide() { 
    obj->setMvmt(0, 0);
}
