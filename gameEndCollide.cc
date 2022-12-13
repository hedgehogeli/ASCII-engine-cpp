#include "gameEndCollide.h"
#include "gameObj.h"
#include "engine.h"

endCollider::endCollider(GameObj *obj, bool win): stopCollider{obj}, winOnCollide{win}, Collider{obj} {}

void endCollider::end() {
    if (winOnCollide) { (obj->getEngine()).terminate("YOU WIN"); } 
    else { (obj->getEngine()).terminate("YOU LOSE"); }
}

void endCollider::collide() {
    stopMvmt();
    end();
}