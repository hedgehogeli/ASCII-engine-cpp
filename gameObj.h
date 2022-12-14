#ifndef __GAME_OBJ_H__
#define __GAME_OBJ_H__

#include "cell.h"
#include "collider.h"
#include "mvmt.h"
#include <cstddef>
#include <vector>
#include <utility>
#include <map>
#include <memory>

class Engine;

class GameObj {
  protected:
    size_t r, c;
    int length, width;
    int height;
    Engine& e;

    int mvmtY, mvmtX;
    int wait, period; // frequency of mvmt: period = # of ticks per move

    std::map<std::pair<int,int>, char> bmp;
    std::vector<Cell*> occupiedCells; // vector of posns the obj occupies

    std::list<std::unique_ptr<Collider>> colliders;
    std::list<std::unique_ptr<Mvmt>> movements;

    void runMvmts();
    void reindexBmp(int dY, int dX);
    void computeCells();
    void computeCollisions();
    void moveCoords();

    void mvmtCollide();
    void dmgCollide(Cell& posn);
    bool collideAt(Cell& posn);

  public:
    bool inPlay;

    GameObj(size_t r, size_t c, int height, Engine& e, char ch);
    GameObj(size_t r, size_t c, int height, Engine& e, size_t w, size_t l, char ch);
    GameObj(size_t r, size_t c, int height, Engine& e, std::map<std::pair<int,int>, char> bitmap);
    
    int getHeight() const { return height; }
    Engine& getEngine() { return e; }
    char charAt(size_t row, size_t col) const; // returns 0 if not within obj
    size_t getRow() { return r; }
    size_t getCol() { return c; }
    int getLength() const { return length; }
    int getWidth() const { return width; }


    void setMvmt(int y, int x) {
        mvmtY = y; 
        mvmtX = x;
    }
    void multMvmt(int y, int x) {
        mvmtY *= y; 
        mvmtX *= x;
    }
    void addMvmt(int y, int x) {
        mvmtY += y;
        mvmtX += x;
    }
    void setPeriod(int ticks) {
        period = ticks;
        wait = period;
    }

    void addCollider(std::unique_ptr<Collider> c);
    // void detachCollider(std::unique_ptr<Collider> c);
    void addMvmt(std::unique_ptr<Mvmt> m);
    void clearMvmts();

    // std::map<Cell*, std::vector<GameObj*>> computeCollisions(int row, int col);
    
    void destroyCharAt(Cell& posn); 
    void selfDestruct();
    void resetColliders();
    
    void move();
    void moveBy(int row, int col) { setMvmt(row, col); } // f'n to respond to user input


};

#endif
