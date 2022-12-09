#include "RectGameObj.h"

#include <utility>

// void RectGameObj::computePosns() {
//     RectGameObj::posns.reserve(width*length);
//     for (int w=0; w<width; ++w) {
//         for (int l=0; l<length; ++l) {
//             posns.push_back(std::make_pair(l+r, w+c));
//         }
//     }
// }

RectGameObj::RectGameObj(size_t r, size_t c, int height, char ch): 
      GameObj{r, c, height}, ch{ch} {
        RectGameObj::computePosns();
    }