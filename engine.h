#ifndef ENGINE_H
#define ENGINE_H
#include "model.h"
#include "gameObj.h"
// #include "CharGameObj.h"
#include "cell.h"
#include <list>
#include <vector>
#include <utility>
#include "ncurses.h"

class Engine : public Model{
    std::vector<std::vector<Cell>> grid;

    //  // list of objects, sorted by HEIGHT
    std::list<std::unique_ptr<GameObj>> objList;

    GameObj* playerObj;

  public:
    const size_t rows, cols;
    Engine(size_t r, size_t c);
    std::vector<std::vector<Cell>>& getGrid() { return grid; }
    void setPlayer(GameObj& o) { playerObj = &o; }
    // GameObj* getPlayer() { return playerObj; }
    // size_t getRows() { return rows; }
    // size_t getCols() { return cols; }

    GameObj& place(std::unique_ptr<GameObj>& obj);
    GameObj& spawnChar(size_t row, size_t col, int height, char ch);
    GameObj& spawnRect(size_t row, size_t col, int height, size_t w, size_t l, char ch);
    GameObj& spawnBmp(size_t row, size_t col, int height, std::map<std::pair<int,int>, char> bitmap);


    void play(); 

    void renderCells(); // resolve which char each cell should show

    friend class curseView;

};

#endif