#ifndef ENGINE_H
#define ENGINE_H
#include "model.h"
#include "GameObj.h"
#include "cell.h"
#include <list>
#include <vector>
#include <utility>
#include "ncurses.h"

class Engine : public Model{
    size_t rows, cols;
    std::vector<std::vector<Cell>> grid;

    //  // list of objects, sorted by HEIGHT

  public:

    Engine(size_t r, size_t c);

    // void addObj(GameObj &o); // insert obj to grid
    // void rmObj(GameObj &o); // rm obj

    // spawn obj
    // despawn obj

    void render(); // render grid

    friend class curseView;

};

#endif