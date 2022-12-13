#ifndef __ENGINE_H__
#define __ENGINE_H__
#include "model.h"
#include "gameObj.h"
#include "cell.h"
#include <list>
#include <vector>
#include <utility>

class Mvmt;

class Engine : public Model{
    std::vector<std::vector<Cell>> grid;
    std::list<std::unique_ptr<GameObj>> objList; // list of objects, sorted by HEIGHT
    std::list<std::unique_ptr<GameObj>> objListIgnore; // currently used for dead objs
    // could be expanded for use in despawning once obj is off screen

    GameObj* playerObj;

    void moveObjs();

  public:
    bool playing;
    const size_t rows, cols;
    Engine(size_t r, size_t c);
    ~Engine();
    std::vector<std::vector<Cell>>& getGrid() { return grid; }

    Action getInput() { return getAction(); }
    void setPlayer(GameObj* o) { playerObj = o; }
    // GameObj* getPlayer() { return playerObj; }

    GameObj* spawn(std::unique_ptr<GameObj>& obj);
    GameObj* spawnChar(size_t row, size_t col, int height, char ch);
    GameObj* spawnRect(size_t row, size_t col, int height, size_t w, size_t l, char ch);
    GameObj* spawnBmp(size_t row, size_t col, int height, std::map<std::pair<int,int>, char> bitmap);

    template <typename T> Collider* createCollider(GameObj* obj);

    // template <typename T> Collider* Engine::createCollider(GameObj* obj);    
    Collider* createStopCollider(GameObj* obj);
    Collider* createBounceCollider(GameObj* obj);
    Collider* createDmgCollider(GameObj* obj);
    Collider* createBoundDestroyCollider(GameObj* obj);
    Collider* createGameEndCollider(GameObj* obj, bool win);
    Collider* createBoundEndCollider(GameObj* obj, bool win);
    void resetColliders();

    Mvmt* createAcceleration(GameObj* obj, int ddY, int ddX);


    void ignore(GameObj* obj); // move obj to ignore list

    void tick();
    void renderCells(); // resolve which char each cell should show

    // win or lose message
    void terminate(std::string msg);

    friend class curseView;
};

#endif