#include "collider.h"

Collider::~Collider() {}

Collider::Collider(GameObj* obj): obj{obj} {
    collided = false;
}

void Collider::runCollision() { 
    if (!collided) {
        collided = true;
        collide(); 
    }
}
void Collider::runCollision(Cell& c) { 
    if (!collided) {
        collided = true;
        collide(c); 
    }
}
