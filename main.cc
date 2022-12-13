#include "engine.h"
#include "ncurses.h"


int main(int argc, char* argv[]) {
    initscr();
    noecho();
    curs_set(0);
    refresh();
    Engine e(20, 78);

    std::map<std::pair<int,int>, char> playerBmp {
        {{0,0}, '='}, {{0,1}, '='}, {{0,2}, '='}, {{0,3}, '='}, {{0,4}, '='}, {{0,5}, '='},
        {{1,0}, '='}, {{1,1}, '='}, {{1,2}, '='}, {{1,3}, '='}, {{1,4}, '='}, {{1,5}, '='} };
    GameObj* player = e.spawnBmp(18,32,0,playerBmp);
    e.setPlayer(player);
    Collider* c1 = e.createStopCollider(player);
    player->setPeriod(0); 

    std::map<std::pair<int,int>, char> block {
        {{0,0}, 'X'}, {{0,1}, 'X'}, {{0,2}, 'X'},
        {{1,0}, 'X'}, {{1,1}, 'X'}, {{1,2}, 'X'} };
    

    std::vector<GameObj*> blocks {};

    for (int r=2; r<7; r+=2) {
        for (int c=0; c<35; c+=4) {
            GameObj* b = e.spawnBmp(r,c,0,block);
            Collider* collide = e.createDmgCollider(b); 
            e.createStopCollider(b);
            // collider to destroy whole block
            blocks.push_back(b);
        }
    }
    




}
