#include "BmpGameObj.h"

void BmpGameObj::computePosns() {
    posns.reserve(bmp.size());
    for (auto it : bmp) {
        posns.push_back(std::make_pair(it.first.first+r, it.first.second+c));
    }
}

BmpGameObj::BmpGameObj(size_t r, size_t c, int height, 
  std::map<std::pair<int,int>, char> bitmap): 
    GameObj{r, c, height}, bmp{bitmap} {
    BmpGameObj::computePosns();
}