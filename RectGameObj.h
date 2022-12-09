#ifndef RECT_GAME_OBJ_H
#define RECT_GAME_OBJ_H

#include <GameObj.h>
#include <cstddef>
#include <map>
#include <utility>

class RectGameObj : public GameObj {
    size_t width, length;
    char ch;

    void computePosns() override {
        posns.reserve(width*length);
        for (int w=0; w<width; ++w) {
            for (int l=0; l<length; ++l) {
                posns.push_back(std::make_pair(l+r, w+c));
            }
        }
    } 

  public:
    RectGameObj(size_t r, size_t c, int height, char ch);
  
    void setChar(char newChar) { c = newChar; }
    void setWidth(size_t w) { width = w; }
    void setLength(size_t l) { length = l; }


};

#endif