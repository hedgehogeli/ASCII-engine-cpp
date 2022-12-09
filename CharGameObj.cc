#include "CharGameObj.h"

CharGameObj::CharGameObj(size_t r, size_t c, int height, char ch): 
      GameObj{r, c, height}, ch{ch} {
        CharGameObj::computePosns();
    }

