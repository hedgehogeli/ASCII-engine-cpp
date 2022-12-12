#include "dmgCollide.h"
#include "gameObj.h"

dmgCollider::dmgCollider(GameObj *obj): Collider{obj} {}

// void collide(Cell& cell) {}

void dmgCollider::collide(Cell& cell) { 
    obj->destroyCharAt(cell);
}
