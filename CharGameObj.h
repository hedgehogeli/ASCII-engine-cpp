#ifndef CHAR_H
#define CHAR_H

#include "gameObj.h"
#include <vector>
#include <utility>
#include <cstddef>

using namespace std;

class CharGameObj : public GameObj {
    char ch;

    void computePosns() override {
        posns.push_back(make_pair(r,c));
    }
  public:

    CharGameObj(size_t r, size_t c, int height, char ch);

    void setChar(char newChar) { ch = newChar; }

    char charAt(size_t r, size_t c) const override { return ch; }

};

#endif