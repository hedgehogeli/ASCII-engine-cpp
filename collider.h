#ifndef __COLLIDER_H__
#define __COLLIDER_H__

class GameObj;
class Cell;

class Collider {
  protected:
    bool collided; // has this collision acted this turn
    GameObj* obj;
     
  public:
    Collider(GameObj *obj);
    void resetCollision() { collided = false; }
    virtual void collide() {}           // collide()s default to do nothing
    virtual void collide(Cell& c) {}
    void runCollision();
    void runCollision(Cell&c);
    virtual ~Collider();  
};

#endif