#include "boundaryCollide.h"
#include "engine.h"

void boundCollider::collide() {
    Engine& e = obj->getEngine();
    if (obj->getCol() == 0 || obj->getRow() == 0
      || obj->getCol() + obj->getHeight() >= e.cols - 1
      || obj->getRow() + obj->getWidth() >= e.rows - 1) {
        boundaryCollision();
    }
}
