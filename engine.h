#ifndef __ENGINE_H__
#define __ENGINE_H__
#include "model.h"
#include "gameObj.h"
#include "cell.h"
#include <list>
#include <vector>
#include <utility>

class Engine : public Model{
    std::vector<std::vector<Cell>> grid;
    std::list<std::unique_ptr<GameObj>> objList; // list of objects, sorted by HEIGHT

    GameObj* playerObj;

    void moveObjs();

  public:
    bool playing;
    const size_t rows, cols;
    Engine(size_t r, size_t c);
    std::vector<std::vector<Cell>>& getGrid() { return grid; }

    Action getInput() { return getAction(); }
    void setPlayer(GameObj& o) { playerObj = &o; }
    // GameObj* getPlayer() { return playerObj; }

    GameObj* place(std::unique_ptr<GameObj>& obj);
    GameObj* spawnChar(size_t row, size_t col, int height, char ch);
    GameObj* spawnRect(size_t row, size_t col, int height, size_t w, size_t l, char ch);
    GameObj* spawnBmp(size_t row, size_t col, int height, std::map<std::pair<int,int>, char> bitmap);

    Collider* createStopCollider(GameObj* obj);
    Collider* createBounceCollider(GameObj* obj);
    Collider* createDmgCollider(GameObj* obj);
    Collider* createGameEndCollider(GameObj* obj, bool win);
    void resetColliders();


    void tick();
    // void play(); 

    void renderCells(); // resolve which char each cell should show

    // win or lose message
    void terminate(std::string msg);

    friend class curseView;
};

#endif