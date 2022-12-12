#include "stopCollide.h"
#include "gameObj.h"

stopCollider::stopCollider(GameObj *obj): Collider{obj} {}

void stopCollider::stopMvmt() {
    obj->setMvmt(0, 0);
}

void stopCollider::collide() { 
    stopMvmt();
}
