#include "CharGameObj.h"

CharGameObj::CharGameObj(size_t r, size_t c, int height, Engine& e, char ch): 
  GameObj{r, c, height, e}, ch{ch} {
    CharGameObj::computeCells();
}

void CharGameObj::moveBy(size_t row, size_t col) {
    size_t newr = r+row;
    size_t newc = c+col;
    if (newr < 0) newr = 0;
    if (newr >= e.rows) newr = e.rows - 1;
    if (newc < 0) newc = 0;
    if (newc >= e.cols) newc = e.cols - 1;

    Cell& targetCell = e.getGrid()[newr][newc];
    if (targetCell.getObjsAtHeight(height)) { return; } // if conflict, do nothing.

    // remove from occupied cells
    e.getGrid()[r][c].rmObj(this);

    // add to new cells
    targetCell.addObj(this);

    // everything succeeded, update (r, c)
    r += row;
    c += col;
    
}

