#include "engine.h"
#include "curseView.h"
#include "textView.h"
#include "curseControl.h"
#include "stopCollide.h"
#include "bounceCollide.h"
#include "dmgCollide.h"
#include "gameEndCollide.h"
#include "boundaryEndCollide.h"
#include "boundaryDestroyCollide.h"
#include "acceleration.h"
#include <iostream>
#include <memory>
#include "ncurses.h"

Engine::Engine(size_t r, size_t c): rows{r}, cols{c} {
    playerObj = nullptr;

    for (size_t i=0; i<r; ++i) {
        std::vector<Cell> row;
        for (size_t j=0; j<c; ++j) {
            row.emplace_back(i, j);
        }
        grid.emplace_back(row);
    }

    addView(std::move(std::make_unique<curseView>(r, c, *this)));
    addView(std::move(std::make_unique<textView>(r, c, *this)));
    addController(std::move(std::make_unique<curseControl>()));

    // halfdelay(5);
}



GameObj* Engine::spawn(std::unique_ptr<GameObj>& obj) {
    obj->moveBy(0, 0);
    obj->move(); // handle any collisions upon spawning
    objList.push_front(std::move(obj)); 
    GameObj* b = (objList.begin())->get();
    return b;
}



GameObj* Engine::spawnChar(size_t row, size_t col, int height, char ch) {
    // std::unique_ptr<GameObj> obj = std::make_unique<GameObj>(GameObj(row, col, height, *this, ch));
    std::unique_ptr<GameObj> obj = std::make_unique<GameObj>(row, col, height, *this, ch);
    return spawn(obj);
}
GameObj* Engine::spawnRect(size_t row, size_t col, int height, size_t w, size_t l, char ch) {
    std::unique_ptr<GameObj> obj = std::make_unique<GameObj>(row, col, height, *this, w, l, ch);
    return spawn(obj);
}
GameObj* Engine::spawnBmp(size_t row, size_t col, int height, std::map<std::pair<int,int>, char> bitmap) {
    std::unique_ptr<GameObj> obj = std::make_unique<GameObj>(row, col, height, *this, bitmap);
    return spawn(obj);
}



template <typename T> Collider* Engine::createCollider(GameObj* obj) {
    std::unique_ptr<Collider> collider = std::make_unique<T>(obj);
    Collider* ptr = collider.get();
    obj->addCollider(std::move(collider));
    return ptr;
} 

// TURN INTO TEMPLATES
Collider* Engine::createStopCollider(GameObj* obj) {
    std::unique_ptr<Collider> collider = std::make_unique<stopCollider>(obj);
    Collider* ptr = collider.get();
    obj->addCollider(std::move(collider));
    return ptr;
}
Collider* Engine::createBounceCollider(GameObj* obj) {
    std::unique_ptr<Collider> collider = std::make_unique<bounceCollider>(obj);
    Collider* ptr = collider.get();
    obj->addCollider(std::move(collider));
    return ptr;
}
Collider* Engine::createDmgCollider(GameObj* obj) {
    std::unique_ptr<Collider> collider = std::make_unique<dmgCollider>(obj);
    Collider* ptr = collider.get();
    obj->addCollider(std::move(collider));
    return ptr;
}
Collider* Engine::createBoundDestroyCollider(GameObj* obj) {
    std::unique_ptr<Collider> collider = std::make_unique<boundDestroyCollider>(obj);
    Collider* ptr = collider.get();
    obj->addCollider(std::move(collider));
    return ptr;
}
Collider* Engine::createGameEndCollider(GameObj* obj, bool win) {
    std::unique_ptr<Collider> collider = std::make_unique<endCollider>(obj, win);
    Collider* ptr = collider.get();
    obj->addCollider(std::move(collider));
    return ptr;
}
Collider* Engine::createBoundEndCollider(GameObj* obj, bool win) {
    std::unique_ptr<Collider> collider = std::make_unique<boundEndCollider>(obj, win);
    Collider* ptr = collider.get();
    obj->addCollider(std::move(collider));
    return ptr;
}

void Engine::resetColliders() {
    for (auto& obj : objList) {
        obj->resetColliders();
    }
}


Mvmt* Engine::createAcceleration(GameObj* obj, int ddY, int ddX) {
    std::unique_ptr<Mvmt> m = std::make_unique<Acceleration>(obj, ddY, ddX);
    Mvmt* ptr = m.get();
    obj->addMvmt(std::move(m));
    return ptr;
}




void Engine::ignore(GameObj* obj) {
    // for (auto it=objList.begin(); it!=objList.end(); ++it) {
    //     if (it->get() == obj) {
    //         objListIgnore.push_back(*it);
    //         objList.erase(it);
    //     }
    // }
}




void Engine::tick() {
    moveObjs(); // handles all motions that aren't related to user input
    if (playerObj) playerObj->moveBy(0,0); // reset player to stationary

    renderCells();
    displayViews();
}



void Engine::moveObjs() {
    for (auto& o : objList) {
        o->move();
    }
    resetColliders();
}


void Engine::renderCells() {
    for (int r=0; r<rows; ++r) {
        for (int c=0; c<cols; ++c) {
            updateViews(r, c, grid[r][c].getChar());
        }
    }
}

void Engine::terminate(std::string msg) {
    playing = false;
    updateViews(0, "                     " + msg);
    updateViews(1, "");
    updateViews(2, "Press any key to exit");
    timeout(-1);
    getch();
}


Engine::~Engine() {
    endwin();
}