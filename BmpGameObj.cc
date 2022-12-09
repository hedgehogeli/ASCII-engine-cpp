#include "BmpGameObj.h"

void BmpGameObj::computePosns() {
    posns.reserve(bmp.size());
    for (auto it : bmp) {
        posns.push_back(make_pair(it.first.first+r, it.first.second+c));
    }
}

BmpGameObj::BmpGameObj(size_t r, size_t c, int height, char ch): 
      GameObj{r, c, height}, ch{ch} {
        BmpGameObj::computePosns();
    }