#ifndef BMP_GAME_OBJ_H
#define BMP_GAME_OBJ_H

#include "gameObj.h"
#include <cstddef>
#include <map>
#include <utility>

class BmpGameObj : public GameObj {
    std::map<std::pair<int,int>, char> bmp;

  public:
    void computePosns() override;
    // for each pair in bmp , add r and c
    
    
    BmpGameObj(size_t r, size_t c, int height, 
      std::map<std::pair<int,int>, char> bitmap);
};

#endif