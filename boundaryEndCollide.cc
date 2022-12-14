#include "boundaryEndCollide.h"
#include "gameObj.h"
#include "engine.h"

boundEndCollider::boundEndCollider(GameObj *obj, bool win): endCollider{obj, win}, 
  stopCollider{obj}, Collider{obj} {}

void boundEndCollider::boundaryCollision() {
    end();
}

void boundEndCollider::collide() {
    Engine& e = obj->getEngine();
    if (obj->getCol() == 0 || obj->getRow() == 0
      || obj->getCol() + obj->getHeight() >= e.cols - 1
      || obj->getRow() + obj->getWidth() >= e.rows - 1) {
        boundaryCollision();
    }
}
