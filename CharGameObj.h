#ifndef CHAR_H
#define CHAR_H

#include "gameObj.h"
#include "engine.h"
#include <vector>
#include <utility>
#include <cstddef>

using namespace std;

class CharGameObj : public GameObj {
    char ch;

    void computeCells() override {
        occupiedCells.push_back(&(e.getGrid()[r][c]));
    }

  public:
    CharGameObj(size_t r, size_t c, int height, Engine& e, char ch);

    void setChar(char newChar) { ch = newChar; }

    char charAt(size_t row, size_t col) const override { 
        if (row == r && col == c) return ch; 
        else return 0;
    }

    void moveBy(size_t row, size_t col) override;

    



};

#endif