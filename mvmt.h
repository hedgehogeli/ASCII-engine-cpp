#ifndef __MVMT_H__
#define __MVMT_H__

class GameObj;

class Mvmt {
    virtual void affect() = 0;
  protected:
    GameObj* obj;
    int waitTicks;
    int waitPeriod; // how many ticks left until apply
    

    
  public:
    Mvmt(GameObj *obj);
    // void resetCollision() { collided = false; }
    virtual void affectMvmt();
    virtual ~Mvmt();  
    void setPeriod(int ticks) {
        waitTicks = waitPeriod = ticks;
    }
};

#endif
