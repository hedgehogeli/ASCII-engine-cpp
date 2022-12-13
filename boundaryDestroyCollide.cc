#include "boundaryDestroyCollide.h"
#include "gameObj.h"

boundDestroyCollider::boundDestroyCollider(GameObj* obj): Collider{obj} {}

void boundDestroyCollider::boundaryCollision() {
    obj->selfDestruct();
}
