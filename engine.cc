#include "engine.h"
#include "curseView.h"
#include "textView.h"
#include "curseControl.h"
#include <iostream>
#include <memory>

Engine::Engine(size_t r, size_t c): rows{r}, cols{c} {
    for (size_t i=0; i<r; ++i) {
        std::vector<Cell> row;
        for (size_t j=0; j<c; ++j) {
            row.emplace_back(Cell(i, j)); // ??????
        }
        grid.emplace_back(row);
    }

    addView(std::move(std::make_unique<curseView>(r, c, *this)));
    addView(std::move(std::make_unique<textView>(r, c, *this)));
    addController(std::move(std::make_unique<curseControl>()));
}

GameObj& Engine::place(std::unique_ptr<GameObj>& obj) {
    obj->moveBy(0, 0);
    obj->move(); // handle any collisions upon spawning
    objList.push_back(obj); 
    return *obj;
}

GameObj& Engine::spawnChar(size_t row, size_t col, int height, char ch) {
    std::unique_ptr<GameObj> obj = std::make_unique<GameObj>(GameObj(row, col, height, *this, ch));
    return place(obj);
}
GameObj& Engine::spawnRect(size_t row, size_t col, int height, size_t w, size_t l, char ch) {
    std::unique_ptr<GameObj> obj = std::make_unique<GameObj>(GameObj(row, col, height, *this, w, l, ch));
    return place(obj);
}
GameObj& Engine::spawnBmp(size_t row, size_t col, int height, std::map<std::pair<int,int>, char> bitmap) {
    std::unique_ptr<GameObj> obj = std::make_unique<GameObj>(GameObj(row, col, height, *this, bitmap));
    return place(obj);
}


void Engine::play() {
    Action a;
    while(std::cin) {
        renderCells();

        timeout(50);
        a = getAction();
        if ( UP == a ) {
            playerObj->moveBy(-1,0);
        }
        else if ( DOWN == a ) {
            playerObj->moveBy(1,0);
        }
        else if ( RIGHT == a ) {
            playerObj->moveBy(0,1);
        }
        else if ( LEFT == a ) {
            playerObj->moveBy(0,-1);
        }
        else if ( QUIT == a ) break;

        // handle automated 
        // tick(); handle all auto things, not the user input bit
        displayViews();
    }
    
}


void Engine::renderCells() {
    for (int r=0; r<rows; ++r) {
        for (int c=0; c<cols; ++c) {
            updateViews(r, c, grid[r][c].getChar());
        }
    }
}
