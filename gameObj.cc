#include "gameObj.h"

GameObj::GameObj(size_t r, size_t c, int height): r{r}, c{c}, height{height} {
    // posns{std::vector<std::pair<size_t,size_t>>()}
}

char GameObj::charAt(size_t r, size_t c) const { return '.'; }