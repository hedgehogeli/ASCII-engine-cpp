#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include "obj.h"
#include "engine.h"
#include "cell.h"
#include "collider.h"
#include <cstddef>
#include <vector>
#include <utility>
#include <map>

// class Engine;

class GameObj {
  protected:
    Engine& e;
    size_t r, c;
    int height;
    int mvmtY, mvmtX;

    std::map<std::pair<int,int>, char> bmp;
    std::vector<Cell*> occupiedCells; // vector of posns the obj occupies

    // motion vector
    std::list<std::unique_ptr<Collider>> colliders;
    
    

    void computeCells();

  public:
    GameObj(size_t r, size_t c, int height, Engine& e, char ch);
    GameObj(size_t r, size_t c, int height, Engine& e, size_t w, size_t l, char ch);
    GameObj(size_t r, size_t c, int height, Engine& e, std::map<std::pair<int,int>, char> bitmap);
    
    int getHeight() const { return height; }
    char charAt(size_t row, size_t col) const; // returns 0 if not within obj
    void setMvmt(int y, int x) {
        mvmtY = y; 
        mvmtX = x;
    }
    void multMvmt(int y, int x) {
        mvmtY *= y; 
        mvmtX *= x;
    }
    // size_t enforceR(size_t r);
    // size_t enforceC(size_t c);

    void addCollider(std::unique_ptr<Collider> c);
    // void detachCollider(std::unique_ptr<Collider> c);

    std::map<Cell*, std::vector<GameObj*>> computeCollisions(int row, int col);

    void collide(Cell& posn);
    void destroyCharAt(Cell& posn);
    std::vector<GameObj*> collideAt(Cell& posn);
    
    void move();
    void moveBy(int row, int col) { setMvmt(row, col); } // f'n to respond to user input

};

#endif