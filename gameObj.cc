#include "gameObj.h"

GameObj::GameObj(size_t r, size_t c, int height, Engine& e, char ch): r{r}, c{c}, height{height}, e{e} {
    bmp[std::make_pair(0, 0)] = ch;
}
GameObj::GameObj(size_t r, size_t c, int height, Engine& e, size_t w, size_t l, char ch):
  r{r}, c{c}, height{height}, e{e} {
    for (int x=0; x<w; ++x) {
        for (int y=0; y<l; ++y) {
            bmp[std::make_pair(0,0)] = ch;
        }
    }
}
GameObj::GameObj(size_t r, size_t c, int height, Engine& e, std::map<std::pair<int,int>, char> bitmap):
  r{r}, c{c}, height{height}, e{e}, bmp{bitmap} {}

void GameObj::computeCells() {
    occupiedCells.reserve(bmp.size());
    occupiedCells.clear();
    for (auto it : bmp) {
        occupiedCells.push_back(&(e.getGrid()[it.first.first + r][it.first.second + c]));
    }
}


char GameObj::charAt(size_t row, size_t col) const {
    return bmp.at(std::make_pair(row-r, col-c));
}

// void GameObj::computeCollisions() {
//     occupiedCells.push_back(&(e.getGrid()[r][c]));
//     posns.reserve(bmp.size());
//     for (auto it : bmp) {
//         posns.push_back(std::make_pair(it.first.first+r, it.first.second+c));
//     }
// }
void GameObj::addCollider(std::unique_ptr<Collider> c){
    colliders.emplace_back(std::move(c));
}

void GameObj::destroyCharAt(Cell& posn) {
    posn.rmObj(this);
    bmp.erase(std::make_pair(posn.r - r, posn.c - c));
}

// std::map<Cell*, std::vector<GameObj*>> GameObj::computeCollisions(int row, int col) {
//     std::map<Cell*, std::vector<GameObj*>> mapping;
//     for (auto it : bmp) {
//         Cell& curCell = e.getGrid()[r][c];
//         mapping[&curCell] = curCell.getObjsAtHeight(height);
//     }
//     return mapping;
// } // useless...? 


void GameObj::collide(Cell& cell) {
    for (auto& it : colliders) {
        it->collide(cell);
    }
}

// pixel destruction collision using Collider::collide(Cell&) happens here. 
// returns vector<GameObj*> of GameObj's 'this' has collided with at Cell& cell
std::vector<GameObj*> GameObj::collideAt(Cell& cell) {
    std::vector<GameObj*> collidingObjs = cell.getObjsAtHeight(height);
    for (auto it : collidingObjs) {
        it->collide(cell);
    }
    return collidingObjs; // return all objs that 'this' may have collided with
} 

// attempt to move by 'this's defined motion vector (mvmtX, mvmtY)
void GameObj::move() {
    // check if this tick is the right one

    bool collision = false;
    for (auto it : bmp) { // for every cell 'this' currently occupies,
        Cell& curCell = e.getGrid()[r+mvmtY][c+mvmtX]; // get its destination cell
        std::vector<GameObj*> collidedWith = collideAt(curCell); // collide with destination cell
        // pikel destruction collision happens here.
        if (collidedWith.size()) { // if collided with at least 1 obj, track it
            collision = true;
        }
    }
    if (collision) { // mvmt modifying collision happens here
        for (auto &it : colliders) {
            it->collide(); // mvmtX, mvmtY mutated if necessary
        }
    } 

    // collisions have been resolved, place down into cells
    r += mvmtX; 
    c += mvmtY;
    computeCells(); // mutates occupiedCells
    for (auto c : occupiedCells) {
        c->addObj(this);
    }
}



// size_t GameObj::enforceR(size_t r);
// size_t GameObj::enforceC(size_t c);
// char GameObj::charAt(size_t r, size_t c) const { return '.'; }