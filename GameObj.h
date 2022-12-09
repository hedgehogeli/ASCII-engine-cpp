#ifndef OBJ_H
#define OBJ_H

#include <cstddef>
#include <vector>
#include <utility>

class GameObj {
  protected:
    size_t r, c;
    int height;
  
    vector<pair<size_t,size_t>> posns;
    // collider class attachment
    // vector of posns the obj occupies

    virtual void computePosns() = 0;

  public:
    GameObj(size_t r, size_t c, int height): 
      r{r}, c{c}, height{height}, posns{vector<pair<size_t,size_t>>} {}
    
    int getHeight() { return height; }

    virtual char charAt(size_t r, size_t c) const;

    // MOVE METHOD

    // + collideWith(GameObj)
    // + collideWith(BorderObj)
    // + collideBy(CollideableObj)
    // + despawn()
};

#endif