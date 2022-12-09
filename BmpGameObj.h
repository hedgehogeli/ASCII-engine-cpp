#ifndef BMP_GAME_OBJ_H
#define BMP_GAME_OBJ_H

#include <GameObj.h>
#include <cstddef>
#include <map>
#include <utility>

class BmpGameObj : public GameObj {
    std::map<std::pair<int,int>, char> bmp;

  public:
    std::map<std::pair<int,int>, char> computePosns() override;
        // for each pair in bmp , add r and c
    
    
    BmpGameObj(size_t r, size_t c, int height, 
      std::map<std::pair<int,int>, char> bitmap): 
      GameObj{r, c, height}, bmp{bitmap} {
        
    }
};

#endif